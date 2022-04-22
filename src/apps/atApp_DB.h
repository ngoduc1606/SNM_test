/**
@file
*/
/*
  Library use EEPROM.h for save data to eeprom 
  This version is 
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_DB_
#define _Application_atApp_DB_
/* _____PROJECT INCLUDES____________________________________________________ */
#include <EEPROM.h>
#include "App.h"
#include "..\src\services\modbus_slave\Modbus_Registers.h"
/* _____DEFINETIONS__________________________________________________________ */
#define EEPROM_SIZE                     25

#define EEPROM_FIRST_BOOT               0
#define EEPROM_TEMPERATURE_REAL_TIME    1
#define EEPROM_MAX_TEMPERATURE          2
#define EEPROM_MIN_TEMPERATURE          3
#define EEPROM_MEAN_TEMPERATURE         4
#define EEPROM_HUMIDITY_REAL_TIME       5
#define EEPROM_MAX_HUMIDITY             6
#define EEPROM_MIN_HUMIDITY             7
#define EEPROM_MEAN_HUMIDITY            8
#define EEPROM_TVOC_REAL_TIME           9
#define EEPROM_MAX_TVOC                 10
#define EEPROM_MIN_TVOC                 11
#define EEPROM_MEAN_TVOC                12

#define EEPROM_CO2_REAL_TIME            13
#define EEPROM_MAX_CO2                  14
#define EEPROM_MIN_CO2                  15
#define EEPROM_MEAN_CO2                 16

#define EEPROM_H2_REAL_TIME             17
#define EEPROM_MAX_H2                   18
#define EEPROM_MIN_H2                   19
#define EEPROM_MEAN_H2                  20

#define EEPROM_ETHANOL_REAL_TIME        21
#define EEPROM_MAX_ETHANOL              22
#define EEPROM_MIN_ETHANOL              23
#define EEPROM_MEAN_ETHANOL             24







/* _____GLOBAL VARIABLES_____________________________________________________ */

///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */
TaskHandle_t Task_atApp_DB;  
void atApp_DB_Task_Func(void *parameter);
/* _____CLASS DEFINITION_____________________________________________________ */

/**
 * This application class is the application to manage the 
 */
class App_DB : public Application
{
public:
  	App_DB();
 	~App_DB();
  	static void  App_DB_Pend();
	static void  App_DB_Start();
	static void  App_DB_Restart();
	static void  App_DB_Execute();
	static void  App_DB_Suspend();
	static void  App_DB_Resume();	  
	static void  App_DB_End();	

    uint16_t Temperature_Real_Time      = 0;
    uint16_t Temperature_Mean           = 0;
    uint16_t Temperature_Max            = 0;
    uint16_t Temperature_Min            = 0;
    uint16_t Humidity_Real_Time         = 0;
    uint16_t Humidity_Mean              = 0;
    uint16_t Humidity_Max               = 0;
    uint16_t Humidity_Min               = 0;
    uint16_t TVOC_Real_Time             = 0;
    uint16_t TVOC_Mean                  = 0;
    uint16_t TVOC_Max                   = 0;
    uint16_t TVOC_Min                   = 0;
    uint16_t H2_Real_Time               = 0;
    uint16_t H2_Mean                    = 0;
    uint16_t H2_Max                     = 0;
    uint16_t H2_Min                     = 0;
    uint16_t CO2_Real_Time              = 0;
    uint16_t CO2_Mean                   = 0;
    uint16_t CO2_Max                    = 0;
    uint16_t CO2_Min                    = 0;
    uint16_t Ethanol_Real_Time          = 0;
    uint16_t Ethanol_Mean               = 0;
    uint16_t Ethanol_Max                = 0;
    uint16_t Ethanol_Min                = 0;
protected:
    uint8_t  First_Boot             = 0;
private:
} atApp_DB ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_DB::App_DB(/* args */)
{
  	_Pend_User 	     = *App_DB_Pend;
	_Start_User 	 = *App_DB_Start;
	_Restart_User 	 = *App_DB_Restart;
	_Execute_User 	 = *App_DB_Execute;
	_Suspend_User	 = *App_DB_Suspend;
	_Resume_User	 = *App_DB_Resume;
	_End_User	     = *App_DB_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"DB Application";
	// change the ID of SNM

}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_DB::~App_DB()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition.
 *  In the debug mode, task will send information of application to terminal to start the application.
 */
