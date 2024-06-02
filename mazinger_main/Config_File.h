//>>>>>>>>>>>>>>>>>>>>>>>>>Mazinger: Configuration File<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/*******************************************************************************************************************/
/*******************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                          *********************/
/*******************  FILE NAME      : Config_File.h                                           *********************/
/*******************  Layer          : Application(Configuration)                              *********************/
/*******************  Project        : 4-Wheel RC Robot Car with (3 Joints)ARM                 *********************/
/*******************  Microcontroller: ESP-32 DevelopmentKIT                                   *********************/
/*******************  Version        : 1.00                                                    *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                            IMPORTANT INFORMATION                                                                                 //
//                                                                            ---------------------                                                                                 //
// >> In this file you can change the configuration pins , and init                                                                                                                           //
// ##Attention## : All the fixed configurations are now related to the PCB connections, so please don't change anything                                                             //
//                 here related to the hardware connection pins without consulting your HARDWARE PCB Designer.                                                                                                                                                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ======================================================================================================= */
/* ===========✔✔✔✔You Can CHANGE Inital Position angles"With some specifications"✔✔✔✔================ */

/* ========================================Movement Motor Pin Definitions*/
//$$$$$$$$MOTOR_1$$$$$$$$$$$$$$$$$$$
const int motor1_BST_LPwm = 22;    // I/O channel setup ESP32 pin
const int motor1_BST_RPwm = 21;    // I/O chennel setup ESP32 pin
const int motor1_En_LR    = 23;    // I/O pin for BST l_EN & R_EN (enable)
//$$$$$$$$MOTOR_2$$$$$$$$$$$$$$$$$$$
const int motor2_BST_LPwm = 4;    // I/O channel setup ESP32 pin
const int motor2_BST_RPwm = 15;    // I/O chennel setup ESP32 pin
const int motor2_En_LR    = 5;    // I/O pin for BST l_EN & R_EN (enable)

//- - - - - - - - - - Speed inital values - - - - - - - - - -
int Speed = 255 ;

/* ========================================Servo Motors Pin Definitions "Select only PWM Pins(GPIOs 34 to 39 can’t generate PWM)"*/
const int pinServo_1 = 13;  // Motor 1 pin 13
const int pinServo_2 = 12;  // Motor 2 pin 12
const int pinServo_3 = 14;  // Motor 3 pin 14
const int pinServo_4 = 27;  // Motor 4 pin 27
const int pinServo_5 = 26;  // Motor 5 pin 26


/* ========================================Set Inital Position angle for the Servo motors*/
int servo1Pos = 90; // Initial position for Servo 1
int servo2Pos = 90; // Initial position for Servo 2
int servo3Pos = 90; // Initial position for Servo 3
int servo4Pos = 90; // Initial position for Servo 4
int servo5Pos = 90; // Initial position for Servo 5
int servo6Pos = 90; // Initial position for Servo 6


/* ======================================== Access Point Declaration and Configuration. */
const char AP_NameChar[] = "Mazinger Robot"; //--> access point name
const char WiFiPassword[] = "AwadinBOT";     //--> access point password

/* ======================================================================================================= */
