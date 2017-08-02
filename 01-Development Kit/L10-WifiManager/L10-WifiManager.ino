#include <ESP8266WiFi.h>         
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#define ACCESSPOINT_NAME  "MyAccesspoint"

WiFiManager wifiManager;
int LEDPIN = D0;
int SWPIN  = D7;

void setup(){
  pinMode(LEDPIN, OUTPUT);
  pinMode(SWPIN, INPUT);
  Serial.begin(115200);
  
  if(!digitalRead(SWPIN)){
    wifiManager.resetSettings();
  }
  
  wifiManager.autoConnect(ACCESSPOINT_NAME);
  Serial.println("connected... :)");
  digitalWrite(LEDPIN, HIGH);
}

void loop(){}
