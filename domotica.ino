#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID "ARRIS-1502"
#define WIFI_PASSWORD "8B7EE4C8B5044FFE"

#define FIREBASE_HOST "verano-iot.firebaseio.com"

/** The database secret is obsoleted, please use other authentication methods, 
 * see examples in the Authentications folder. 
*/
#define FIREBASE_AUTH "ELBkqiVNrOHQS7pkfAEzRCFQJ8qgj9XI21prewjy"

void setup() {
 pinMode (16,OUTPUT);
 pinMode (5,OUTPUT);
 pinMode (4,OUTPUT);
 pinMode (0,OUTPUT);
  Serial.begin(2400);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  if (Firebase.getString("objects/obj1") == "1"){
    digitalWrite(16, 1);
  }else{
    digitalWrite(16, 0);
  }
  
  if (Firebase.getString("objects/obj2") == "1"){
    digitalWrite(5, 1);
  }else{
    digitalWrite(5, 0);
  }

  if (Firebase.getString("objects/obj3") == "1"){
    digitalWrite(4, 1);
  }else{
    digitalWrite(4, 0);
  }

  if (Firebase.getString("objects/obj3") == "1"){
    digitalWrite(0, 1);
  }else{
    digitalWrite(0, 0);
  }
  
  
  }

  
