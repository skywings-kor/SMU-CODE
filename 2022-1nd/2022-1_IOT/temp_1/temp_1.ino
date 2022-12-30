int pin1=A0;
int reading;
float temp;
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  reading=analogRead(pin1);
  temp=(5.0*reading*100.0)/1024.0;
  Serial.print(temp);
  Serial.print("도");
  delay(1000);
  
}
