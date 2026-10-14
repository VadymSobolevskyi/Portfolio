/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.ino                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vadym Sobolevskyi                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:34:58 by vs                 #+#    #+#            */
/*   Updated: 2026/09/24 15:35:03 by vs                 ###   #########       */
/*                                                                            */
/* ************************************************************************** */

/* FreeRTOS. Device. - ESP32 */

/*
Time to assemble everything. This capstone builds a complete multi-task "smart sensor device" on the ESP32 in Wokwi: a sensor task samples at a fixed rate and streams readings through a queue to a processing task that checks them against a threshold; a button ISR arms/disarms the alarm via a task notification; a software timer drives the status LED; and a serial command task edits a shared configuration protected by a mutex. Every module of this level appears here doing the exact job it was designed for — plus a wiring list, a test plan, and extensions to make it your own.

                     ┌───────────────┐ Reading ┌────────────────┐
  potentiometer ───► │ sensorTask │──── queue ──►│ processTask │──► alarm LED
  (GPIO 34) │ 5 Hz, DelayUntil│ (8 deep) │ threshold check│
                     └───────────────┘ └───────┬────────┘
                                                            │ reads config
  button (GPIO 27) ──ISR──notification──► armTask │ (mutex)
                          toggles cfg.armed (mutex) │
                                                            │
  serial "set/get/stats" ──► commandTask ──── writes config (mutex)

  statusTimer (auto-reload) ──► heartbeat LED: slow=disarmed, fast=armed
*/

// Smart Sensor Device — Level 1 capstone (ESP32 Arduino with FreeRTOS)

Code:

const uint8_t SENSOR_PIN = 34;
const uint8_t BUTTON_PIN = 27;
const uint8_t ALARM_LED  = 25;
const uint8_t STATUS_LED = 26;

// ---------- shared configuration (mutex-guarded) ----------
struct Config {
  bool     armed;        // alarm enabled?
  int      threshold;    // raw ADC alarm level (0..4095)
  uint32_t periodMs;     // sensor sampling period
};
Config config = { true, 3000, 200 };
SemaphoreHandle_t configMutex;

Config getConfig() {                       // snapshot helper: lock briefly
  xSemaphoreTake(configMutex, portMAX_DELAY);
  Config c = config;
  xSemaphoreGive(configMutex);
  return c;
}

// ---------- reading pipeline ----------
struct Reading { uint32_t ms; int raw; };
QueueHandle_t readingQueue;
volatile uint32_t droppedReadings = 0;     // stats only

// ---------- button → arm/disarm ----------
TaskHandle_t armTaskHandle;

void IRAM_ATTR buttonISR() {
  BaseType_t woken = pdFALSE;
  vTaskNotifyGiveFromISR(
  portYIELD_FROM_ISR(woken);
}

void armTask(void *pv) {
  for (;;) {
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);         // wait for a press
    xSemaphoreTake(configMutex, portMAX_DELAY);
    config.armed = !config.armed;
    bool nowArmed = config.armed;
    xSemaphoreGive(configMutex);
    Serial.printf("[%lu] button: system %s\n", millis(),
                  nowArmed ? "ARMED" : "DISARMED");
    vTaskDelay(pdMS_TO_TICKS(250))
    ulTaskNotifyTake(pdTRUE, 0);                     // drain bounces
  }
}

// ---------- status LED timer ----------
TimerHandle_t statusTimer;

void statusCallback(TimerHandle_t t) {
  digitalWrite(STATUS_LED, !digitalRead(STATUS_LED));
}

// ---------- tasks ----------
void sensorTask(void *pv) {                          // priority 3
  TickType_t lastWake = xTaskGetTickCount();
  for (;;) {
    uint32_t period = getConfig().periodMs;
    vTaskDelayUntil(&lastWake, pdMS_TO_TICKS(period));
    Reading r = { millis(), analogRead(SENSOR_PIN) };
    if (xQueueSend(readingQueue, &r, 0) != pdPASS) {
      droppedReadings++;                             // never block the sampler
    }
  }
}

void processTask(void *pv) {                         // priority 2
  Reading r;
  bool alarmLatched = false;
  for (;;) {
    xQueueReceive(readingQueue, &r, portMAX_DELAY);
    Config c = getConfig();
    bool over = (r.raw >= c.threshold);
    bool alarm = c.armed && over;
    if (alarm != alarmLatched) {                     // log transitions only
      alarmLatched = alarm;
      digitalWrite(ALARM_LED, alarm ? HIGH : LOW);
      Serial.printf("[%lu] ALARM %s (raw=%d thr=%d)\n",
                    r.ms, alarm ? "ON" : "off", r.raw, c.threshold);
      // armed + alarming → fast heartbeat, else slow
      xTimerChangePeriod(
                         pdMS_TO_TICKS(alarm ? 100 : 700), 0);
    }
  }
}

void commandTask(void *pv) {                         // priority 1
  String line;
  for (;;) {
    while (Serial.available()) {
      char ch = (char)Serial.read();
      if (ch == '\n') {
        line.trim();
        if (line == "get") {
          Config c = getConfig();
          Serial.printf("armed=%d threshold=%d period=%lu\n",
                        c.armed, c.threshold, (unsigned long)c.periodMs);
        } else if (line.startsWith("set thr ")) {
          int v = line.substring(8).toInt();
          xSemaphoreTake(configMutex, portMAX_DELAY);
          config.threshold = constrain(v, 0, 4095);
          xSemaphoreGive(configMutex);
          Serial.printf("ok threshold=%d\n", v);
        } else if (line.startsWith("set period ")) {
          int v = line.substring(11).toInt();
          xSemaphoreTake(configMutex, portMAX_DELAY);
          config.periodMs = max(50, v);
          xSemaphoreGive(configMutex);
          Serial.printf("ok period=%d\n", v);
        } else if (line == "stats") {
          Serial.printf("queued=%u dropped=%lu heap=%u minheap=%u stack=%u\n",
                        uxQueueMessagesWaiting(
                        (unsigned long)droppedReadings,
                        ESP.getFreeHeap(), ESP.getMinFreeHeap(),
                        uxTaskGetStackHighWaterMark(
        } else if (line.length()) {
          Serial.println("cmds: get | set thr N | set period N | stats");
        }
        line = "";
      } else {
        line += ch;
      }
    }
    vTaskDelay(pdMS_TO_TICKS(20));                   // human-speed polling
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ALARM_LED, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // kernel objects FIRST (Module 4's lesson)
  configMutex  = xSemaphoreCreateMutex();
  readingQueue = xQueueCreate(8, sizeof(Reading));
  statusTimer  = xTimerCreate("status", pdMS_TO_TICKS(700), pdTRUE,
                              NULL, statusCallback);
  if (!configMutex || !readingQueue || !statusTimer) {
    Serial.println("FATAL: object creation failed"); for (;;);
  }

  xTaskCreate(armTask,     "arm",     2048, NULL, 1, &armTaskHandle);
  xTaskCreate(sensorTask,  "sensor",  2048, NULL, 3, NULL);
  xTaskCreate(processTask, "process", 3072, NULL, 2, NULL);
  xTaskCreate(commandTask, "command", 4096, NULL, 1, NULL);

  attachInterrupt(
  xTimerStart(statusTimer, 0);
  Serial.println("smart sensor up — try: get | set thr N | set period N | stats");
}

void loop() { vTaskDelay(portMAX_DELAY); }

