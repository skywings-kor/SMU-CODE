int buttonpin=5;
int ledpin=13;
int buttonstate=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonpin,INPUT);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonstate=digitalRead(buttonpin);
  if(buttonpin==HIGH)
  {
    digitalWrite(ledpin,HIGH);
  }

  else
  {
    digitalWrite(ledpin,LOW);
  }
  
}
