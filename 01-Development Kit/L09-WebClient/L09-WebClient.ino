#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "netpie1";
const char* password = "netpie1234";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {    
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    http.begin("http://chavee.com/test.html");
    Serial.print("[HTTP] Send request\n");
    int httpCode = http.GET();
    
    if(httpCode > 0) {
      Serial.printf("[HTTP] Reply code: %d\n", httpCode);
      if(httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    }
    else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    
    http.end();
  }
  
  delay(10000);
}
