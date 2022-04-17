
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration,distance;
  digitalWrite(2,HIGH);
  delay(10);
  digitalWrite(2,LOW);
  
  duration=pulseIn(3,HIGH);
  distance=((float)(340*duration)/10000/2);

  Serial.print("Duration"); Serial.print(duration);
  Serial.print("Distance"); Serial.print(distance);
  delay(500);
}
