/**
@file
*/
/*
  Service_atService_Web_Server.h

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Service_atService_Web_Server_
#define _Service_atService_Web_Server_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "../Service.h"
#include "ESPAsyncWebServer.h" 

/* _____DEFINETIONS__________________________________________________________ */

AsyncWebServer server(80);
AsyncResponseStream *response;

/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This Service class is the Service to manage the 
 */
class Service_Web_Server : public Service
{
public:
    Service_Web_Server();
    ~Service_Web_Server();
    static void  Service_Web_Server_Start();
    static void  Service_Web_Server_Execute();    
    static void  Service_Web_Server_End();
protected:
private:
} atService_Web_Server ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
Service_Web_Server::Service_Web_Server(/* args */)
{
    _Start_User      = *Service_Web_Server_Start;
    _Execute_User    = *Service_Web_Server_Execute;
    _End_User        = *Service_Web_Server_End;

    // change the ID of Service
    ID_Service = 1;
    // change the Service name
    Name_Service = (char*)"Web_Server Service";
    // change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
Service_Web_Server::~Service_Web_Server()
{
    
}
/**
 * This start function will init some critical function 
 */



void  Service_Web_Server::Service_Web_Server_Start()
{
  server.begin();
}
 

/**
 * Execute fuction of SNM app
 */
void  Service_Web_Server::Service_Web_Server_Execute()
{   
 
}    
void  Service_Web_Server::Service_Web_Server_End(){}



#endif


