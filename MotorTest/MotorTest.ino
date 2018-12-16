int pinR_LED = 9;
int pinG_LED = 10;
int pinB_LED = 11;
int pinLeft = 3;
int pinRight = 5;

void setup() {
  // put your setup code here, to run once:
  //pinMode(pinR_LED, OUTPUT);
  //pinMode(pinG_LED, OUTPUT);
  pinMode(pinLeft, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pinLeft, 100);
  //analogWrite(pinRight, 50);
  /*
  digitalWrite(pinR_LED, LOW);
  digitalWrite(pinG_LED, LOW);
  digitalWrite(pinB_LED, LOW);
  delay(1000);
  digitalWrite(pinR_LED, HIGH);
  digitalWrite(pinG_LED, HIGH);
  digitalWrite(pinB_LED, HIGH);
  //delay(1000);
  */
  
  
}
