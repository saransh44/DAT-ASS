// Home Automation Tweeter Project by Geeve George
// Select these libraries from  Sketch>Import Libraries

#include <Dhcp.h>
#include <Dns.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include <SPI.h>
#include <Ethernet.h>

#include <Twitter.h>

void setup(){

// Code for initializing Serial Monitor Acess by hitting CTRL+SHIFT+M  

    Serial.begin(9600);
//Prints the analogValue of the sensor on A0 and displays in the Serial Monitor
         Serial.print(analogRead(0));
delay(1000);
Serial.print(analogRead(0));
delay(1000);
 
        
}

void loop(){

 
//Declaring the variable tweetMessage
        tweetMessage();
        delay(6000);
         
       
}

void tweetMessage(){
    Twitter twitter("3296303267-Z4TO6SMVXw0wgta6zxmClOIhIyViuUGd0fyXB7m");

   // replace 700 with your suitable value according to your surrounding light intensity

    if(analogRead(0)>300)
    {
    String stringMsg = "Value:";
    stringMsg += analogRead(0);
    stringMsg += " #LightON";
  
//Convert String to Char for posting on twitter
    char msg[140];
    stringMsg.toCharArray(msg, 140);


    twitter.post(msg);
    }
    else 
    {

    
      
      String stringMsg = "#LightOFF";
      stringMsg += "Value:";
      stringMsg += analogRead(0);
   
//Convert String to Char to post on twitter  
    char msg[140];
    stringMsg.toCharArray(msg, 140);

//posts to twitter!
    twitter.post(msg);
    }
      

  
}
