/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ques.ino                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vadym Sobolevskyi                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:34:58 by vs                 #+#    #+#            */
/*   Updated: 2026/09/24 15:35:03 by vs                 ###   #########       */
/*                                                                            */
/* ************************************************************************** */

/* FreeRTOS.Ques. Producer/consumer: the fundamental RTOS pattern. - ESP32 */

struct Reading {
  uint32_t ms; // when it was taken
  int raw; // ADC value
};

QueueHandle_t readingQueue;

void producerTask(void *pv) { // fast, dumb, regular
  TickType_t lastWake = xTaskGetTickCount();
  for (;;) {
    vTaskDelayUntil(&lastWake, pdMS_TO_TICKS(200)); // exactly 5 Hz
    Reading r = { millis(), analogRead(34) };
    if (xQueueSend(readingQueue, &r, 0) != pdPASS) {
      Serial.println("queue full — dropped a reading");
    }
  }
}

void consumerTask(void *pv) { // slow, smart, event-driven
  Reading r;
  for (;;) {
    xQueueReceive(readingQueue, &r, portMAX_DELAY); // sleeps until data
    float volts = r.raw * 3.3f / 4095.0f;
    Serial.printf("[%lu ms] %.2f V\n", r.ms, volts);
    vTaskDelay(pdMS_TO_TICKS(350)); // simulate slow processing
  }
}

void setup() {
  Serial.begin(115200);
  readingQueue = xQueueCreate(8, sizeof(Reading)); // create BEFORE tasks
  if (readingQueue == NULL) { Serial.println("queue alloc failed"); for(;;); }
  xTaskCreate(producerTask, "prod", 2048, NULL, 2, NULL);
  xTaskCreate(consumerTask, "cons", 4096, NULL, 1, NULL);
}

void loop() { vTaskDelay(portMAX_DELAY); }
