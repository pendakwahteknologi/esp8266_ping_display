# esp8266_ping_display
A simple application to display ping (ICMP) results of servers using ESP8266 connected to a MAX7219 Dot Matrix Module 4-in-1 Display.

Required Hardware
-----------------
- 1 unit of ESP8266 Node MCU
- 1 unit of MAX7219 Dot Matrix Module 4-in-1 Display
- Jumper Wires
- Breadboard (optional)
- USB Cable for programming and power

Required Software & Libraries
-----------------------------
- Arduino IDE
- ESP8266 Arduino Library (https://github.com/esp8266/Arduino)
- MD_Parola (https://github.com/MajicDesigns/MD_Parola) libraries
- MD_MAX72xx (https://github.com/MajicDesigns/MD_MAX72XX) libraries
- theSwedishMaker.h - Custom fonts for the dot matrix display made by https://github.com/TheSwedishMaker

Installing the NodeMCU Driver drivers for macOS & Windows
-------------------
The first step on the mac is to install drivers. Go to https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers

For macOS
1. For macOS, select the CP210x VCP Mac OSX Driver
2. Double click on SiLabsUSBDriverDisk.dmg 
3. Double click on Silicon Labs VCP Driver Install Disk.pkg
4. Click on Continue
5. Finish installation

For Windows
1. For Windows, select the CP210x VCP Windows
2. Double click on the CP210xVCPInstaller_x64.exe or CP210xVCPInstaller_x86.exe (depending on your system architecture)
3. Click on Continue
4. Finish installation

How to use ESP8266 with Arduino IDE
-----------------------
To install the ESP8266 board in your Arduino IDE, follow these next instructions:
1. In your Arduino IDE, go to File> Preferences
2. Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into the “Additional Boards Manager URLs” field. Then, click the “OK”
3. Open the Boards Manager. Go to Tools > Board > Boards Manager
4. Search for ESP8266 and press install button for the “ESP8266 by ESP8266 Community“
5. That’s it. It should be installed after a few seconds.
(Source: https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)

To use the code
---------------
- Enter your Wi-Fi SSID and Wi-Fi password at the marked location in the file.
- Change the domain/server that you wish to ping.

Know Issues
------------
Users of macOS BigSur getting the following error when trying to upload the sketch to the esp8288 via the Arduino IDE.
"pyserial or esptool not found next to this upload.py tool" 

Solution:
1. Download https://github.com/espressif/esptool/archive/v3.0.zip
2. Download https://github.com/pyserial/pyserial/archive/v3.4.zip
3. Extract the contents to esptool/ and pyserial/ in the ~/Library/Arduino15/packages/esp8266/hardware/esp8266/2.7.4/tools/ folder (an equivalent must exist on Windows)
(Source: https://www.esp8266.com/viewtopic.php?p=89446)
