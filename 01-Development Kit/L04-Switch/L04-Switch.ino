#define SWPIN D3
#define LEDPIN LED_BUILTIN

void setup() {
  pinMode(LEDPIN, OUTPUT); // Set as output
  pinMode(SWPIN, INPUT);   // Set as input
}

void loop(){
  if (digitalRead(SWPIN) == HIGH){
    digitalWrite(LEDPIN,LOW);
  }
  else{
    digitalWrite(LEDPIN,HIGH);
  }
}
