/**
@file
Objective for control with Esp32 Wrover.
*/
/*
  Object_HDMs_Data.h - Arduino library for control with ESP32
  Library:: Object_HDMs_Data
  This version is
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef Object_HDMs_Data_h
#define Object_HDMs_Data_h


/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
#include "Object.h"

/* _____DEFINETIONS__________________________________________________________ */

struct HDMs_data
{
    bool Status_of_HDMs;
    //value of host in IPv4 : (192, 168, Host_1, Host_2)
    uint8_t Host_1;     
    uint8_t Host_2;
    uint8_t IP[4]        = 	{192,168,Host_1,Host_2};

    bool operation_mode;
    uint8_t low_limit_temperature;
    uint8_t high_limit_temperature;
    uint8_t power;
    uint8_t low_limit_power;
    uint8_t high_limit_power;
    uint8_t temperature;
};

/* _____GLOBAL VARIABLES_____________________________________________________ */


/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This class is the application to manage the 
 */

class Object_HDMs_Data :public Object
{
public:
    static void   Object_Cont_Start();
    static void   Object_Cont_Execute();    
    static void   Object_Cont_End();
    
    uint8_t Get_Fault_State();
    Object_HDMs_Data(/* args */);
    ~Object_HDMs_Data();
    uint8_t HDM_number = 0;
    //Max number of devices = 20;
    HDMs_data HDM[21];
protected: 
    
    
private:
    /* data */ 
} atObject_HDMs_Data;
/**
 * @brief This function code is executed one time when class is init
 * 
 */
Object_HDMs_Data::Object_HDMs_Data(/* args */)
{
     _Start_User      = *Object_Cont_Start;
     _Execute_User    = *Object_Cont_Execute;
     _End_User        = *Object_Cont_End;
}
/**
 * @brief This function code is executed one time when class is deinit
 * 
 */
Object_HDMs_Data::~Object_HDMs_Data()
{
}
/**
 * This start function will init some critical function 
 */
void  Object_HDMs_Data::Object_Cont_Start()
{
  
} 
/**
 * Execute fuction of HDM app
 */
void  Object_HDMs_Data:: Object_Cont_Execute()
{   

}    
void  Object_HDMs_Data:: Object_Cont_End(){}

#endif