# pong-arduino
## Installation

To install the dependencies, run the following command:

```sh
pip install -r requirements.txt
```

## Project Description

This project is an implementation of the classic Pong game using Arduino as a Joystick. It involves setting up the hardware and writing the necessary code to control the game using Arduino components.

# Hardware Requirements
- Arduino board (e.g., Arduino Uno, Arduino Nano)
- ESP8266 WiFi module
- Breadboard
- Jumper wires
- Push buttons
- Computer with Arduino IDE installed

# Scheme of the Circuit

![Circuit Diagram](circuit.png)

# Software Requirements

The arduino and the computer should be connected to the same network. The IP address of the computer should be known to the arduino. The IP address of the computer can be found by running the following command in the terminal:

```sh
ipconfig
```

# How to Play

The buttons are used to control the paddle. The left button moves the paddle up, and the right button moves the paddle down. The objective is to hit the ball with the paddle and prevent it from hitting the wall behind the paddle. The game ends when the ball hits the wall, and the score is displayed on the screen.

