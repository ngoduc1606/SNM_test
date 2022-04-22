/**
@file
*/
/*

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atHMI_
#define _Application_atHMI_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/lvgl/atService_LVGL_HMI.h"
#include "../services/lvgl/atService_atButtons_LEDs_PCF8575.h"

/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */

lv_obj_t * label_Voltage_Phase_A;
lv_obj_t * label_Voltage_Phase_B;
lv_obj_t * label_Voltage_Phase_C;

lv_obj_t * label_Current_Phase_A;
lv_obj_t * label_Current_Phase_B;
lv_obj_t * label_Current_Phase_C;

lv_obj_t * label_Power_Phase_A;
lv_obj_t * label_Power_Phase_B;
lv_obj_t * label_Power_Phase_C;

lv_obj_t * label_Cosfi_Phase_A;
lv_obj_t * label_Cosfi_Phase_B;
lv_obj_t * label_Cosfi_Phase_C;

///////////////////////////////////////////////Testing part//


/* _____GLOBAL FUNCTION______________________________________________________ */

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
}  atHMI ;
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
	// atButtons.Debug();
	// atButtons_LEDs_PCF8575.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_HMI::App_HMI_Start()
{
	// init atHMI Service in the fist running time
	atService_LVGL_HMI.Run_Service();
	atService_Buttons_LEDs_PCF8575.Run_Service();

	lv_obj_t * label1 = lv_label_create(lv_scr_act());
    lv_label_set_long_mode(label1, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
    lv_label_set_recolor(label1, true);                      /*Enable re-coloring by commands in the text*/
    lv_label_set_text(label1, "#0000ff Re-color# #ff00ff words# #ff0000 of a# label, align the lines to the center "
                      "and wrap long text automatically.");
    lv_obj_set_width(label1, 150);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, -40);

    lv_obj_t * label2 = lv_label_create(lv_scr_act());
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR);     /*Circular scroll*/
    lv_obj_set_width(label2, 150);
    lv_label_set_text(label2, "It is a circularly scrolling text. ");
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 40);

	atService_Buttons_LEDs_PCF8575.LED_RGB_1 = RED;
	atService_Buttons_LEDs_PCF8575.LED_RGB_2 = RED;
	atService_Buttons_LEDs_PCF8575.LED_RGB_3 = RED;
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
	atService_LVGL_HMI.Run_Service();
	atService_Buttons_LEDs_PCF8575.Run_Service();

	if(atHMI.User_Mode == APP_USER_MODE_DEBUG)
    {
    }   
}
void  App_HMI::App_HMI_Suspend(){}
void  App_HMI::App_HMI_Resume(){}	  
void  App_HMI::App_HMI_End(){}

#endif