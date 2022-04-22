/**
@file

*/
/*
  Application example t

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_SNM_
#define _Application_atApp_SNM_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "..\App.h"
#include "..\src\services\modbus_master\atService_MB_TCP_MA.h"
#include "..\src\obj\atObj_SNMs_Data.h"
#include "..\src\services\modbus_register\SNM_MB_Register.h"
/* _____DEFINETIONS__________________________________________________________ */
enum status_connect
{
  disconnect,
  connect
};
/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_SNM;  
void atApp_SNM_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */

/**
 * This Application class is the application to manage the 
 */
class App_SNM : public Application
{
public:
  	App_SNM();
 	~App_SNM();
  	static void  App_SNM_Pend();
	static void  App_SNM_Start();
	static void  App_SNM_Restart();
	static void  App_SNM_Execute();
	static void  App_SNM_Suspend();
	static void  App_SNM_Resume();	  
	static void  App_SNM_End();
  bool status_connect;

protected:
private:
} atApp_SNM ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_SNM::App_SNM(/* args */)
{
  	_Pend_User 	     = *App_SNM_Pend;
	_Start_User 	 = *App_SNM_Start;
	_Restart_User 	 = *App_SNM_Restart;
	_Execute_User 	 = *App_SNM_Execute;
	_Suspend_User	 = *App_SNM_Suspend;
	_Resume_User	 = *App_SNM_Resume;
	_End_User	     = *App_SNM_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"SNM Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_SNM::~App_SNM()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_SNM::App_SNM_Pend()
{
    atService_MB_TCP_MA.Run_Service();
}
/**
 * This start function will init some critical function 
 */
void  App_SNM::App_SNM_Start()
{
	// init atXYZ Service in the fist running time
	
}  
/**
 * Restart function of SNM  app
 */
void  App_SNM::App_SNM_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_SNM::App_SNM_Execute()
{	
    for( uint8_t count = 1; count <= atObject_SNMs_Data.SNM_number; count++)
    {	
      mb_TCP.readHreg(atObject_SNMs_Data.SNM[count].IP, SNM_REGISTER_R_TEMPERATURE_REAL_TIME,
                                                    &atObject_SNMs_Data.SNM[count].Temperature);
      mb_TCP.readHreg(atObject_SNMs_Data.SNM[count].IP, SNM_REGISTER_R_HUMIDITY_REAL_TIME,
                                                    &atObject_SNMs_Data.SNM[count].Humidity);
      mb_TCP.readHreg(atObject_SNMs_Data.SNM[count].IP, SNM_REGISTER_R_CO2_REAL_TIME,
                                                    &atObject_SNMs_Data.SNM[count].CO2);
      mb_TCP.readHreg(atObject_SNMs_Data.SNM[count].IP, SNM_REGISTER_R_H2_REAL_TIME,
                                                    &atObject_SNMs_Data.SNM[count].H2);
      mb_TCP.readHreg(atObject_SNMs_Data.SNM[count].IP, SNM_REGISTER_R_TVOC_REAL_TIME,
                                                    &atObject_SNMs_Data.SNM[count].TVOC);  
      mb_TCP.readHreg(atObject_SNMs_Data.SNM[count].IP, SNM_REGISTER_R_ETHANOL_REAL_TIME,
                                                    &atObject_SNMs_Data.SNM[count].Ethanol);     

      atApp_SNM.status_connect = mb_TCP.isConnected(atObject_SNMs_Data.SNM[count].IP);
      if( atApp_SNM.status_connect == disconnect)
      {
        atObject_SNMs_Data.SNM[count].Status_of_SNMs = 0;
        atObject_SNMs_Data.SNM[count].Temperature = 0;
        atObject_SNMs_Data.SNM[count].Humidity = 0;
        atObject_SNMs_Data.SNM[count].CO2 = 0;
        atObject_SNMs_Data.SNM[count].H2 = 0;
        atObject_SNMs_Data.SNM[count].TVOC = 0;
        atObject_SNMs_Data.SNM[count].Ethanol = 0;
      }                                                                                                                        
    }  
}
void  App_SNM::App_SNM_Suspend(){}
void  App_SNM::App_SNM_Resume(){}	  
void  App_SNM::App_SNM_End(){}
void atApp_SNM_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_SNM.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}
#endif