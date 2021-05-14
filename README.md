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

To use the code
---------------
- Enter your Wifi SSID and password at the marked location in the file. 
- Change the domain/server that you wish to ping.

Know Issues
------------
1) Users of macOS BigSur getting the following error:
"pyserial or esptool not found next to this upload.py tool"

Solution:
1. Download https://github.com/espressif/esptool/archive/v3.0.zip
2. Download https://github.com/pyserial/pyserial/archive/v3.4.zip
3. Extract the contents to esptool/ and pyserial/ in the ~/Library/Arduino15/packages/esp8266/hardware/esp8266/2.7.4/tools/ folder (an equivalent must exist on Windows)
(Source: https://www.esp8266.com/viewtopic.php?p=89446)
