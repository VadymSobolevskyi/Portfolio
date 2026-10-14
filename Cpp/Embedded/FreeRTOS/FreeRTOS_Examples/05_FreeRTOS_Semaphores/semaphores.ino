/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vadym Sobolevskyi                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:34:58 by vs                 #+#    #+#            */
/*   Updated: 2026/09/24 15:35:03 by vs                 ###   #########       */
/*                                                                            */
/* ************************************************************************** */

/* FreeRTOS.Semaphores. - ESP32 */

SemaphoreHandle_t startSignal;

void workerTask(void *pv) {
  for (;;) {
    // Sleeps (0% CPU) until someone gives the semaphore:
    if (xSemaphoreTake(startSignal, portMAX_DELAY) == pdTRUE) {
      Serial.printf("[%lu ms] worker: triggered!\n", millis());
    }
  }
}

void triggerTask(void *pv) {
  for (;;) {
    vTaskDelay(pdMS_TO_TICKS(1500));
    Serial.printf("[%lu ms] trigger: firing worker\n", millis());
    xSemaphoreGive(startSignal);
  }
}

void setup() {
  Serial.begin(115200);
  startSignal = xSemaphoreCreateBinary(); // starts EMPTY (must be given first)
  xTaskCreate(workerTask, "worker", 2048, NULL, 2, NULL);
  xTaskCreate(triggerTask, "trigger", 2048, NULL, 1, NULL);
}

void loop() { vTaskDelay(portMAX_DELAY); }
