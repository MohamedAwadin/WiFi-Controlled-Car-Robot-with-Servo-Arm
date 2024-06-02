//>>>>>>>>>>>>>>>>>>>>>>>>>Mazinger: Motors control File<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author    : Mohamed Awadin                                               *********************/
/*******************  FILE NAME : Motors_ControlFunc.h                                         *********************/
/*******************  Layer     : HAL(PRIVATE)                                                 *********************/
/*******************  Project   : 4-Wheel RC Robot Car with (3 Joints)ARM                      *********************/
/*******************  Microcontroller: ESP-32 DevelopmentKIT                                   *********************/
/*******************  Version: 1.00                                                            *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/*
   Reference :
   - ESP32 PWM with Arduino IDE (Analog Output) : https://randomnerdtutorials.com/esp32-pwm-arduino-ide/
   - BTS7960 DataSheet : https://www.handsontec.com/dataspecs/module/BTS7960%20Motor%20Driver.pdf
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                            IMPORTANT INFORMATION                                                                                 //
//                                                                            ---------------------                                                                                 //
//                                                                                                                                                                                  //
// > This Hardware File to Run BTS7960 High Current 43A H-Bridge Motor Driver.                                                                                                      //
// > BTS7960 Pin 3 (R_EN), 4 (L_EN) connected in the same Digital I/O Pin                                                                                                           //
// > BTS7960 Pin 5 (R_IS) and 6 (L_IS) not connected                                                                                                                                // 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ==================================================================== */
/* ==================================================================== */
/* ===========❌❌❌❌DON'T CHANGE ANY THING HERE❌❌❌❌================ */
//- - - - - - - - - - channel assignments - - - - - - - - - -
const int  motor1_LPwm_Channel_5 = 5;   // & PWM channel 5, for Motor1 BST pin L_PWM
const int  motor1_RPwm_Channel_6 = 6;   // & PWM channel 6, for Motor1 BST pin R_PWM
const int  motor2_LPwm_Channel_7 = 7;   // & PWM channel 7, for Motor2 BST pin L_PWM
const int  motor2_RPwm_Channel_8 = 8;   // & PWM channel 8, for Motor2 BST pin R_PWM
//- - - - - - - - - - Channel Variables  - - - - - - - - - -
const int freq = 1000;      //  Set up PWM Frequency
const int  res = 8;         //  Set up PWM Resolution"8-bit"


void move_init_setup(void) {
  //- - - - - - - - - - Motor1_init_Funcs  - - - - - - - - - -
  ledcSetup(     motor1_LPwm_Channel_5, freq, res);               // setup PWM channel_5 for Motor1 BST L_PWM
  ledcSetup(     motor1_RPwm_Channel_6, freq, res);              // setup PWM channel_6 for Motor1 BST R_PWM
  ledcAttachPin( motor1_BST_LPwm , motor1_LPwm_Channel_5); // Attach Motor1 BST R_PWM
  ledcAttachPin( motor1_BST_RPwm , motor1_RPwm_Channel_6);// Attach Motor1 BST R_PWM
  pinMode(motor1_En_LR , OUTPUT);                        // declare motor1_En_LR pin as output
 
  //- - - - - - - - - - Motor2_init_Funcs  - - - - - - - - - -
  ledcSetup(     motor2_LPwm_Channel_7, freq, res);               // setup PWM channel_7 for Motor2 BST L_PWM
  ledcSetup(     motor2_RPwm_Channel_8, freq, res);              // setup PWM channel_8 for Motor2 BST R_PWM
  ledcAttachPin( motor2_BST_LPwm , motor2_LPwm_Channel_7); // Attach Motor2 BST L_PWM
  ledcAttachPin( motor2_BST_RPwm , motor2_RPwm_Channel_8);// Attach Motor2 BST R_PWM
  pinMode(motor2_En_LR , OUTPUT);                        // declare motor2_En_LR pin as output

  
}
//Function to Stop the car
void car_stop() {
  //----------- enable En_LR------------
  digitalWrite(motor1_En_LR, HIGH); // enable motor1_En_LR
  digitalWrite(motor2_En_LR, HIGH); // enable motor2_En_LR

  //----------------------------------------
  ledcWrite(motor1_LPwm_Channel_5, 0);      // stop channel 5  (Motor1_L_PWM)
  ledcWrite(motor1_RPwm_Channel_6, 0);     // stop channel  6   (Motor1_R_PWM)
  
  ledcWrite(motor2_LPwm_Channel_7, 0);    // stop channel   7    (Motor2_L_PWM)
  ledcWrite(motor2_RPwm_Channel_8, 0);   // stop channel    8     (Motor2_R_PWM)
}

