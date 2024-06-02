# WiFi-Controlled Car Robot with Servo Arm

## Overview
This project features a WiFi-controlled car robot equipped with an arm that has five servo motors. The robot is controlled via a web interface, allowing users to navigate the car and manipulate the servos easily.

## Features
- **WiFi Connectivity**: Remote control via a web interface.
- **Car Movement**: Control forward, backward, left, right, and stop.
- **Servo Control**: Adjust the angles of five servo motors using sliders.
- **User-Friendly Interface**: Intuitive web page for seamless control.

## Components
- **ESP32**: For WiFi and web server.
- **DC Motors**: For car movement.
- **Servo Motors**: Five servos for the arm.
- **HTML, CSS, JavaScript**: For the web interface.

## Setup and Installation
### Hardware Setup
1. Connect DC motors and servos to ESP32 pins.
2. Ensure an adequate power supply.

### Software Setup
1. Install necessary libraries (WiFi, AsyncTCP, Servo) in the Arduino IDE.
2. Upload `CarRobotWithServoArm.ino` to the ESP32.

### Running the Project
1. Connect to the ESP32's WiFi network.
2. Open a web browser and navigate to the ESP32's IP address.

## Usage
1. Connect to the ESP32's WiFi network.
2. Open the web browser and enter the IP address displayed on the serial monitor.
3. Use the web interface to control the car and adjust servo angles.

## Code Structure
**1-mazinger_main.ino**
The `main_code.ino` file serves as the main program file for the Mazinger project, responsible for coordinating the functionality of the robot, including motor movement, servo control, and handling client requests via a web interface. Here's a structured overview of its contents:

1. **File Information**: Provides essential details about the author, file name, layer, project name, microcontroller used, and version.

2. **Dependencies**: Includes necessary libraries for WiFi communication (`WiFi.h`), asynchronous TCP communication (`AsyncTCP.h`), and servo motor control (`ESP32Servo.h`).

3. **Global Variables and Objects**: Declares global variables, such as a `WiFiServer` object for handling client connections and a string variable for storing client requests.

4. **Setup Function**: Initializes the hardware and establishes the WiFi access point. This function also attaches servo objects to their respective pins and sets their initial positions.

5. **Loop Function**: Continuously loops to handle incoming client requests. It reads HTTP requests from clients, processes them to control motor movement and servo angles, and sends HTML responses back to clients to update the web interface.

6. **Helper Functions**: Includes a helper function to extract values from HTTP requests, used for updating servo positions based on client inputs.

**2- Config_File.h:**
The Config_File.h file serves as a configuration file for the Mazinger project, providing an organized setup for various parameters related to pin assignments, initial servo positions, and WiFi access point details. Here's a breakdown of its components:

-  **Motor and Servo Pin Definitions:** Defines the GPIO pins used to control the motors and servo motors. It includes definitions for each motor's BST (Brushed DC Motor) control pins and PWM (Pulse Width Modulation) pins for servo motors.

-  **Initial Position for Servo Motors:** Sets the initial positions (angles) for each servo motor upon startup. These values determine the starting orientation of the servo motors.

-  **Access Point Configuration:** Specifies the name and password for the WiFi access point created by the ESP32. This allows nearby devices to connect to the ESP32 as an access point for controlling the robot.

**2- Motors_ControlFunc.h**
The Motors_ControlFunc.h file contains functions responsible for controlling the movement of motors in the Mazinger project. Here's a structured description of its contents:

1. **Channel Assignments**: Defines PWM channels for controlling the motors connected via BTS7960 High Current H-Bridge Motor Driver. Each motor has dedicated PWM channels for controlling its speed and direction.

2. **Initialization Setup Function**: `move_init_setup()` initializes the PWM channels and assigns them to the corresponding motor control pins. This function sets up the environment necessary for motor control operations.

3. **Motor Control Functions**:
   - `car_stop()`: Stops all motor movement by setting the PWM values to zero.
   - `moveForward()`: Moves the robot car forward by activating the appropriate PWM channels and adjusting the motor speed.
   - `moveBackward()`: Moves the robot car backward by activating the necessary PWM channels and adjusting the motor speed.
   - `turnRight()`: Turns the robot car right by controlling the PWM channels for differential steering.
   - `turnLeft()`: Turns the robot car left by controlling the PWM channels for differential steering.

**4- PageIndex.h:** 
The `PageIndex.h` file contains the HTML code for the user interface web page of the Mazinger project. Here's a breakdown of its components:

1. **HTML Structure**: Defines the basic structure of the HTML page, including the `<!DOCTYPE>` declaration, `<html>`, `<head>`, and `<body>` tags.

2. **CSS Styling**: Includes CSS styling rules to format the appearance of the web page. It defines the font family, text alignment, button styles, and layout for the movement controls and servo sliders.

3. **Movement Control Buttons**: Defines HTML forms for the movement control buttons of the robot, including forward, backward, right, left, and stop. Each form contains an input element with a submit button that triggers the corresponding action when clicked.

4. **Servo Control Sliders**: Sets up sliders for controlling the servo motors. Each slider input element is associated with a specific servo motor, allowing users to adjust the servo angle by dragging the slider.

5. **JavaScript Functionality**: Contains JavaScript code to handle the dynamic updating of servo positions when the sliders are adjusted. It sends HTTP requests to the ESP32 server with the updated servo positions, allowing real-time control of the servos.



## Repository Structure
WiFi-Controlled-Car-Robot/
├── README.md
├── Arduino_Code/
│ └── mazinger_main.ino
| └── Config_File.h
| └── Motors_ControlFunc.h
| └── PageIndex.h
├── Images/
│ └── Interface.png
└── Documentation/
└── SetupGuide.md


## License
This project is licensed under the MIT License.
