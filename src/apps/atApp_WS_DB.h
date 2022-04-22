/**
@file

*/
/*
  Application

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_Web_Server_
#define _Application_atApp_Web_Server_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/web_server/atService_Web_Server.h"
#include "atApp_Wifi.h"
/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_Web_Server;  
void atApp_Web_Server_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */

/**
 * This Application class is the application to manage the 
 */
class App_Web_Server : public Application
{
public:
  	App_Web_Server();
 	~App_Web_Server();
  	static void  App_Web_Server_Pend();
	static void  App_Web_Server_Start();
	static void  App_Web_Server_Restart();
	static void  App_Web_Server_Execute();
	static void  App_Web_Server_Suspend();
	static void  App_Web_Server_Resume();	  
	static void  App_Web_Server_End();

	char name_of_device[100] = "SNM_Device";
	// upload time (s)
	uint8_t upload_time = 5; 
protected:
private:
} atApp_Web_Server ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_Web_Server::App_Web_Server(/* args */)
{
  	_Pend_User 	     = *App_Web_Server_Pend;
	_Start_User 	 = *App_Web_Server_Start;
	_Restart_User 	 = *App_Web_Server_Restart;
	_Execute_User 	 = *App_Web_Server_Execute;
	_Suspend_User	 = *App_Web_Server_Suspend;
	_Resume_User	 = *App_Web_Server_Resume;
	_End_User	     = *App_Web_Server_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"Web_Server Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_Web_Server::~App_Web_Server()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_Web_Server::App_Web_Server_Pend()
{

}
/**
 * This start function will init some critical function 
 */
void  App_Web_Server::App_Web_Server_Start()
{
	// init atWeb_Server Service in the fist running time
	atService_Web_Server.Run_Service();
	
}  
/**
 * Restart function of SNM  app
 */
void  App_Web_Server::App_Web_Server_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_Web_Server::App_Web_Server_Execute()
{	
	// server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request)
	// 	{
        	// request->send(200, "text/plain", "Scanned networks");
        	// request->send(200, "text/plain", atApp_Wifi.scanned_Wifi_SSIDs);
			// request->send(200, "text/plain", "Information connecting wifi:\n");
        	// request->send(200, "text/plain", "Connecting RSSI:     dB"); 		
			// request->send(200, "text/plain", atApp_Wifi.IP);
			// request->send(200, "text/plain", atApp_Wifi.connecting_Password);

		server.on("/scan", HTTP_GET, [](AsyncWebServerRequest * request) {
		String json = "[";
		 json += "{";
		 json += "\"Scanned networks\":" + String(atApp_Wifi.scanned_Wifi_SSIDs);
		 json += "Information connecting wifi:\n";
		 json += "Connecting RSSI:" + String(atApp_Wifi.collecting_wifi_RSSI)+ String("dB \n");
		 json += "Connecting SSID:" + String(atApp_Wifi.connecting_SSID)+ String("\n");
		 json += "Connecting password:" + String(atApp_Wifi.connecting_Password)+ String("\n");
		 json += "Connecting IP:" + String(atApp_Wifi.IP)+ String("\n");
		 json += "Connecting gateway:" + String(atApp_Wifi.Gateway)+ String("\n");
		 json += "Connecting subnet:" + String(atApp_Wifi.Subnet)+ String("\n");
		 json += "Connecting dns:" + String(atApp_Wifi.DNS)+ String("\n");

		 json += "Wifi status:";
		 switch (atApp_Wifi.status)
        {
        case WIFI_STATUS_Idle:
            json += "Idle";
            break;

        case WIFI_STATUS_Scanning:
            json += " scanning";
            break;

        case WIFI_STATUS_Scan_Completed:
            json += "completed scanning";
            break;

        case WIFI_STATUS_Connecting:
            json += "Connecting";
            break;

        case WIFI_STATUS_Connected:
            json += "connected";
            break;

        case WIFI_STATUS_Connect_Failed:
            json += "failed to connect";
            break;

        case WIFI_STATUS_Connection_Lost:
            json += "lost connection";
            break;

        case WIFI_STATUS_Disconnecting:
            json += "Wifi is being disconnecting";
            break;

        case WIFI_STATUS_Disconnected:
            json += "Wifi has disconnected";
            break;

        default:
            break;
        }

		 request->send(200, "application/json", json);
		 json = String();
		});
}
void  App_Web_Server::App_Web_Server_Suspend(){}
void  App_Web_Server::App_Web_Server_Resume(){}	  
void  App_Web_Server::App_Web_Server_End(){}
void atApp_Web_Server_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_Web_Server.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}
#endif