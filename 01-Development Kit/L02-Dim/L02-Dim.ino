int brightness = 0;
int fadeAmount = 10;

void setup() {
  pinMode(A0, OUTPUT);
}

void loop() {
  analogWrite(A0, brightness);
  brightness = brightness + fadeAmount;
  
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  delay(30);
}
