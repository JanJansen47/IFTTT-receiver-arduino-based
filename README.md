# IFTTT-receiver-arduino-based
Receives IFTTT notifications and switches output thereoff ( can be used with Google Assistant)

Hardware: ESP8266 nodemcu and three neopixels

Configuration:
1) SSID and SSID password and URL download server (OTA) are  stored in SPIFFS after first startup.
2) In case you never attached the esp8266 to a WiFi network you need to format  SPIFFS  first. You can do the by uncommenting 
SPIFFS.format(); (line 151) and run the program. Hereafter comment SPIFFS.format();
3) Load the program again and attach your tablet or pc to SSID  xxxxx with apssword 12345678.
4) in your browser go to 192.168.4.1
5) fill in your SSID and SSID password. If you want to use OTA fill in your OTA URL. 
6) finish and restart the esp8266

Usage:
Get an IFTTT account and create your own If This Than That service.  The receiver is used in the "That" part of the IFTTT.
For example used the Webhook for the This action and also another Webhook, that makes the webrequest  for the That action.
Under URL you need to fill in 
URL
    http://????????:777/SagA2_off
Thats all.

As you have three outputs you can also use SagA2_on, SagA1_off,SagA2_on, SagA3_off, SagA3_on

The three neopixels show the state of the output.





