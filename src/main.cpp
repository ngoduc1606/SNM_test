#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "../src/apps/atApp_ABC.h"

TaskHandle_t Task_ABC;  
void atApp_ABC_Application(void *parameter)
{
  while (1)
  {
    atApp_ABC.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

void setup() {
  // put your setup code here, to run once:

  atApp_ABC.Debug();
  {                           // create a task to run ABC application            
    xTaskCreatePinnedToCore(
      atApp_ABC_Application,      // task function
      "atApp_ABC_Application",      // name task
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