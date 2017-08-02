void setup() {
  //LED_BUILTIN คือตัวแปรค่าเริ่มต้น
  //สำหรับ LED ประจำแต่ละบอร์ด
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN,HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);
}
