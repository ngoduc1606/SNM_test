
/*
  Application_SNM.h - Arduino library for communicating with OP320A&S SNM
  over RS232/485 (via RTU protocol).


  This version is

  Copyright:: 2022 ngoduc1606@gmail.com
*/

#ifndef _Application_atApp_MB_TCP_SL_
#define _Application_atApp_MB_TCP_SL_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "..\src\services\modbus_slave\atService_MB_TCP_SL.h"
#include "..\src\services\modbus_slave\Modbus_Registers.h"

/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
static TaskHandle_t Task_atApp_MB_TCP_SL;  
void atApp_MB_TCP_SL_Task_Func(void *parameter);
/* _____GLOBAL FUNCTION______________________________________________________ */
/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This Application class is the application to manage the 
 */
class App_MB_TCP : public Application
{
public:
    App_MB_TCP();
 	  ~App_MB_TCP();
  static void  App_MB_Pend();
	static void  App_MB_Start();
	static void  App_MB_Restart();
	static void  App_MB_Execute();
	static void  App_MB_Suspend();
	static void  App_MB_Resume();	  
	static void  App_MB_End();
protected:
private:
} atApp_MB_TCP_SL ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_MB_TCP::App_MB_TCP(/* args */)
{
  	_Pend_User 	     = *App_MB_Pend;
	_Start_User 	 = *App_MB_Start;
	_Restart_User 	 = *App_MB_Restart;
	_Execute_User 	 = *App_MB_Execute;
	_Suspend_User	 = *App_MB_Suspend;
	_Resume_User	 = *App_MB_Resume;
	_End_User	     = *App_MB_End;

	// change the ID of application
	ID_Application = 3;
	// change the application name
	Name_Application = (char*)"Modbus TCP Application";
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_MB_TCP::~App_MB_TCP()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. 
 * In the debug mode, task will send information of application to terminal to start the application.
 */
void  App_MB_TCP::App_MB_Pend()
{
  // atApp_MB_TCP_SL.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_MB_TCP::App_MB_Start()
{
	// init atXYZ Service in the fist running time
	atService_MB_TCP_SL.Run_Service();
 
 
 // Init General Register 
  for( int count = GENERAL_REGISTER_RW_MODBUS_RTU_ID; count <= GENERAL_REGISTER_R_HUMIDITY; count++)
  {
    atService_MB_TCP_SL.addHreg(count,count);
  }
  
 // Init SNM Register
  for( int count = SMM_REGISTER_RW_SHT30_SENSOR_STATE; count <= SNM_REGISTER_R_MIN_ETHANOL; count++)
  {
    atService_MB_TCP_SL.addHreg(count,count);
  }
}  
/**
 * Restart function of SNM  app
 */
void  App_MB_TCP::App_MB_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_MB_TCP::App_MB_Execute()
{	    
	atService_MB_TCP_SL.Run_Service();
	if(atApp_MB_TCP_SL.User_Mode == APP_USER_MODE_DEBUG)
	{
	
	} 

}
void  App_MB_TCP::App_MB_Suspend(){}
void  App_MB_TCP::App_MB_Resume(){}	  
void  App_MB_TCP::App_MB_End(){}
void atApp_MB_TCP_SL_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_MB_TCP_SL.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1/ portTICK_PERIOD_MS);
  }
}
#endif