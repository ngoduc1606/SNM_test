/**
@file

*/
/*
  Application example t

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_SM_
#define _Application_atApp_SM_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "..\services\modbus_master\atService_MB_TCP_MA.h"
#include "..\services\modbus_register\General_MB_Register.h"
#include "..\obj\atObj_EMMs_Data.h"
#include "..\obj\atObj_HDMs_Data.h"
#include "..\obj\atObj_IDMs_Data.h"
#include "..\obj\atObj_RDMs_Data.h"
#include "..\obj\atObj_SNMs_Data.h"
/* _____DEFINETIONS__________________________________________________________ */
enum Status_of_device
{
	offline,
	online
};

enum Device_type
{
	RCM = 1,
	LCM,
	SNM,
	EMM,
	IDM,
	RDM,
	HDM
};
/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_SM;  
void atApp_SM_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */

/**
 * This Application class is the application to manage the 
 */
class App_SM : public Application
{
public:
  	App_SM();
 	~App_SM();
  	static void  App_SM_Pend();
	static void  App_SM_Start();
	static void  App_SM_Restart();
	static void  App_SM_Execute();
	static void  App_SM_Suspend();
	static void  App_SM_Resume();	  
	static void  App_SM_End();

	//value of host in IPv4 : (192, 168, Host_1, Host_2)
	uint8_t Host_1 = 0;
	uint8_t Host_2 = 2;
	uint8_t IP[4]        = 	{192,168,Host_1,Host_2};
	//Device type
	uint16_t DT = 0;
	//Device Identify
	uint16_t DID = 0;
	// Number buffer
	uint8_t SNM_number = 0;
	uint8_t IDM_number = 0;
	uint8_t EMM_number = 0;
	uint8_t RDM_number = 0;
	uint8_t HDM_number = 0;


protected:
	void create_id_of_SNM();
	void create_id_of_EMM();
	void create_id_of_IDM();
	void create_id_of_RDM();
	void create_id_of_HDM();

private:
} atApp_SM ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_SM::App_SM(/* args */)
{
  	_Pend_User 	     = *App_SM_Pend;
	_Start_User 	 = *App_SM_Start;
	_Restart_User 	 = *App_SM_Restart;
	_Execute_User 	 = *App_SM_Execute;
	_Suspend_User	 = *App_SM_Suspend;
	_Resume_User	 = *App_SM_Resume;
	_End_User	     = *App_SM_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"Scan module Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_SM::~App_SM()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_SM::App_SM_Pend()
{
}
/**
 * This start function will init some critical function 
 */
void  App_SM::App_SM_Start()
{
	// init atXYZ Service in the fist running time
}  
/**
 * Restart function of SNM  app
 */
void  App_SM::App_SM_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_SM::App_SM_Execute()
{	
	// Scan all module in network
	for(atApp_SM.Host_1 = 0; atApp_SM.Host_1 <=255; atApp_SM.Host_2++)
	{
		for(atApp_SM.Host_2 = 2; atApp_SM.Host_2 <=255; atApp_SM.Host_2++)
		{
			mb_TCP.connect(atApp_SM.IP); 
			mb_TCP.readHreg(atApp_SM.IP, GENERAL_REGISTER_R_DEVICE_TYPE, &atApp_SM.DT);
			mb_TCP.readHreg(atApp_SM.IP, GENERAL_REGISTER_RW_DEVICE_ID, &atApp_SM.DID);
			switch (atApp_SM.DT)
			{
				case SNM:
					atApp_SM.SNM_number++;
					atApp_SM.create_id_of_SNM();
					break;
				case EMM:
					atApp_SM.EMM_number++;
					atApp_SM.create_id_of_EMM();
					break;
				case IDM:
					atApp_SM.IDM_number++;
					atApp_SM.create_id_of_IDM();
					break;
				case RDM:
					atApp_SM.RDM_number++;
					atApp_SM.create_id_of_RDM();
					break;
				case HDM:
					atApp_SM.HDM_number++;
					atApp_SM.create_id_of_HDM();
					break;
			}
		}
	}

	// Save the number of module
	atObject_SNMs_Data.SNM_number = atApp_SM.SNM_number;
	atObject_EMMs_Data.EMM_number = atApp_SM.EMM_number;
	atObject_IDMs_Data.IDM_number = atApp_SM.IDM_number;
	atObject_RDMs_Data.RDM_number = atApp_SM.RDM_number;
	atObject_HDMs_Data.HDM_number = atApp_SM.HDM_number;
	
    if(atApp_SM.User_Mode == APP_USER_MODE_DEBUG)
    {
		Serial.println(atApp_SM.SNM_number++);
		for( uint8_t count = 1; count <= 20; count++)
		{
			if(atObject_SNMs_Data.SNM[count].Status_of_SNMs == online)
			{
				Serial.printf(" Module %d is online\n",count);
			}
			Serial.print("192.168.");
			Serial.print(atObject_SNMs_Data.SNM[count].Host_1);
			Serial.print(".");
			Serial.print(atObject_SNMs_Data.SNM[count].Host_2);
			Serial.print("\n");
		}
    }   
}
void  App_SM::App_SM_Suspend(){}
void  App_SM::App_SM_Resume(){}	  
void  App_SM::App_SM_End(){}
void atApp_SM_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_SM.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

//Allocate a new id for the SNM module
void App_SM::create_id_of_SNM()
{	
	if (atApp_SM.DID == 0)
	{	
		for (uint16_t a = 1; a <= 20; a++)
		{
			if(atObject_SNMs_Data.SNM[a].Status_of_SNMs == offline)
			{
				mb_TCP.writeHreg(atApp_SM.IP, GENERAL_REGISTER_RW_DEVICE_ID, a);
				atObject_SNMs_Data.SNM[a].Status_of_SNMs = online;
				// save device IP to obj
				atObject_SNMs_Data.SNM[a].Host_1 = atApp_SM.Host_1;
				atObject_SNMs_Data.SNM[a].Host_2 = atApp_SM.Host_2;
				break;
			}
		}
	}
}

//Allocate a new id for the EMM module
void App_SM::create_id_of_EMM()
{	
	if (atApp_SM.DID == 0)
	{	
		for (uint16_t a = 1; a <= 20; a++)
		{
			if(atObject_EMMs_Data.EMM[a].Status_of_EMMs == offline)
			{
				mb_TCP.writeHreg(atApp_SM.IP, GENERAL_REGISTER_RW_DEVICE_ID, a);
				atObject_EMMs_Data.EMM[a].Status_of_EMMs = online;
				// save device IP to obj
				atObject_EMMs_Data.EMM[a].Host_1 = atApp_SM.Host_1;
				atObject_EMMs_Data.EMM[a].Host_2 = atApp_SM.Host_2;
				break;
			}
		}
	}
}

//Allocate a new id for the IDM module
void App_SM::create_id_of_IDM()
{	
	if (atApp_SM.DID == 0)
	{	
		for (uint16_t a = 1; a <= 20; a++)
		{
			if(atObject_IDMs_Data.IDM[a].Status_of_IDMs == offline)
			{
				mb_TCP.writeHreg(atApp_SM.IP, GENERAL_REGISTER_RW_DEVICE_ID, a);
				atObject_IDMs_Data.IDM[a].Status_of_IDMs = online;
				// save device IP to obj
				atObject_IDMs_Data.IDM[a].Host_1 = atApp_SM.Host_1;
				atObject_IDMs_Data.IDM[a].Host_2 = atApp_SM.Host_2;
				break;
			}
		}
	}
}

//Allocate a new id for the RDM module
void App_SM::create_id_of_RDM()
{	
	if (atApp_SM.DID == 0)
	{	
		for (uint16_t a = 1; a <= 20; a++)
		{
			if(atObject_RDMs_Data.RDM[a].Status_of_RDMs == offline)
			{
				mb_TCP.writeHreg(atApp_SM.IP, GENERAL_REGISTER_RW_DEVICE_ID, a);
				atObject_RDMs_Data.RDM[a].Status_of_RDMs = online;
				// save device IP to obj
				atObject_RDMs_Data.RDM[a].Host_1 = atApp_SM.Host_1;
				atObject_RDMs_Data.RDM[a].Host_2 = atApp_SM.Host_2;
				break;
			}
		}
	}
}

//Allocate a new id for the HDM module
void App_SM::create_id_of_HDM()
{	
	if (atApp_SM.DID == 0)
	{	
		for (uint16_t a = 1; a <= 20; a++)
		{
			if(atObject_HDMs_Data.HDM[a].Status_of_HDMs == offline)
			{
				mb_TCP.writeHreg(atApp_SM.IP, GENERAL_REGISTER_RW_DEVICE_ID, a);
				atObject_HDMs_Data.HDM[a].Status_of_HDMs = online;
				// save device IP to obj
				atObject_HDMs_Data.HDM[a].Host_1 = atApp_SM.Host_1;
				atObject_HDMs_Data.HDM[a].Host_2 = atApp_SM.Host_2;
				break;
			}
		}
	}
}

#endif