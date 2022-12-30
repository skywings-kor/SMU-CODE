int ledpin=4;
int val=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(A0);

  //밝을경우
  if(val>600)
  {
    digitalWrite(ledpin,LOW);
  }

  else
  {
    digitalWrite(ledpin,HIGH);
    delay(200);
  }
}
