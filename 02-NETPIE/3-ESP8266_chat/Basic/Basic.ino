/*  NETPIE ESP8266 basic sample                            */
/*  More information visit : https://netpie.io             */

#include <ESP8266WiFi.h>
#include <MicroGear.h>

// ----- แก้ค่า config 6 ค่าข้างล่างนี้ --------------------------------------------------------
const char* ssid     = "YOUR_WIFI_SSID";          // ชื่อ ssid
const char* password = "YOUR_WIFI_PASSWORD";      // รหัสผ่าน wifi

#define APPID   "GROUP_APPID"
#define KEY     "GROUP_KEY"
#define SECRET  "GROUP_SECRET"
#define ALIAS   "YOUR_UNIQUE_ALIAS"               // แทนที่ด้วยหมายเลขของท่าน เช่น "A01"
// --------------------------------------------------------------------------------------

WiFiClient client;

int last_chat_time = 0;
MicroGear microgear(client);

// เมื่อมี message ใหม่เข้ามา จะเรียก function นี้
void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) {
    Serial.print("Incoming message --> ");
    msg[msglen] = '\0';
    Serial.println((char *)msg);
}

// เมื่อ connect netpie สำเร็จ จะเรียก function นี้
void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.println("Connected to NETPIE...");
    // ตั้ง alias ของ microgear นี้เป็น ALIAS
    microgear.setAlias(ALIAS);
}

void setup() {
    // ลงทะเบียน Event listeners
    microgear.on(MESSAGE,onMsghandler);
    microgear.on(CONNECTED,onConnected);

    Serial.begin(115200);
    Serial.println("Starting...");

    // ทำการ init wifi โดยระบุ ssid และ password วิธีนี้เป็นเพียงวิธีหนึ่งที่ simple ที่สุด
    if (WiFi.begin(ssid, password)) {
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
    }
    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    // initial ตัวแปร microgear
    microgear.init(KEY,SECRET,ALIAS);

    // เชื่อมต่อไปที่ NETPIE
    microgear.connect(APPID);
}

void loop() {
    // เช็คว่า connect อยู่หรือเปล่า ถ้าไม่ให้ทำการ conenct ใหม่
    if (microgear.connected()) {
        // เรียก function นี้เป็นระยะๆ ไม่เช่นนั้น connection จะหลุด
        microgear.loop();

        if (millis() - last_chat_time >= 1000) {
            Serial.println("Send chat message >>>");

            // chat หา device ชื่อ ALIAS ซึ่งก็คือชื่อของตัวเอง
            microgear.chat(ALIAS,"Hello..");
            last_chat_time = millis();
        } 
    }
    else {
        Serial.println("connection lost, reconnect...");
        microgear.connect(APPID);
    }
}
