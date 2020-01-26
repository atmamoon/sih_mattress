#include <dht.h>

dht DHT;

#define DHT11_PIN A1
#define relay 9
#define ref_temperature 28
void setup(){
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(DHT11_PIN,INPUT);
  //DHT.begin();
}
int error=0;
void loop()
{
   DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  
  delay(300);
  error=ref_temperature-DHT.temperature;
  Serial.print("ERROR = ");
  Serial.println(error);
 // if (error>=2)
  digitalWrite(relay,HIGH);
  //else if(error<=0)
 delay(2000);
  digitalWrite(relay,LOW);
  delay(2000);
  //else
  //digitalWrite(relay,HIGH);
}
