//#include <SerialESP8266wifi.h>

//#include <Adafruit_ESP8266.h>

#include <ESP8266WiFi.h>                                                    
#include <FirebaseArduino.h>                                                
#include <DHT.h>                                                            

#define FIREBASE_HOST "https://warm-patient-matress.firebaseio.com/"                          
#define FIREBASE_AUTH "VIcgq6DtGo90vAS1GfFL6LhEuJkftd1jCcqBYQav"           

#define WIFI_SSID "network_name"                                             
#define WIFI_PASSWORD "password"                                    
 
#define DHTPIN D4                                                          
#define DHTTYPE DHT11                                                       
DHT dht(DHTPIN, DHTTYPE);                                                     

void setup() {
  Serial.begin(9600);
  delay(1000);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                        
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              
  dht.begin();                                                               
}

void loop() { 
  float h = dht.readHumidity();                                              
  float t = dht.readTemperature();                                          
    
  if (isnan(h) || isnan(t)) {                                                
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print("Humidity: ");  Serial.print(h);
  String fireHumid = String(h) + String("%");                                         
  Serial.print("%  Temperature: ");  Serial.print(t);  Serial.println("Â°C ");
  String fireTemp = String(t) + String("Â°C");                                                     
  delay(4000);
  
  Firebase.pushString("/DHT11/Humidity", fireHumid);                                 
  Firebase.pushString("/DHT11/Temperature", fireTemp);                                
   
}
