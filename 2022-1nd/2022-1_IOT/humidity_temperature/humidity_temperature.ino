#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  int h=dht.readHumidity();
  int t=dht.readTemperature();

  Serial.print("습도: "); Serial.print(h);
  Serial.print("%\t");
  Serial.print("온도: "); Serial.print(t);
}
