/**
@file

*/
/*
  Application

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_MB_TCP_CL_
#define _Application_atApp_MB_TCP_CL_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/modbus_master/atService_MB_TCP_CL.h"
/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_MB_TCP_CL;  
void atApp_MB_TCP_CL_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */

/**
 * This Application class is the application to manage the 
 */
class App_MB_TCP_CL : public Application
{
public:
  	App_MB_TCP_CL();
 	~App_MB_TCP_CL();
  	static void  App_MB_TCP_CL_Pend();
	static void  App_MB_TCP_CL_Start();
	static void  App_MB_TCP_CL_Restart();
	static void  App_MB_TCP_CL_Execute();
	static void  App_MB_TCP_CL_Suspend();
	static void  App_MB_TCP_CL_Resume();	  
	static void  App_MB_TCP_CL_End();
protected:
private:
} atApp_MB_TCP_CL ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_MB_TCP_CL::App_MB_TCP_CL(/* args */)
{
  	_Pend_User 	     = *App_MB_TCP_CL_Pend;
	_Start_User 	 = *App_MB_TCP_CL_Start;
	_Restart_User 	 = *App_MB_TCP_CL_Restart;
	_Execute_User 	 = *App_MB_TCP_CL_Execute;
	_Suspend_User	 = *App_MB_TCP_CL_Suspend;
	_Resume_User	 = *App_MB_TCP_CL_Resume;
	_End_User	     = *App_MB_TCP_CL_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"MB_TCP_CL Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_MB_TCP_CL::~App_MB_TCP_CL()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_MB_TCP_CL::App_MB_TCP_CL_Pend()
{
    atService_MB_TCP_CL.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_MB_TCP_CL::App_MB_TCP_CL_Start()
{
	// init atXYZ Service in the fist running time
	atService_MB_TCP_CL.Run_Service();
}  
/**
 * Restart function of SNM  app
 */
void  App_MB_TCP_CL::App_MB_TCP_CL_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_MB_TCP_CL::App_MB_TCP_CL_Execute()
{	
	atService_MB_TCP_CL.Run_Service();
    if(atApp_MB_TCP_CL.User_Mode == APP_USER_MODE_DEBUG)
    {
		
    }   
}
void  App_MB_TCP_CL::App_MB_TCP_CL_Suspend(){}
void  App_MB_TCP_CL::App_MB_TCP_CL_Resume(){}	  
void  App_MB_TCP_CL::App_MB_TCP_CL_End(){}
void atApp_MB_TCP_CL_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_MB_TCP_CL.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}
#endif