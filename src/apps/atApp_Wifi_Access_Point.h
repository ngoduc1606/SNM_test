/**
@file

*/
/*
  Application

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_Wifi_Access_Point_
#define _Application_atApp_Wifi_Access_Point_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "Arduino.h"
#include "WiFi.h"
/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_Wifi_Access_Point;  
void atApp_Wifi_Access_Point_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */
enum Network_Index_IPV4
{
    A = 0,
    B,
    C,
    D,
    IPV4_Index_Number
};
enum Wifi_Access_Point_Status
{
    WIFI_AP_STATUS_Idle,
    WIFI_AP_STATUS_Opening,
    WIFI_AP_STATUS_Open_Completed,
    WIFI_AP_STATUS_Checking,
    WIFI_AP_STATUS_Get_Data_Completed,
    WIFI_AP_STATUS_Closeing,
    WIFI_AP_STATUS_Close_Completed
};
enum Wifi_Access_Point_Request
{
    WIFI_AP_REQUEST_Idle,
    WIFI_AP_REQUEST_Open,
    WIFI_AP_REQUEST_Get_Data,
    WIFI_AP_REQUEST_Close
};
/* _____CLASS DEFINITION_____________________________________________________ */

/**
 * This Application class is the application to manage the 
 */
class App_Wifi_Access_Point : public Application
{
public:
  	App_Wifi_Access_Point();
 	~App_Wifi_Access_Point();
  	static void  App_Wifi_Access_Point_Pend();
	static void  App_Wifi_Access_Point_Start();
	static void  App_Wifi_Access_Point_Restart();
	static void  App_Wifi_Access_Point_Execute();
	static void  App_Wifi_Access_Point_Suspend();
	static void  App_Wifi_Access_Point_Resume();	  
	static void  App_Wifi_Access_Point_End();

    Wifi_Access_Point_Status status = WIFI_AP_STATUS_Idle;
    Wifi_Access_Point_Request request = WIFI_AP_REQUEST_Idle;

    // Set up an access point
    char IP[20] = "";
    char Gateway[20] ="";
    char Subnet[20] = "";
    
    char ssid[100] = "... device AP";
    char password[100] = "12345678";
    int channel_of_wifi_ap = 1;         // WiFi channel number, 1 - 13.
    int ssid_hidden = 0;                 // Network cloaking (0 = broadcast SSID, 1 = hide SSID)
    int max_connection = 4;              // Max simultaneous connected clients, 1 - 4.

    // data of network wifi
    int number_of_device_connected;

protected:
    void open_access_point();
    void get_data();
    void close_access_point();
private:
} atApp_Wifi_Access_Point ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_Wifi_Access_Point::App_Wifi_Access_Point(/* args */)
{
  	_Pend_User 	     = *App_Wifi_Access_Point_Pend;
	_Start_User 	 = *App_Wifi_Access_Point_Start;
	_Restart_User 	 = *App_Wifi_Access_Point_Restart;
	_Execute_User 	 = *App_Wifi_Access_Point_Execute;
	_Suspend_User	 = *App_Wifi_Access_Point_Suspend;
	_Resume_User	 = *App_Wifi_Access_Point_Resume;
	_End_User	     = *App_Wifi_Access_Point_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"Wifi_Access_Point Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_Wifi_Access_Point::~App_Wifi_Access_Point()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_Wifi_Access_Point::App_Wifi_Access_Point_Pend()
{
  
}
/**
 * This start function will init some critical function 
 */
void  App_Wifi_Access_Point::App_Wifi_Access_Point_Start()
{
	// init atXYZ Service in the fist running time
    Serial.begin(115200);
    
    WiFi.softAP(atApp_Wifi_Access_Point.ssid,               atApp_Wifi_Access_Point.password,
                atApp_Wifi_Access_Point.channel_of_wifi_ap, atApp_Wifi_Access_Point.ssid_hidden,
                atApp_Wifi_Access_Point.max_connection                                          );
}  
/**
 * Restart function of SNM  app
 */
void  App_Wifi_Access_Point::App_Wifi_Access_Point_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_Wifi_Access_Point::App_Wifi_Access_Point_Execute()
{	
	// execute the request
    switch (atApp_Wifi_Access_Point.request)
    {
    case WIFI_AP_REQUEST_Open:
        atApp_Wifi_Access_Point.status = WIFI_AP_STATUS_Opening;
        atApp_Wifi_Access_Point.open_access_point();
        atApp_Wifi_Access_Point.status = WIFI_AP_STATUS_Open_Completed;
        atApp_Wifi_Access_Point.request = WIFI_AP_REQUEST_Idle;
        break;

    case WIFI_AP_REQUEST_Get_Data:
        atApp_Wifi_Access_Point.status = WIFI_AP_STATUS_Checking;
        atApp_Wifi_Access_Point.get_data();
        atApp_Wifi_Access_Point.status = WIFI_AP_STATUS_Get_Data_Completed;
        break;

    case WIFI_AP_REQUEST_Close:
        atApp_Wifi_Access_Point.status = WIFI_AP_STATUS_Closeing;
        atApp_Wifi_Access_Point.close_access_point();
        atApp_Wifi_Access_Point.status = WIFI_AP_STATUS_Close_Completed;
        atApp_Wifi_Access_Point.request = WIFI_AP_REQUEST_Idle;
        break;
    }

    if(atApp_Wifi_Access_Point.User_Mode == APP_USER_MODE_DEBUG)
    {
		
    }   
}
void  App_Wifi_Access_Point::App_Wifi_Access_Point_Suspend(){}
void  App_Wifi_Access_Point::App_Wifi_Access_Point_Resume(){}	  
void  App_Wifi_Access_Point::App_Wifi_Access_Point_End(){}

void  App_Wifi_Access_Point::open_access_point()
{
        // Set your Static IP address
        IPAddress local_IP( atApp_Wifi_Access_Point.IP[A], 
                            atApp_Wifi_Access_Point.IP[B],
                            atApp_Wifi_Access_Point.IP[C], 
                            atApp_Wifi_Access_Point.IP[D]);
        // Set your Gateway IP address
        IPAddress gateway(  atApp_Wifi_Access_Point.Gateway[A], 
                            atApp_Wifi_Access_Point.Gateway[B],
                            atApp_Wifi_Access_Point.Gateway[C],
                            atApp_Wifi_Access_Point.Gateway[D]);

        IPAddress subnet(   atApp_Wifi_Access_Point.Subnet[A],
                            atApp_Wifi_Access_Point.Subnet[B],
                            atApp_Wifi_Access_Point.Subnet[C],
                            atApp_Wifi_Access_Point.Subnet[D]);
                        
    WiFi.softAPConfig(local_IP, gateway, subnet);

    WiFi.softAP(atApp_Wifi_Access_Point.ssid,               atApp_Wifi_Access_Point.password,
                atApp_Wifi_Access_Point.channel_of_wifi_ap, atApp_Wifi_Access_Point.ssid_hidden,
                atApp_Wifi_Access_Point.max_connection                                          );

}

void  App_Wifi_Access_Point::get_data()
{
    atApp_Wifi_Access_Point.number_of_device_connected = WiFi.softAPgetStationNum();
}

void  App_Wifi_Access_Point::close_access_point()
{
    WiFi.softAPdisconnect();
}

void atApp_Wifi_Access_Point_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_Wifi_Access_Point.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}
#endif