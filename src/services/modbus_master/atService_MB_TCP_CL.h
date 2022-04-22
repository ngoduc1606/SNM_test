/**
@file
*/
/*
  Service_atService_MB_TCP_CL.h

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Service_atService_MB_TCP_CL_
#define _Service_atService_MB_TCP_CL_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "..\Service.h"
#include <ModbusIP_ESP8266.h>
/* _____DEFINETIONS__________________________________________________________ */

ModbusIP mb_TCP;

/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This Service class is the Service to manage the 
 */
class Service_MB_TCP_CL : public Service, public ModbusIP
{
public:
    Service_MB_TCP_CL();
    ~Service_MB_TCP_CL();
    static void  Service_MB_TCP_CL_Start();
    static void  Service_MB_TCP_CL_Execute();    
    static void  Service_MB_TCP_CL_End();
protected:
     
private:
} atService_MB_TCP_CL ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
Service_MB_TCP_CL::Service_MB_TCP_CL(/* args */)
{
    _Start_User      = *Service_MB_TCP_CL_Start;
    _Execute_User    = *Service_MB_TCP_CL_Execute;
    _End_User        = *Service_MB_TCP_CL_End;

    // change the ID of Service
    ID_Service = 1;
    // change the Service name
    Name_Service = (char*)"MB_TCP_CL Service";
    // change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
Service_MB_TCP_CL::~Service_MB_TCP_CL()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Service_MB_TCP_CL::Service_MB_TCP_CL_Start()
{
    atService_MB_TCP_CL.client();
}  

/**
 * Execute fuction of SNM app
 */
void  Service_MB_TCP_CL::Service_MB_TCP_CL_Execute()
{   
    atService_MB_TCP_CL.task();
    yield();
}    
void  Service_MB_TCP_CL::Service_MB_TCP_CL_End(){}

#endif


