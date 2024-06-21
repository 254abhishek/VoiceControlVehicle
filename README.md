# Arduino Robot Control with Ultrasonic Sensor and Serial Commands

This Arduino sketch enables basic control of a robot using an ultrasonic sensor for obstacle detection and serial commands for directional control.

## Table of Contents

- [Overview](#overview)
- [Setup](#setup)
- [Usage](#usage)
- [Serial Commands](#serial-commands)
- [License](#license)

## Overview

This project uses an Arduino board to control four relays connected to a robot's motors for directional movement (forward, backward, left, right, and stop). An ultrasonic sensor (HC-SR04) is employed to detect obstacles in front of the robot, ensuring safe operation.

## Setup

### Components Required
- Arduino board (e.g., Arduino Uno)
- HC-SR04 Ultrasonic Sensor
- Four-channel relay module
- Robot chassis with motors

### Wiring Diagram
- **Relay Connections**:
  - `relay1` to `relay4` connected to the robot motors.
- **Ultrasonic Sensor**:
  - `trigPin1` connected to the trigger pin of the HC-SR04.
  - `echoPin1` connected to the echo pin of the HC-SR04.

### Arduino IDE Setup
1. Connect your Arduino board to your computer.
2. Open the Arduino IDE.
3. Copy and paste the provided sketch into a new sketch in the Arduino IDE.
4. Verify and upload the sketch to your Arduino board.

## Usage

1. **Power on your Arduino board and the robot setup**.
2. **Monitor the Serial Monitor** (set to 9600 baud rate) for status updates and debug messages.
3. **Send commands** using the Serial Monitor or any serial communication software to control the robot:
   - Commands:
     - `*forward#`: Move the robot forward.
     - `*backward#`: Move the robot backward.
     - `*right#`: Turn the robot right.
     - `*left#`: Turn the robot left.
     - `*stop#`: Stop all movement of the robot.

4. **Observe** how the robot reacts to obstacles detected by the ultrasonic sensor, automatically stopping when an obstacle is detected within 10 cm.

## Serial Commands

- **Command Format**: Each command should be sent in the format `*command#`.
- **Available Commands**:
  - `*forward#`: Move the robot forward.
  - `*backward#`: Move the robot backward.
  - `*right#`: Turn the robot right.
  - `*left#`: Turn the robot left.
  - `*stop#`: Stop all movement of the robot.

## License

This project is licensed under the [MIT License](LICENSE).
