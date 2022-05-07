
/*
  Application_SNM.h

  This version is

  Copyright:: 2022 ngoduc1606@gmail.com
*/

#ifndef _Application_atApp_MB_TCP_SL_IDM_
#define _Application_atApp_MB_TCP_SL_IDM_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "..\src\services\modbus_slave\atService_MB_TCP_SL.h"
#include "..\src\services\modbus_slave\Modbus_Registers_IDM.h"
#include "..\src\services\modbus_slave\General_MB_Register.h"

/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
static TaskHandle_t Task_atApp_MB_TCP_IDM;  
void atApp_MB_TCP_IDM_Task_Func(void *parameter);
/* _____GLOBAL FUNCTION______________________________________________________ */
/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This Application class is the application to manage the 
 */
class App_MB_TCP_IDM : public Application
{
public:
    App_MB_TCP_IDM();
 	  ~App_MB_TCP_IDM();
  static void  App_MB_TCP_IDM_Pend();
	static void  App_MB_TCP_IDM_Start();
	static void  App_MB_TCP_IDM_Restart();
	static void  App_MB_TCP_IDM_Execute();
	static void  App_MB_TCP_IDM_Suspend();
	static void  App_MB_TCP_IDM_Resume();	  
	static void  App_MB_TCP_IDM_End();
protected:
private:
} atApp_MB_TCP_IDM ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_MB_TCP_IDM::App_MB_TCP_IDM(/* args */)
{
  	_Pend_User 	     = *App_MB_TCP_IDM_Pend;
	_Start_User 	 = *App_MB_TCP_IDM_Start;
	_Restart_User 	 = *App_MB_TCP_IDM_Restart;
	_Execute_User 	 = *App_MB_TCP_IDM_Execute;
	_Suspend_User	 = *App_MB_TCP_IDM_Suspend;
	_Resume_User	 = *App_MB_TCP_IDM_Resume;
	_End_User	     = *App_MB_TCP_IDM_End;

	// change the ID of application
	ID_Application = 3;
	// change the application name
	Name_Application = (char*)"Modbus TCP Application";
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_MB_TCP_IDM::~App_MB_TCP_IDM()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. 
 * In the debug mode, task will send information of application to terminal to start the application.
 */
void  App_MB_TCP_IDM::App_MB_TCP_IDM_Pend()
{
  // atApp_MB_TCP_SL_IDM.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_MB_TCP_IDM::App_MB_TCP_IDM_Start()
{
	// init atXYZ Service in the fist running time
	atService_MB_TCP_SL.Run_Service();
 
 // Init General Register 
  for( int count = GENERAL_REGISTER_RW_MODBUS_RTU_ID; count <= GENERAL_REGISTER_R_MODBUS_TCP_IP_PORT; count++)
  {
    atService_MB_TCP_SL.addHreg(count,count);
  }
   atService_MB_TCP_SL.addHreg(GENERAL_REGISTER_R_DEVICE_TYPE,5);
   atService_MB_TCP_SL.addHreg(GENERAL_REGISTER_RW_DEVICE_ID,0);
 // Init SNM Register
  for( int count = IDM_REGISTER_RW_INVERTER_TYPE; count <= IDM_REGISTER_RW_SET_FREQUENCY; count++)
  {
    atService_MB_TCP_SL.addHreg(count,count);
  }

  for( int count = IDM_REGISTER_R_OPERATION_FREQUENCY; count <= IDM_REGISTER_R_FAULT_CODE; count++)
  {
    atService_MB_TCP_SL.addIreg(count,count);
  }
}  
/**
 * Restart function of SNM  app
 */
void  App_MB_TCP_IDM::App_MB_TCP_IDM_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_MB_TCP_IDM::App_MB_TCP_IDM_Execute()
{	    
	atService_MB_TCP_SL.Run_Service();
}
void  App_MB_TCP_IDM::App_MB_TCP_IDM_Suspend(){}
void  App_MB_TCP_IDM::App_MB_TCP_IDM_Resume(){}	  
void  App_MB_TCP_IDM::App_MB_TCP_IDM_End(){}
void atApp_MB_TCP_IDM_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_MB_TCP_IDM.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1/ portTICK_PERIOD_MS);
  }
}
#endif