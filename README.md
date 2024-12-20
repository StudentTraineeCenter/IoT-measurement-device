# IoT-measurement-device

## Introduction
Measurement device for plants and its enviroment

## Getting Started  
### Prerequisites
Before you begin, ensure you have installed Arduino IDE and made Azure account:  
-[Arduino IDE](https://pages.github.com/)  
-[Azure](https://azure.microsoft.com/en-us/)
### Installation  
1. Navigate to the place where you want the app to be downloaded in Command Prompt.
2. Clone the repository: git clone https://github.com/StudentTraineeCenter/IoT-measurement-device

Arduino
Wire your sensor (e.g., DHT11/DHT22) to the Arduino.
Upload a sketch to the Arduino that:
Reads sensor data.
Prints it via the Serial.print function. 


Here’s a quick and stylized README file for your GitHub project:

Arduino to Azure IoT Central Bridge



This project demonstrates how to connect an Arduino Uno R3 (connected via USB to a PC) to Azure IoT Central using a Python bridge script. The bridge reads sensor data from the Arduino over a serial connection and sends it to Azure IoT Central using the Device Provisioning Service (DPS).

Features
Reads temperature and humidity data from sensors connected to an Arduino Uno R3.
Sends real-time telemetry data to Azure IoT Central using a Python script.
Uses Azure IoT DPS for secure provisioning and connection.
Requirements
Hardware
Arduino Uno R3 (or a compatible clone).
A sensor module (e.g., DHT11/DHT22) for temperature and humidity.
USB cable for PC connection.
Software
Python 3.x installed on your PC.
Azure IoT Central account and application setup.
Libraries to install:
bash
Kopírovať kód
pip install azure-iot-device pyserial
Setup Instructions
Arduino
Wire your sensor (e.g., DHT11/DHT22) to the Arduino.
Upload a sketch to the Arduino that:
Reads sensor data.
Prints it via the Serial.print function.
Python Script
Clone this repository:

bash
Kopírovať kód
git clone https://github.com/yourusername/arduino-azure-bridge.git
Update the Python script with your Azure IoT Central settings:

ID_SCOPE
DEVICE_ID
DEVICE_KEY
Run the script:

How It Works
The Python script:
Registers the device with Azure IoT Central using DPS.
Connects to Azure IoT Hub after successful provisioning.
Reads data from the Arduino via the serial port.
Sends data as telemetry messages to Azure IoT Central.
Azure IoT Central:
Visualizes the incoming data with real-time graphs and dashboards
