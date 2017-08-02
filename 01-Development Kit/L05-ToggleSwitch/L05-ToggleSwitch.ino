#define SWPIN D3
#define LEDPIN LED_BUILTIN
int buttonState = 0;
int ledState = 0;

void setup() {
    pinMode(LEDPIN,OUTPUT);
    pinMode(SWPIN,INPUT);
}
void loop() {
  int  reading = digitalRead(SWPIN);
  
  if(buttonState != reading){
    delay(100);
    buttonState = reading;
    
    if (buttonState == HIGH) {
      ledState = !ledState;
    }
  }
  
  digitalWrite(LEDPIN,ledState);
}