void  App_DB::App_DB_Pend()
{
    // atService_DB7758.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_DB::App_DB_Start()
{
	// init atXYZ Service in the fist running time
    // init the eeprom
    if (!EEPROM.begin(EEPROM_SIZE))
    {
        Serial.println("        [Error] - failed to initialise EEPROM\n"); 
    }
    // in the first boot flash the eeprom
    if (EEPROM.read(EEPROM_FIRST_BOOT) !=1)
    {
        for(uint8_t i = 0; i < EEPROM_SIZE; i++)
        {
            if(i == 1) EEPROM.write(i,1);
            else    EEPROM.write(i,0);
        }
        EEPROM.commit();
    }
// read the data from eeprom when power up
    atApp_DB.First_Boot            = EEPROM.read(EEPROM_FIRST_BOOT);
    atApp_DB.Temperature_Real_Time = (uint16_t)EEPROM.readShort(EEPROM_TEMPERATURE_REAL_TIME);
    atApp_DB.Temperature_Mean      = (uint16_t)EEPROM.readShort(EEPROM_MEAN_TEMPERATURE     );
    atApp_DB.Temperature_Max       = (uint16_t)EEPROM.readShort(EEPROM_MAX_TEMPERATURE      );
    atApp_DB.Temperature_Min       = (uint16_t)EEPROM.readShort(EEPROM_MIN_TEMPERATURE      );
    atApp_DB.Humidity_Real_Time    = (uint16_t)EEPROM.readShort(EEPROM_HUMIDITY_REAL_TIME   );
    atApp_DB.Humidity_Mean         = (uint16_t)EEPROM.readShort(EEPROM_MEAN_HUMIDITY        );
    atApp_DB.Humidity_Max          = (uint16_t)EEPROM.readShort(EEPROM_MAX_HUMIDITY         );
    atApp_DB.Humidity_Min          = (uint16_t)EEPROM.readShort(EEPROM_MIN_HUMIDITY         );
    atApp_DB.TVOC_Real_Time        = (uint16_t)EEPROM.readShort(EEPROM_TVOC_REAL_TIME       );
    atApp_DB.TVOC_Mean             = (uint16_t)EEPROM.readShort(EEPROM_MEAN_TVOC            );
    atApp_DB.TVOC_Max              = (uint16_t)EEPROM.readShort(EEPROM_MAX_TVOC             );
    atApp_DB.TVOC_Min              = (uint16_t)EEPROM.readShort(EEPROM_MIN_TVOC             );
    atApp_DB.H2_Real_Time          = (uint16_t)EEPROM.readShort(EEPROM_CO2_REAL_TIME        );
    atApp_DB.H2_Mean               = (uint16_t)EEPROM.readShort(EEPROM_MEAN_CO2             );
    atApp_DB.H2_Max                = (uint16_t)EEPROM.readShort(EEPROM_MAX_CO2              );
    atApp_DB.H2_Min                = (uint16_t)EEPROM.readShort(EEPROM_MIN_CO2              );
    atApp_DB.CO2_Real_Time         = (uint16_t)EEPROM.readShort(EEPROM_H2_REAL_TIME         );
    atApp_DB.CO2_Mean              = (uint16_t)EEPROM.readShort(EEPROM_MEAN_H2              );
    atApp_DB.CO2_Max               = (uint16_t)EEPROM.readShort(EEPROM_MAX_H2               );
    atApp_DB.CO2_Min               = (uint16_t)EEPROM.readShort(EEPROM_MIN_H2               );
    atApp_DB.Ethanol_Real_Time     = (uint16_t)EEPROM.readShort(EEPROM_ETHANOL_REAL_TIME    );
    atApp_DB.Ethanol_Mean          = (uint16_t)EEPROM.readShort(EEPROM_MEAN_ETHANOL         );
    atApp_DB.Ethanol_Max           = (uint16_t)EEPROM.readShort(EEPROM_MAX_ETHANOL          );
    atApp_DB.Ethanol_Min           = (uint16_t)EEPROM.readShort(EEPROM_MIN_ETHANOL          );

}  
/**
 * Restart function of SNM  app
 */
void  App_DB::App_DB_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_DB::App_DB_Execute()
{	
	//if value is change, commit value to eeprom 
    if (atApp_DB.Temperature_Max != EEPROM.read(EEPROM_MAX_TEMPERATURE))
    {
        EEPROM.write(EEPROM_MAX_TEMPERATURE, atApp_DB.Temperature_Max);
        EEPROM.commit();
    }
    if (atApp_DB.Temperature_Min != EEPROM.read(EEPROM_MIN_TEMPERATURE))
    {
        EEPROM.write(EEPROM_MIN_TEMPERATURE, atApp_DB.Temperature_Min);
        EEPROM.commit();
    }
    if (atApp_DB.Temperature_Mean != EEPROM.read(EEPROM_MEAN_TEMPERATURE))
    {
        EEPROM.write(EEPROM_MEAN_TEMPERATURE, atApp_DB.Temperature_Mean);
        EEPROM.commit();
    }
    if (atApp_DB.Humidity_Max != EEPROM.read(EEPROM_MAX_HUMIDITY))
    {
        EEPROM.write(EEPROM_MAX_HUMIDITY, atApp_DB.Humidity_Max);
        EEPROM.commit();
    }
    if (atApp_DB.Humidity_Min != EEPROM.read(EEPROM_MIN_HUMIDITY))
    {
        EEPROM.write(EEPROM_MIN_HUMIDITY, atApp_DB.Humidity_Min);
        EEPROM.commit();
    }
    if (atApp_DB.Humidity_Mean != EEPROM.read(EEPROM_MEAN_HUMIDITY))
    {
        EEPROM.write(EEPROM_MEAN_HUMIDITY, atApp_DB.Humidity_Mean);
        EEPROM.commit();
    }
    if (atApp_DB.TVOC_Max != EEPROM.read(EEPROM_MAX_TVOC))
    {
        EEPROM.write(EEPROM_MAX_TVOC, atApp_DB.TVOC_Max);
        EEPROM.commit();
    }
    if (atApp_DB.TVOC_Min != EEPROM.read(EEPROM_MIN_TVOC))
    {
        EEPROM.write(EEPROM_MIN_TVOC, atApp_DB.TVOC_Min);
        EEPROM.commit();
    }
    if (atApp_DB.TVOC_Mean != EEPROM.read(EEPROM_MEAN_TVOC))
    {
        EEPROM.write(EEPROM_MEAN_TVOC, atApp_DB.TVOC_Mean);
        EEPROM.commit();
    }
    if (atApp_DB.H2_Max != EEPROM.read(EEPROM_MAX_H2))
    {
        EEPROM.write(EEPROM_MAX_H2, atApp_DB.H2_Max);
        EEPROM.commit();
    }
    if (atApp_DB.H2_Min != EEPROM.read(EEPROM_MIN_H2))
    {
        EEPROM.write(EEPROM_MIN_H2, atApp_DB.H2_Min);
        EEPROM.commit();
    }
    if (atApp_DB.H2_Mean != EEPROM.read(EEPROM_MEAN_H2))
    {
        EEPROM.write(EEPROM_MEAN_H2, atApp_DB.H2_Mean);
        EEPROM.commit();
    }
    if (atApp_DB.CO2_Max != EEPROM.read(EEPROM_MAX_CO2))
    {
        EEPROM.write(EEPROM_MAX_CO2, atApp_DB.CO2_Max);
        EEPROM.commit();
    }
    if (atApp_DB.CO2_Min != EEPROM.read(EEPROM_MIN_CO2))
    {
        EEPROM.write(EEPROM_MIN_CO2, atApp_DB.CO2_Min);
        EEPROM.commit();
    }
    if (atApp_DB.CO2_Mean != EEPROM.read(EEPROM_MEAN_CO2))
    {
        EEPROM.write(EEPROM_MEAN_CO2, atApp_DB.CO2_Mean);
        EEPROM.commit();
    }
    if (atApp_DB.Ethanol_Max != EEPROM.read(EEPROM_MAX_ETHANOL))
    {
        EEPROM.write(EEPROM_MAX_ETHANOL, atApp_DB.Ethanol_Max);
        EEPROM.commit();
    }
    if (atApp_DB.Ethanol_Min != EEPROM.read(EEPROM_MIN_ETHANOL))
    {
        EEPROM.write(EEPROM_MIN_ETHANOL, atApp_DB.Ethanol_Min);
        EEPROM.commit();
    }
    if (atApp_DB.Ethanol_Mean != EEPROM.read(EEPROM_MEAN_ETHANOL))
    {
        EEPROM.write(EEPROM_MEAN_ETHANOL, atApp_DB.Ethanol_Mean);
        EEPROM.commit();
    }



    if(atApp_DB.User_Mode == APP_USER_MODE_DEBUG)
    {
		
    }   
}
void  App_DB::App_DB_Suspend(){}
void  App_DB::App_DB_Resume(){}	  
void  App_DB::App_DB_End(){}

void atApp_DB_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_DB.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

#endif