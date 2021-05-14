
//################# LIBRARIES ########################################################
#include <MD_Parola.h>       // https://github.com/MajicDesigns/MD_Parola
#include <MD_MAX72xx.h>      // https://github.com/MajicDesigns/MD_MAX72XX
#include <ESP8266WiFi.h>     // Library to enable Wi-Fi on ESP8266
#include <ESP8266Ping.h>     // Library to enable Ping on ESP8266
#include "theSwedishMaker.h" // This header was made by TheSwedishMaker for his 
                             // ESP8266-SUB-COUNTER project
//####################################################################################

//################# DISPLAY CONNECTIONS ##############################################
// Define the typ of hardware and the pins used.
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   12
#define DATA_PIN  15
#define CS_PIN    13

// Connect the software to the hardware (dot matrix display) using the MD_MAX72XX class
MD_Parola Display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
//####################################################################################

//################# Wi-Fi SETTINGS ##############################
const char* ssid     = "Your Wi-Fi SSID";      // SSID of local network
const char* password = "Your Wi-Fi Password";  // Password on network
//###############################################################

//################# DOMAIN TO PING ############################################
const char* domain = "google.com";     // Will ping google.com in this example
//#############################################################################

void setup() // Used to initialize variables, pin modes, start using libraries, etc. 
             // The setup() function will only run once, after each powerup or reset of the Arduino board.
{
  Serial.begin(115200);           // Display the maximum ping time on the Dot Matrix display
  
  Display.begin();                // Initialize the object.
  Display.setFont(fontSubs);      // Set the display font to use theSwedishMaker fonts

  // Wi-Fi Connection
  Serial.print("Connecting WiFi ");        // Display message on serial output
  WiFi.begin(ssid, password);              // Connect to Wi-Fi SSDI with password
  Display.print(" Wi-Fi...");              // Display message on the MAX7219 Dot Matrix Module 4-in-1 Display
  while (WiFi.status() != WL_CONNECTED) {  // While waiting for Wi-Fi connection...
    Serial.print(".");                     // Display dots on serial output
    delay(500);
  }
  Serial.println("");                     // Set new line on serial output
  Serial.print("Connected: "); Serial.println(WiFi.localIP());  // After successfully connecting to Wi-Fi, display message and IP address
  Display.print(" Wi-Fi Ok");                                   // Display message on the MAX7219 Dot Matrix Module 4-in-1 Display
}

void loop(void)  // The loop() function does precisely what its name suggests, and loops consecutively, 
                 // allowing your program to change and respond
{

//Start Ping
  if(Ping.ping(domain))                  // If ping is successful then..
    { 
      int pingMin = Ping.minTime();      // input is in integer format
      int pingMax = Ping.maxTime();      // input is in integer format
      int pingAvg = Ping.averageTime();  // input is in integer format
      Display.print("Google");                      //display 'Google' on the MAX7219 Dot Matrix Module 4-in-1 Display
      delay(2000);                                  // Wait 2000 ms @ 2 sec before continuing
      Display.print("Min:"+String(pingMin)+"ms");   // Display the minimmum ping time on the Dot Matrix display
      delay(2000);                                  // Wait 2000 ms @ 2 sec before continuing
      Display.print("Max:"+String(pingMax)+"ms");   // Display the maximum ping time on the Dot Matrix display
      delay(2000);                                  // Wait 2000 ms @ 2 sec before continuing
      Display.print("Avg:"+String(pingAvg)+"ms");   // Display the average ping time on the Dot Matrix display
    } else {                            // If ping is not successful then..                               
      Display.print("Google");          // Display the word 'Google' on the MAX7219 Dot Matrix Module 4-in-1 Display
      delay(1500);                      // Wait 1500 ms @ 1.5 sec before continuing
      Display.print("Ping Error");      // Display 'Ping Error' on the MAX7219 Dot Matrix Module 4-in-1 Display
   }

}
