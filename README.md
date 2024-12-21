# IoT-measurement-device

## Introduction
This project demostrates how to connect Arduino UNO R3 to Azure IoT Central app using python bridge script. Arduino gathers data like temperature, humidity and soil moisture. Then the data are beeing send via bridge to Azure IoT Central app where they are displayed. Data are beeing display real-time with delay that can be set to prefferences.

## Getting Started  
### Prerequisites
Before you begin, ensure you have installed Arduino IDE and made Azure account:  
-[Arduino IDE](https://pages.github.com/)  
-[Azure](https://azure.microsoft.com/en-us/)
### Installation  
1. Navigate to the place where you want the app to be downloaded in Command Prompt.
2. Clone the repository:  
   `git clone https://github.com/StudentTraineeCenter/IoT-measurement-device`
4. Install dependecies:  
   `pip install -r requirements.txt`
6. Upload the sketch to Arduino UNO R3 using Arduino IDE

### Connect Arduino  
1. Connect these sensors/motor to arduino board:  
   -DHT11  
   -soil moisture sensor  
   -servo motor  
   -3 different coloured LEDs  
If you don't have these sensors/motors or you want to use some other the scetch must be changed.

### Setup Azure IoT Central app  
1. Create a resource group
2. Create an IoT Central Application
### Bridge setup
