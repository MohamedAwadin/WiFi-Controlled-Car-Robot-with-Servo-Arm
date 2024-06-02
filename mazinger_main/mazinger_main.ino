//>>>>>>>>>>>>>>>>>>>>>>>>>A Mazinger Main File<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : mazinger_main.ino                                        *********************/
/*******************  Layer          : Application (RUNNABLE&SETUP)                             *********************/
/*******************  Project        : 4-Wheel RC Robot Car with (3 Joints)ARM                  *********************/
/*******************  Microcontroller: ESP-32 DevelopmentKIT                                    *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/



/*
   Reference :
   - ESP32 information                                     : https://en.wikipedia.org/wiki/ESP32
   - Installing ESP32 Add-on in Arduino IDE (json)         :  >> File -> Preferance -> Additlonal Boards Manager URLs: {Paste this Link}
                                                              https://dl.espressif.com/dl/package_esp32_index.json

   - ESP32Servo (Author: Kevin Harrington,John K. Bennett) : - https://www.arduino.cc/reference/en/libraries/esp32servo/
                                                             - https://github.com/madhephaestus/ESP32Servo

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                            IMPORTANT INFORMATION                                                                                 //
//                                                                            ---------------------                                                                                 //
//                                                                                                                                                                                  //
// > This project uses ESP32-Development Board, BTS7960B Motor Driver Module, Servo (5 pieces) and DC Motor (4 pieces).                                                             //
// > ESP32 work as an access point, which creates its own Wi-Fi network and nearby Wi-Fi devices (stations) can connect to it (like your smartphone or your computer).              //
//                                                                                                                                                                                  //
// > I suggest that every time you upload the program code to the ESP32, make sure that the switch that connects the Power Supply to the BTS7960B Motor Driver Module is off        //
//   (OFF/0). Then if the process of uploading the program code to the ESP32 is complete, you can change the switch to on (ON/1).                                                   //
//   I suggest this because from what I experienced, if the switch is on when uploading the program code to the ESP32, the DC Motor will spin.                                      //
//                                                                                                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* ==================================================================== */
/* ===========❌❌❌❌DON'T CHANGE ANY THING HERE❌❌❌❌================ */
/* ======================================== Including the libraries. */
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESP32Servo.h>

/* ======================================== */
#include "PageIndex.h"            //--> Include the contents of the User Interface Web page, stored in the same folder as the .ino file
#include "Config_File.h"      //--> Include the contents of the pins configuration which you use, stored in the same folder as the .ino file
#include "Motors_ControlFunc.h"  //--> Include the contents of the motors control functions, stored in the same folder as the .ino file
/* ======================================== */
WiFiServer server(80);
String request = "";

// Create Servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
/* ==================================================================== */


void setup() {
  //>>>>>>>>>>> Setup code, to run once<<<<<<<<<<<<<<<
  /* ==================================================================== */
  /* ===========❌❌❌❌DON'T CHANGE ANY THING HERE❌❌❌❌================ */

  /* Initialize motor Movement control */
  move_init_setup();

  /* Attach servo objects to respective pins*/
  servo1.attach(pinServo_1);
  servo2.attach(pinServo_2);
  servo3.attach(pinServo_3);
  servo4.attach(pinServo_4);
  servo5.attach(pinServo_5);

  /*Set initial servo positions*/
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);
  servo3.write(servo3Pos);
  servo3.write(servo4Pos);
  servo3.write(servo5Pos);

  /* Start WiFi Access Point */
  boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);         // Start Access Point with specified credentials
  Serial.begin(115200);                                         //  Initialize serial communication
  IPAddress espIP = WiFi.softAPIP();                           //   Get IP address of the Access Point
  Serial.print("IP address(SEARCH FOR IT IN ANY BROWSER): "); //    Print message
  Serial.println(espIP);                                     //     Print IP address
  server.begin();                                           //      Start WiFi server
  Serial.println(WiFi.softAPIP());                         //       Print IP address again

  /* ==================================================================== */
  /* ==================================================================== */
}

void loop() {
  //>>>>>>>>>>> LOOP main code, to run repeatedly:<<<<<<<<<<<<<<<
  /* ==================================================================== */
  /* ===========❌❌❌❌DON'T CHANGE ANY THING HERE❌❌❌❌================ */

  /*Handle incoming client requests*/
  WiFiClient client = server.available();  // Check for incoming client connections
  if (!client) {// If no client is available
    return;// Exit the loop
  }

  /*Read HTTP request*/
  request = client.readStringUntil('\r'); // Read the request until carriage return
  client.flush();// Clear the client buffer

  /* Motor movement and servo control based on request*/
  if (request.indexOf("FORWARD") > 0) { // If the request contains "FORWARD"
    moveForward(); // Call function to move car forward
  }
  else if (request.indexOf("BACKWARD") > 0) { // If the request contains "BACKWARD"
    moveBackward(); // Call function to move car backward
  }
  else if (request.indexOf("RIGHT") > 0) { // If the request contains "RIGHT"
    turnRight(); // Call function to turn car right
  }
  else if (request.indexOf("LEFT") > 0) { // If the request contains "LEFT"
    turnLeft(); // Call function to turn car left
  }
  else if (request.indexOf("STOP") > 0) { // If the request contains "STOP"
    car_stop(); // Call function to turn car left

  }
  else if (request.indexOf("updateServo1") > 0) { // If the request contains "updateServo1"
    int value = getValueFromRequest(request, "value"); // Get servo value from request
    servo1.write(value); // Set servo 1 position
    servo1Pos = value; // Update servo 1 position variable
  } else if (request.indexOf("updateServo2") > 0) { // If the request contains "updateServo2"
    int value = getValueFromRequest(request, "value"); // Get servo value from request
    servo2.write(value); // Set servo 2 position
    servo2Pos = value; // Update servo 2 position variable
  } else if (request.indexOf("updateServo3") > 0) { // If the request contains "updateServo3"
    int value = getValueFromRequest(request, "value"); // Get servo value from request
    servo3.write(value); // Set servo 3 position
    servo3Pos = value; // Update servo 3 position variable
  }
  else if (request.indexOf("updateServo4") > 0) {// If the request contains "updateServo4"
    int value = getValueFromRequest(request, "value");// Get servo value from request
    servo4.write(value);// Set servo  4 position
    servo4Pos = value;// Update servo 4 position variable
  } else if (request.indexOf("updateServo5") > 0) {// If the request contains "updateServo5"
    int value = getValueFromRequest(request, "value");// Get servo value from request
    servo5.write(value);// Set servo  5 position
    servo5Pos = value;// Update servo 5 position variable
  }
  /*Send HTML response to client*/
  client.print(header);
  client.print(html_1);
  client.print(css);
  client.print(html_2);
  client.print(html_3);
  client.print(html_4);
  client.print(html_5);
  client.print(html_6);
  client.print(html_7);
  client.print(html_8);
  client.print(html_9);
  client.print(html_10);
  client.print(html_11);
  client.print(html_12);
  client.print(html_13);
  client.print(html_14);
  client.print(js);
  client.print(html_15);

  delay(5);// Delay for stability
  /* ==================================================================== */
  /* ==================================================================== */
}

/* ==================================================================== */
/* ===========❌❌❌❌DON'T CHANGE ANY THING HERE❌❌❌❌================ */
/* Function to extract value from HTTP request*/
int getValueFromRequest(String request, String param) {
  int start = request.indexOf(param + "=") + param.length() + 1;
  int end = request.indexOf(" ", start);
  return request.substring(start, end).toInt();
}
/* ==================================================================== */
