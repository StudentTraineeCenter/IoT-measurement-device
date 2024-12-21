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
1. Connect these sensors/motor to arduino board. Set it up based on the sketch:  
   -DHT11  
   -soil moisture sensor  
   -servo motor  
   -3 different coloured LEDs  
If you don't have these sensors/motors or you want to use some other the scetch must be changed.

### Setup Azure IoT Central app  
1. Create a resource group
2. Create an IoT Central Application
3. In the project details select *Custom application* template and hit create
4. Open the application. On the left tab go to *Devices* and add new.
5. Now go to *Device templates* and create new *IoT device* template. Check the *This is a gateway device* box. Hit Create.
6. Add capability to the device template. You can ad as much as you would like. Those will display the data that are beeing collected by your device:
![image](https://github.com/user-attachments/assets/0643d5f9-1d3b-4b8a-bb9a-391cab0bb62c)
You must fill out *Relationship* before saving and dont forget the *View*. This will determine how your data will be displayed(*pine chart, bar chart....*)
7. Now go back to *Devices* and assing this template to your device

### Bridge setup
1. Whe you have setted up your AZ IoT app go to *Devices* and open your device.
2. Click connect.
3. There you can see **ID scope, Device ID, auth type, Device key**
4. Select SAS authentication acces type.
5. Copy and paste these properties - **ID scope, Device ID, Device key** into their respective locations in the bridge script.
![image](https://github.com/user-attachments/assets/19c88dff-5658-4726-bc91-145fb58a6a97)



