/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vadym Sobolevskyi                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:34:58 by vs                 #+#    #+#            */
/*   Updated: 2026/09/24 15:35:03 by vs                 ###   #########       */
/*                                                                            */
/* ************************************************************************** */

/* FreeRTOS. Mutexes. - ESP32 */

struct Config { float threshold; uint32_t periodMs; };
Config config = {2.5f, 1000};
SemaphoreHandle_t configMutex;

void writerTask(void *pv) {
  for (;;) {
    vTaskDelay(pdMS_TO_TICKS(3000));
    xSemaphoreTake(configMutex, portMAX_DELAY);   // ---- critical section ----
    config.threshold += 0.1f;                     // both fields updated
    config.periodMs  += 50;                       // together, atomically
    xSemaphoreGive(configMutex);                  // --------------------------
  }
}

void readerTask(void *pv) {
  for (;;) {
    vTaskDelay(pdMS_TO_TICKS(700));
    xSemaphoreTake(configMutex, portMAX_DELAY);
    Config snapshot = config;                     // consistent copy
    xSemaphoreGive(configMutex);
    Serial.printf("threshold=%.1f period=%lu\n",
                  snapshot.threshold, snapshot.periodMs);
  }
}

void setup() {
  Serial.begin(115200);
  configMutex = xSemaphoreCreateMutex();          // starts AVAILABLE
  xTaskCreate(writerTask, "writer", 2048, NULL, 1, NULL);
  xTaskCreate(readerTask, "reader", 2048, NULL, 2, NULL);
}

void loop() { vTaskDelay(portMAX_DELAY); }
