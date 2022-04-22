#ifndef _Register_atMB_
#define _Register_atMB_

/* _____DEFINETIONS__________________________________________________________ */

#define Initial_value 0


// State of the Sensor 
#define ACTIVATE 1
#define DEACTIVATE 0

enum SNM_REGISTER_INDEX
{
SMM_REGISTER_RW_SHT30_SENSOR_STATE = 3001,                  
SMM_REGISTER_RW_SGP30_SENSOR_STATE,                       
SMM_REGISTER_RW_FAULT_CODE,                  
/*
 Setting Sensor Node Module
*/

// Frequency of data collection ( 1 - 65535 seconds)
SMM_REGISTER_RW_SAMPLING_INTERVAL,                      
//  Average divisor ( 0 - 255)
SMM_REGISTER_RW_NUMBER_SAMPLING,                        
// Comparison in that period ( 1 - 65535 seconds)
SMM_REGISTER_RW_RANGE_TIME,                         

/*
 Temperature Parameter
*/

//Temperature in present time
SNM_REGISTER_R_TEMPERATURE_REAL_TIME,                    
//The average temperature during a time period
SNM_REGISTER_R_MEAN_TEMPERATURE,                         
//The max temperature during a given time period
SNM_REGISTER_R_MAX_TEMPERATURE,                          
//The min temperature during a given time period
SNM_REGISTER_R_MIN_TEMPERATURE,                          

/*
 Humidity Parameter
*/

//Humidity in present time
SNM_REGISTER_R_HUMIDITY_REAL_TIME,                      
//The average Humidity during a time period
SNM_REGISTER_R_MEAN_HUMIDITY,                           
//The max Humidity during a given time period
SNM_REGISTER_R_MAX_HUMIDITY,                            
//The min Humidity during a given time period
SNM_REGISTER_R_MIN_HUMIDITY,                            

/*
 CO2 Parameter
*/

//CO2 in present time
SNM_REGISTER_R_CO2_REAL_TIME,                        
//The average CO2 during a time period
SNM_REGISTER_R_MEAN_CO2,                             
//The max CO2 during a given time period
SNM_REGISTER_R_MAX_CO2,                              
//The min CO2 during a given time period
SNM_REGISTER_R_MIN_CO2,                              
             
/*
 H2 Parameter
*/

//H2 in present time
SNM_REGISTER_R_H2_REAL_TIME,                           
//The average H2 during a time period
SNM_REGISTER_R_MEAN_H2,                                 
//The max H2 during a given time period
SNM_REGISTER_R_MAX_H2,                                  
//The min H2 during a given time period
SNM_REGISTER_R_MIN_H2,                                  
               
/*
 TVOC Parameter
*/

//TVOC in present time
SNM_REGISTER_R_TVOC_REAL_TIME,                         
//The average TVOC during a time period
SNM_REGISTER_R_MEAN_TVOC,                              
//The max TVOC during a given time period
SNM_REGISTER_R_MAX_TVOC,                               
//The min TVOC during a given time period
SNM_REGISTER_R_MIN_TVOC,                               

/*
 Ethanol Parameter
*/

//Ethanol in present time
SNM_REGISTER_R_ETHANOL_REAL_TIME,                     
//The average Ethanol during a time period
SNM_REGISTER_R_MEAN_ETHANOL,                          
//The max Ethanol during a given time period
SNM_REGISTER_R_MAX_ETHANOL,                           
//The min Ethanol during a given time period
SNM_REGISTER_R_MIN_ETHANOL,                           
};

/***********
 ---------- General Register ------------
***********/

