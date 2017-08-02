#define INTERVAL 1000
int ledState = LOW;
long previousMillis = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  long currentMillis = millis();
  
  if(currentMillis - previousMillis > INTERVAL) {
    previousMillis = currentMillis;  
     
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
      
    digitalWrite(LED_BUILTIN, ledState);
  }
}
