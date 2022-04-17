int led[]={2,4,6};
int ledDelay[]={500,300,500};
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<=2;i++)
  {
    pinMode(led[i],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<=2;i++)
  {
    digitalWrite(led[i],HIGH);
    delay(ledDelay[i]);
    digitalWrite(led[i],LOW);
    delay(ledDelay[i]);
  }
  
}