//Function to move the car forward
void moveForward() {
  //----------- enable En_LR------------
  digitalWrite(motor1_En_LR, HIGH); // enable motor1_En_LR
  digitalWrite(motor2_En_LR, HIGH); // enable motor2_En_LR

  //----------------------------------------
  ledcWrite(motor1_LPwm_Channel_5, Speed);      // Run channel 5  (Motor1_L_PWM) at "Speed"
  ledcWrite(motor1_RPwm_Channel_6, 0);         // stop channel 6   (Motor1_R_PWM)
  
  ledcWrite(motor2_LPwm_Channel_7, Speed);    // Run channel   7    (Motor2_L_PWM) at "Speed"
  ledcWrite(motor2_RPwm_Channel_8, 0);       // stop channel   8     (Motor2_R_PWM)
}
//Function to move the car Backward
void moveBackward() {
  //----------- enable En_LR------------
  digitalWrite(motor1_En_LR, HIGH); // enable motor1_En_LR
  digitalWrite(motor2_En_LR, HIGH); // enable motor2_En_LR

  //----------------------------------------
  ledcWrite(motor1_LPwm_Channel_5, 0);              // Stop channel 5  (Motor1_L_PWM) 
  ledcWrite(motor1_RPwm_Channel_6, Speed);         // Run channel 6   (Motor1_R_PWM) at "Speed"
  
  ledcWrite(motor2_LPwm_Channel_7, 0);            // Stop channel   7    (Motor2_L_PWM) 
  ledcWrite(motor2_RPwm_Channel_8, Speed);       // Run channel   8     (Motor2_R_PWM)at "Speed"
}

//Function to move the car Right
void turnRight() {
  //----------- enable En_LR------------
  digitalWrite(motor1_En_LR, HIGH);  // enable motor1_En_LR
  digitalWrite(motor2_En_LR, HIGH); // enable motor2_En_LR

  //----------------------------------------
  ledcWrite(motor1_LPwm_Channel_5, Speed);              // Run channel 5  (Motor1_L_PWM) at "Speed"
  ledcWrite(motor1_RPwm_Channel_6, 0);                 // Stop channel 6   (Motor1_R_PWM) 
  
  ledcWrite(motor2_LPwm_Channel_7, 0);               // Stop channel   7    (Motor2_L_PWM) 
  ledcWrite(motor2_RPwm_Channel_8, Speed);          // Run channel   8     (Motor2_R_PWM)at "Speed"
}

//Function to move the car Left
void turnLeft() {
  //----------- enable En_LR------------
  digitalWrite(motor1_En_LR, HIGH);  // enable motor1_En_LR
  digitalWrite(motor2_En_LR, HIGH); // enable motor2_En_LR

  //----------------------------------------
  ledcWrite(motor1_LPwm_Channel_5, 0);              // Stop channel 5  (Motor1_L_PWM) 
  ledcWrite(motor1_RPwm_Channel_6, Speed);         // Run channel 6   (Motor1_R_PWM) at "Speed"
  
  ledcWrite(motor2_LPwm_Channel_7, Speed);       // Run channel   7    (Motor2_L_PWM) at "Speed"
  ledcWrite(motor2_RPwm_Channel_8, 0);          // Stop channel   8     (Motor2_R_PWM)
}
/* ====================================================================== */
/* ====================================================================== */
