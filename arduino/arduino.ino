//D4,D5,D19
// 3v3 , GND
#include <WiFi.h>
//inisialisasi web api
#include <WebServer.h>
WebServer server(80);
//inisalisais wifi
const char* ssid ="GTS";
const char* pass ="123456789";

bool dapurLedState=false;
bool kamarLedState=false;
bool belakangLedState=false;
bool depanLedState=false;

const int espLed=2;
const int ledpint1=4;
const int ledpint2=5;
const int ledpint3=19;
const int ledpint4=21;

void setup() {
  Serial.begin(115200);
  pinMode(espLed,OUTPUT);

  pinMode(ledpint1,OUTPUT);
  pinMode(ledpint2,OUTPUT);
  pinMode(ledpint3,OUTPUT);
  pinMode(ledpint4,OUTPUT);


  digitalWrite(ledpint1,LOW);
  digitalWrite(ledpint2,LOW);
  digitalWrite(ledpint3,LOW);
  digitalWrite(ledpint4,LOW);

  WiFi.begin(ssid,pass);
  Serial.print("connect to wifi GTS....");
  while (WiFi.status() != WL_CONNECTED){
    digitalWrite(espLed,LOW);
    delay(1000);
    Serial.print("....");
  }
  digitalWrite(espLed,HIGH);
  Serial.println("");
  Serial.println("Connected to wifi network");
  Serial.println(WiFi.localIP());

  server.on("/dapur",HTTP_GET,getDapurLED);
  server.on("/kamar",HTTP_GET,getKamarLED);
  server.on("/belakang",HTTP_GET,getBelakangLED);
  server.on("/depan",HTTP_GET,getDepanLED);

  server.on("/dapur",HTTP_POST,setDapurLED);
  server.on("/kamar",HTTP_POST,setKamarLED);
  server.on("/belakang",HTTP_POST,setBelakangLED);
  server.on("/depan",HTTP_POST,setDepanLED);
  server.begin();
  Serial.println("serverStarted");
}

void loop() {
  server.handleClient();

}
void setKamarLED(){
  kamarLedState=!kamarLedState;
  digitalWrite(ledpint1, kamarLedState?HIGH:LOW);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"text/plain",kamarLedState?"ON":"OFF");
}
void setDapurLED(){
  dapurLedState=!dapurLedState;
  digitalWrite(ledpint2, dapurLedState?HIGH:LOW);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"text/plain",dapurLedState?"ON":"OFF");
}

void setBelakangLED(){
  belakangLedState=!belakangLedState;
  digitalWrite(ledpint3, belakangLedState?HIGH:LOW);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"text/plain",belakangLedState?"ON":"OFF");
}
void setDepanLED(){
  depanLedState=!depanLedState;
  digitalWrite(ledpint4, depanLedState?HIGH:LOW);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"text/plain",depanLedState?"ON":"OFF");
}





void getKamarLED(){
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"text/plain",kamarLedState?"ON":"OFF");
}
void getDapurLED(){
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"text/plain",dapurLedState?"ON":"OFF");
}
void getBelakangLED(){
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"text/plain",belakangLedState?"ON":"OFF");
}
void getDepanLED(){
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"text/plain",depanLedState?"ON":"OFF");
}





