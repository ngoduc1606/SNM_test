/**
@file
Objective for control with Esp32 Wrover.
*/
/*
  Object_EMMs_Data.h - Arduino library for control with ESP32
  Library:: Object_EMMs_Data
  This version is
  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef Object_EMMs_Data_h
#define Object_EMMs_Data_h


/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
#include "Object.h"

/* _____DEFINETIONS__________________________________________________________ */

struct EMMs_data
{
    bool Status_of_EMMs;
    //value of host in IPv4 : (192, 168, Host_1, Host_2)
    uint8_t Host_1;     
    uint8_t Host_2;
    uint8_t IP[4]        = 	{192,168,Host_1,Host_2};
    uint8_t Alert;
    uint8_t voltage_phase_A;
    uint8_t voltage_phase_B;
    uint8_t voltage_phase_C;
    uint8_t current_phase_A;
    uint8_t current_phase_B;
    uint8_t current_phase_C;
    uint8_t active_power;
    uint8_t reactive_power;
    uint8_t apparent_power;
    uint8_t cosfi;
    uint8_t frequency;
    bool control_relay;
    bool aptomat_feedback;
    bool contactor_feedback;
    bool relay_feedback;
};

/* _____GLOBAL VARIABLES_____________________________________________________ */


/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */
/**
 * This class is the application to manage the 
 */

class Object_EMMs_Data :public Object
{
public:
    static void   Object_Cont_Start();
    static void   Object_Cont_Execute();    
    static void   Object_Cont_End();
    
    uint8_t Get_Fault_State();
    Object_EMMs_Data(/* args */);
    ~Object_EMMs_Data();
    uint8_t EMM_number = 0;
    //Max number of devices = 20;
    EMMs_data EMM[21];

protected: 
    
private:
    /* data */ 
} atObject_EMMs_Data;
/**
 * @brief This function code is executed one time when class is init
 * 
 */
Object_EMMs_Data::Object_EMMs_Data(/* args */)
{
     _Start_User      = *Object_Cont_Start;
     _Execute_User    = *Object_Cont_Execute;
     _End_User        = *Object_Cont_End;
}
/**
 * @brief This function code is executed one time when class is deinit
 * 
 */
Object_EMMs_Data::~Object_EMMs_Data()
{
}
/**
 * This start function will init some critical function 
 */
void  Object_EMMs_Data::Object_Cont_Start()
{
  
} 
/**
 * Execute fuction of EMM app
 */
void  Object_EMMs_Data:: Object_Cont_Execute()
{   

}    
void  Object_EMMs_Data:: Object_Cont_End(){}

#endif