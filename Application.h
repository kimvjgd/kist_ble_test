
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"
#include "driver/gpio.h"
#include "soc/wdev_reg.h"
#include "xtensa/core-macros.h"

#include "myBLE.h"
#include "Adafruit_MCP9808.h"

void Temper_task(void *pvParameter)
{
  (void)pvParameter;

  Serial.println("Test_task Start");
  // int a = 0;
  Adafruit_MCP9808 temper_sensor = Adafruit_MCP9808();
  temper_sensor.setResolution(3);

  // zmod_setup();
  // GPIO_Init();
  // FAN_ON;

  while (1)
  {

    ////////////////////////////////////////////////////////////////////////
    float randomValue = 20.00 + static_cast<float>(rand() % 100) / 100.0;
  
    // 시리얼 모니터에 출력
    // Serial.print("Random Value: ");
    Serial.println(randomValue, 2);  // 소수점 2자리까지 출력
    ////////////////////////////////////////////////////////////////////////
    temper_sensor.wake();
    // float temper_value = temper_sensor.readTempC();

    String str;
    char data[256];

    // str = "dongpakka : " + String(randomValue);
    str = String(randomValue);
    str.toCharArray(data, str.length() + 1);
    BLE_Send_Msg(data);
    Serial.println(randomValue);

    temper_sensor.shutdown_wake(1);

    vTaskDelay(500 / portTICK_RATE_MS);
  }
}

void freeRTOS_setup()
{
  xTaskCreatePinnedToCore(&Temper_task, "Temper_task", 8192, NULL, 5, NULL, 1);
}