/**
@file
*/
/*

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_HMI_
#define _Application_atApp_HMI_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/lvgl/atService_LVGL_HMI_Lite.h"
#include "GUI_HMI_Lite/gui_guider.h"
#include "GUI_HMI_Lite/events_init.h"
// #include "GUI_HMI_Lite/custom.h"


// #include "../services/lvgl/atService_atButtons_LEDs_PCF8575.h"

/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */

///////////////////////////////////////////////Testing part//


/* _____GLOBAL FUNCTION______________________________________________________ */
TaskHandle_t Task_atApp_HMI;  
void atApp_HMI_Task_Func(void *parameter);
/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This Application class is the application to manage the 
 */
class App_HMI : public Application
{
public:
  	App_HMI();
 	~App_HMI();
  	static void  App_HMI_Pend();
	static void  App_HMI_Start();
	static void  App_HMI_Restart();
	static void  App_HMI_Execute();
	static void  App_HMI_Suspend();
	static void  App_HMI_Resume();	  
	static void  App_HMI_End();

	// bool update = 0;
protected:
private:
}  atApp_HMI ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_HMI::App_HMI(/* args */)
{
  	_Pend_User 	     = *App_HMI_Pend;
	_Start_User 	 = *App_HMI_Start;
	_Restart_User 	 = *App_HMI_Restart;
	_Execute_User 	 = *App_HMI_Execute;
	_Suspend_User	 = *App_HMI_Suspend;
	_Resume_User	 = *App_HMI_Resume;
	_End_User	     = *App_HMI_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"HMI Application";
	// change the ID of SNM

	
	
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_HMI::~App_HMI()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. 
 * In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_HMI::App_HMI_Pend()
{
	atService_LVGL_HMI_Lite.Debug();
	// atButtons_LEDs_PCF8575.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_HMI::App_HMI_Start()
{
	// init atApp_HMI Service in the fist running time
	atService_LVGL_HMI_Lite.Run_Service();
	// init GUI
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    // custom_init(&guider_ui);

}  
/**
 * Restart function of SNM  app
 */
void  App_HMI::App_HMI_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_HMI::App_HMI_Execute()
{	
	atService_LVGL_HMI_Lite.Run_Service();
	if(atApp_HMI.User_Mode == APP_USER_MODE_DEBUG)
    {
    }   
}
void  App_HMI::App_HMI_Suspend(){}
void  App_HMI::App_HMI_Resume(){}	  
void  App_HMI::App_HMI_End(){}
void atApp_HMI_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_HMI.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(10/ portTICK_PERIOD_MS);
  }
}
#endif