enum GENERAL_REGISTER_INDEX
{

/*
 Modbus
*/

GENERAL_REGISTER_RW_MODBUS_RTU_ID   =  1,                    
GENERAL_REGISTER_RW_MODBUS_RTU_BAUDRATE,                
GENERAL_REGISTER_RW_MODBUS_RTU_CHECK_NUMBER,            
//Time interval returns  for data to be after received command
GENERAL_REGISTER_RW_MODBUS_RTU_TIME_DELAY_FOR_RETURN_DA,  
// MODBUS TCP/IP: A.B.C.D
GENERAL_REGISTER_R_MODBUS_TCP_IP_A,                     
GENERAL_REGISTER_R_MODBUS_TCP_IP_B,                     
GENERAL_REGISTER_R_MODBUS_TCP_IP_C,                     
GENERAL_REGISTER_R_MODBUS_TCP_IP_D,                     
// eg: 502 for modbus
GENERAL_REGISTER_R_MODBUS_TCP_IP_PORT,                              
                                       

/*
 Device identification
*/

GENERAL_REGISTER_R_DEVICE_TYPE,                                       
//The level of this device           
GENERAL_REGISTER_RW_DEVICE_LEVEL,                                           
//Level highest for groups
GENERAL_REGISTER_RW_LEVEL_1,                                          
GENERAL_REGISTER_RW_LEVEL_2,                                            
GENERAL_REGISTER_RW_LEVEL_3,                                          
//Level lowest for groups                    
GENERAL_REGISTER_RW_LEVEL_4,                                          

/*
 Control
*/

GENERAL_REGISTER_RW_CONTROL_COMMAND_CCA,                              
GENERAL_REGISTER_RW_CONTROL_COMMAND_CCB,                              
GENERAL_REGISTER_R_FAULT_CODE,                                        

/******************************
 Wifi
******************************/

//Enable wifi driver
GENERAL_REGISTER_RW_WIFI_ENABLE,                                      
GENERAL_REGISTER_R_WIFI_STATUS ,                                      
//Received signal strength indication 
GENERAL_REGISTER_R_WIFI_RSSI,                                         

//SSID of wifi is connecting and to connect. 
//They are converter to char and merge to a string conclude 30 char
GENERAL_REGISTER_RW_WIFI_SSID_1,                                      
GENERAL_REGISTER_RW_WIFI_SSID_2,                                      
GENERAL_REGISTER_RW_WIFI_SSID_3,                                      
GENERAL_REGISTER_RW_WIFI_SSID_4,                                      
GENERAL_REGISTER_RW_WIFI_SSID_5,                                      
GENERAL_REGISTER_RW_WIFI_SSID_6,                                      
GENERAL_REGISTER_RW_WIFI_SSID_7,                                      
GENERAL_REGISTER_RW_WIFI_SSID_8,                                      
GENERAL_REGISTER_RW_WIFI_SSID_9,                                      
GENERAL_REGISTER_RW_WIFI_SSID_10,                                     
GENERAL_REGISTER_RW_WIFI_SSID_11,                                     
GENERAL_REGISTER_RW_WIFI_SSID_12,                                     
GENERAL_REGISTER_RW_WIFI_SSID_13,                                     
GENERAL_REGISTER_RW_WIFI_SSID_14,                                     
GENERAL_REGISTER_RW_WIFI_SSID_15,                                     
GENERAL_REGISTER_RW_WIFI_SSID_16,                                     
GENERAL_REGISTER_RW_WIFI_SSID_17,                                     
GENERAL_REGISTER_RW_WIFI_SSID_18,                                     
GENERAL_REGISTER_RW_WIFI_SSID_19,                                     
GENERAL_REGISTER_RW_WIFI_SSID_20,                                     
GENERAL_REGISTER_RW_WIFI_SSID_21,                                     
GENERAL_REGISTER_RW_WIFI_SSID_22,                                     
GENERAL_REGISTER_RW_WIFI_SSID_23,                                     
GENERAL_REGISTER_RW_WIFI_SSID_24,                                     
GENERAL_REGISTER_RW_WIFI_SSID_25,                                     
GENERAL_REGISTER_RW_WIFI_SSID_26,                                     
GENERAL_REGISTER_RW_WIFI_SSID_27,                                     
GENERAL_REGISTER_RW_WIFI_SSID_28,                                     
GENERAL_REGISTER_RW_WIFI_SSID_29,                                     
GENERAL_REGISTER_RW_WIFI_SSID_30,                                     
GENERAL_REGISTER_RW_WIFI_SSID_31,                                     

//Password wifi is connecting and to connect.
//They are converter to char and merge to a string conclude 30 char
GENERAL_REGISTER_RW_WIFI_PASSWORD_1,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_2,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_3,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_4,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_5,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_6,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_7,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_8,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_9,                                  
GENERAL_REGISTER_RW_WIFI_PASSWORD_10,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_11,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_12,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_13,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_14,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_15,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_16,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_17,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_18,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_19,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_20,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_21,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_22,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_23,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_24,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_25,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_26,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_27,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_28,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_29,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_30,                                 
GENERAL_REGISTER_RW_WIFI_PASSWORD_31,                                 

//local IP: A.B.C.D
GENERAL_REGISTER_RW_WIFI_LOCAL_IP_A,                                  
GENERAL_REGISTER_RW_WIFI_LOCAL_IP_B,                                  
GENERAL_REGISTER_RW_WIFI_LOCAL_IP_C,                                  
GENERAL_REGISTER_RW_WIFI_LOCAL_IP_D,                                  

//gateway: A.B.C.D
GENERAL_REGISTER_RW_WIFI_GATEWAY_A,                                   
GENERAL_REGISTER_RW_WIFI_GATEWAY_B,                                   
GENERAL_REGISTER_RW_WIFI_GATEWAY_C,                                   
GENERAL_REGISTER_RW_WIFI_GATEWAY_D,                                   

//subnet mark: A.B.C.
GENERAL_REGISTER_RW_WIFI_SUBNET_A,                                    
GENERAL_REGISTER_RW_WIFI_SUBNET_B,                                    
GENERAL_REGISTER_RW_WIFI_SUBNET_C,                                    
GENERAL_REGISTER_RW_WIFI_SUBNET_D,                                    

//primary DNS: A.B.C.D
GENERAL_REGISTER_RW_WIFI_PRIMARY_DNS_A,                              
GENERAL_REGISTER_RW_WIFI_PRIMARY_DNS_B,                              
GENERAL_REGISTER_RW_WIFI_PRIMARY_DNS_C,                              
GENERAL_REGISTER_RW_WIFI_PRIMARY_DNS_D,                              

//secondary DNS: A.B.C.D
GENERAL_REGISTER_RW_WIFI_SECONDARY_DNS_A,                             
GENERAL_REGISTER_RW_WIFI_SECONDARY_DNS_B,                             
GENERAL_REGISTER_RW_WIFI_SECONDARY_DNS_C,                             
GENERAL_REGISTER_RW_WIFI_SECONDARY_DNS_D,                             

/*
 Ethernet
*/

GENERAL_REGISTER_RW_ETHERNET_ENABLE,                                  

////local IP: A.B.C.D
GENERAL_REGISTER_RW_ETHERNET_LOCAL_IP_A,                              
GENERAL_REGISTER_RW_ETHERNET_LOCAL_IP_B,                              
GENERAL_REGISTER_RW_ETHERNET_LOCAL_IP_C,                              
GENERAL_REGISTER_RW_ETHERNET_LOCAL_IP_D,                              

//gateway: A.B.C.D
GENERAL_REGISTER_RW_ETHERNET_GATEWAY_A,                               
GENERAL_REGISTER_RW_ETHERNET_GATEWAY_B,                               
GENERAL_REGISTER_RW_ETHERNET_GATEWAY_C,                               
GENERAL_REGISTER_RW_ETHERNET_GATEWAY_D,                               

//subnet mark: A.B.C.D
GENERAL_REGISTER_RW_ETHERNET_SUBNET_A,                                
GENERAL_REGISTER_RW_ETHERNET_SUBNET_B,                                
GENERAL_REGISTER_RW_ETHERNET_SUBNET_C,                                
GENERAL_REGISTER_RW_ETHERNET_SUBNET_D,    

//primary DNS: A.B.C.D
GENERAL_REGISTER_RW_ETHERNET_PRIMARY_DNS_A,                           
GENERAL_REGISTER_RW_ETHERNET_PRIMARY_DNS_B,                           
GENERAL_REGISTER_RW_ETHERNET_PRIMARY_DNS_C,                           
GENERAL_REGISTER_RW_ETHERNET_PRIMARY_DNS_D,                           

//secondary DNS: A.B.C.D
GENERAL_REGISTER_RW_ETHERNET_SECONDARY_DNS_A,                         
GENERAL_REGISTER_RW_ETHERNET_SECONDARY_DNS_B,                         
GENERAL_REGISTER_RW_ETHERNET_SECONDARY_DNS_C,                         
GENERAL_REGISTER_RW_ETHERNET_SECONDARY_DNS_D,                         

/*
 Mesh
*/

//Enable mesh driver
GENERAL_REGISTER_RW_MESH_ENABLE,                                        

//MESH ID: A.B.C.D.E.F.G.H

GENERAL_REGISTER_R_MESH_ID_A,                                         
GENERAL_REGISTER_R_MESH_ID_B,                                         
GENERAL_REGISTER_R_MESH_ID_C,                                         
GENERAL_REGISTER_R_MESH_ID_D,                                         
GENERAL_REGISTER_R_MESH_ID_E,                                         
GENERAL_REGISTER_R_MESH_ID_F,                                         
GENERAL_REGISTER_R_MESH_ID_G,                                         
GENERAL_REGISTER_R_MESH_ID_H,                                         

//Password wifi is connecting and to connect. 
//They are converter to char and merge to a string conclude 11 char
GENERAL_REGISTER_RW_MESH_PREFIX_1,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_2,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_3,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_4,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_5,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_6,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_7,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_8,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_9,                                    
GENERAL_REGISTER_RW_MESH_PREFIX_10,                                  
GENERAL_REGISTER_RW_MESH_PREFIX_11,                                  

//Password wifi is connecting and to connect. 
//They are converter to char and merge to a string conclude 10 char
GENERAL_REGISTER_RW_MESH_PASSWORD_1,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_2,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_3,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_4,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_5,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_6,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_7,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_8,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_9,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_10,                                 
GENERAL_REGISTER_RW_MESH_PASSWORD_11,                                 

//eg 5555
GENERAL_REGISTER_RW_MESH_PORT,                                        

/*
 Electrical characteristic
*/
GENERAL_REGISTER_R_220V_BUS_VOLTAGE,                                  
GENERAL_REGISTER_R_220V_BUS_CURRENT,                                  
GENERAL_REGISTER_R_24V_BUS_VOLTAGE,                                   
GENERAL_REGISTER_R_24V_BUS_CURRENT,                                   
GENERAL_REGISTER_R_12V_BUS_VOLTAGE,                                   
GENERAL_REGISTER_R_12V_BUS_CURRENT,                                   
GENERAL_REGISTER_R_5V_BUS_VOLTAGE,                                    
GENERAL_REGISTER_R_5V_BUS_CURRENT,                                    
GENERAL_REGISTER_R_3V3_BUS_VOLTAGE,                                   
GENERAL_REGISTER_R_3V3_BUS_CURRENT,          

/*
 Condition operating
*/
 GENERAL_REGISTER_R_TEMPERATURE,                                       
 GENERAL_REGISTER_R_HUMIDITY,                                          
};

#endif