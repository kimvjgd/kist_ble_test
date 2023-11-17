#include "Application.h"

// int WEARABLE_DEVICE_NUM = 11;

void setup()
{
  Serial.begin(115200);
  delay(100);
  // GPIO_INIT();
  pinMode(0, INPUT_PULLUP);

  Serial.println("Ble test board System Start");
  initBLE();

  freeRTOS_setup();
}

void loop()
{
  // Serial.println("hihi");
  // delay(1000);
}