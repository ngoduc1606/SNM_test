#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "../src/apps/App_atABC.h"

TaskHandle_t Task_ABC;  
void atABC_Application(void *parameter)
{
  while (1)
  {
    atABC.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1/ portTICK_PERIOD_MS);
  }
}

void setup() {
  // put your setup code here, to run once:
  {                           // create a task to run ABC application            
    xTaskCreatePinnedToCore(
      atABC_Application,      // task function
      "ABC_Application",      // name task
      50000,                  // stack size of task
      NULL,   
      1,                      // priority
      &Task_ABC,              // Task handle
      1                       // on core 1
    );
  };
}

void loop() {
  // put your main code here, to run repeatedly:
}