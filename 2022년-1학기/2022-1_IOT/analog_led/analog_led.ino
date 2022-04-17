int ledpin=13;
int val=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  
  }

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(A0);

  digitalWrite(ledpin,HIGH);
  delay(val);
  digitalWrite(ledpin,LOW);
  delay(val);
}
