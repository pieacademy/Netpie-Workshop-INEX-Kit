int value = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  value = analogRead(A0);
  Serial.print("analog value = ");
  Serial.println(value);
  delay(500);
}
