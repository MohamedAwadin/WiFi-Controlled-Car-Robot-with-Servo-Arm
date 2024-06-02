//>>>>>>>>>>>>>>>>>>>>>>>>>Mazinger: HTML Control Web Page File<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                          *********************/
/*******************  FILE NAME      : PageIndex.h                                             *********************/
/*******************  Layer          : Application_Service(PRIVATE)                            *********************/
/*******************  Project        : 4-Wheel RC Robot Car with (3 Joints)ARM                 *********************/
/*******************  Microcontroller: ESP-32 DevelopmentKIT                                   *********************/
/*******************  Version        : 1.00                                                    *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/* ==================================================================== */
/* ===========❌❌❌❌DON'T CHANGE ANY THING HERE❌❌❌❌================ */



String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = "<!DOCTYPE html><html><head><title>Mazinger Robot Control</title><style>";
String css = "body { font-family: Arial, sans-serif; text-align: center; }"
             "#main { display: inline-block; border: 2px solid #000; padding: 20px; }"
             ".button { display: inline-block; margin: 10px; padding: 15px 25px; font-size: 16px; }"
             "#movement { display: grid; grid-template-areas: 'left forward right' 'backward backward backward'; grid-gap: 10px; }"
             "#movement #F1 { grid-area: forward; }"
             "#movement #F2 { grid-area: backward; }"
             "#movement #F3 { grid-area: right; }"
             "#movement #F4 { grid-area: left; }"
             "#servos { margin-top: 20px; }"
             ".slider { width: 80%; }";
String html_2 = "</style></head><body><div id='main'><h2>Mazinger Robot Control</h2><div id='movement'>";
String html_3 = "<form id='F1' action='FORWARD'><input class='button' type='submit' value='CAR FORWARD' ></form>";
String html_4 = "<form id='F2' action='BACKWARD'><input class='button' type='submit' value='CAR BACKWARD' ></form>";
String html_5 = "<form id='F3' action='RIGHT'><input class='button' type='submit' value='CAR RIGHT' ></form>";
String html_6 = "<form id='F4' action='LEFT'><input class='button' type='submit' value='CAR LEFT' ></form>";
String html_7 = "<form id='F5' action='STOP'><input class='button' type='submit' value='CAR STOP' ></form>";
String html_8 = "</div><div id='servos'>";
String html_9 = "<h3>Servo 1 Control</h3><input type='range' id='servo1' min='0' max='180' value='90' class='slider' oninput='updateServo(this.value, 1)'><span id='servo1Val'>90</span>";
String html_10 = "<h3>Servo 2 Control</h3><input type='range' id='servo2' min='0' max='180' value='90' class='slider' oninput='updateServo(this.value, 2)'><span id='servo2Val'>90</span>";
String html_11 = "<h3>Servo 3 Control</h3><input type='range' id='servo3' min='0' max='180' value='90' class='slider' oninput='updateServo(this.value, 3)'><span id='servo3Val'>90</span>";
String html_12 = "<h3>Servo 4 Control</h3><input type='range' id='servo4' min='0' max='180' value='90' class='slider' oninput='updateServo(this.value, 4)'><span id='servo4Val'>90</span>";
String html_13 = "<h3>Servo 5 Control</h3><input type='range' id='servo5' min='0' max='180' value='90' class='slider' oninput='updateServo(this.value, 5)'><span id='servo5Val'>90</span>";
String html_14 = "</div><script>";
String js = "function updateServo(value, servo) {"
            "  var xhr = new XMLHttpRequest();"
            "  xhr.open('GET', '/updateServo' + servo + '?value=' + value, true);"
            "  xhr.send();"
            "  document.getElementById('servo' + servo + 'Val').innerText = value;"
            "}";
String html_15 = "</script></div></body></html>";


/* ==================================================================== */
/* ==================================================================== */
