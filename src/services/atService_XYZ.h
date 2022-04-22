/**
@file
Service for communicating with OP320A&S SNM over RS232/485 (via RTU protocol).
*/
/*
  Service_atService_XYZ.h - Arduino library for communicating with OP320A&S SNM
  over RS232/485 (via RTU protocol).

  Library:: chickyPig_OP320_V1

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Service_atService_XYZ_
#define _Service_atService_XYZ_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "Service.h"
/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */

///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This Service class is the Service to manage the 
 */
class Service_XYZ : public Service
{
public:
    Service_XYZ();
    ~Service_XYZ();
    static void  Service_XYZ_Start();
    static void  Service_XYZ_Execute();    
    static void  Service_XYZ_End();
protected:
     
private:
} atService_XYZ ;
/**
 * This function will be automatical called when a object is created by this class
 */
Service_XYZ::Service_XYZ(/* args */)
{
    _Start_User      = *Service_XYZ_Start;
    _Execute_User    = *Service_XYZ_Execute;
    _End_User        = *Service_XYZ_End;

    // change the ID of Service
    ID_Service = 1;
    // change the Service name
    Name_Service = (char*)"XYZ Service";
    // change the ID of SNM
}
/**
 * This function will be automatical called when the object of class is delete
 */
Service_XYZ::~Service_XYZ()
{
    
}
/**
 * This start function will init some critical function 
 */
void  Service_XYZ::Service_XYZ_Start()
{
    
}  

/**
 * Execute fuction of SNM app
 */
void  Service_XYZ::Service_XYZ_Execute()
{   
    if(atService_XYZ.User_Mode == SER_USER_MODE_DEBUG)
    {
        
    }   
}    
void  Service_XYZ::Service_XYZ_End(){}

#endif


