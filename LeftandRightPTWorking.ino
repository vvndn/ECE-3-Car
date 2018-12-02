#include <string.h>

int ledPinRed = 5;
int ledPinGreen = 10;
int ledPinBlue = 11;

int rightPin = 1;
int midPin = 4;
int leftPin = 7;

int motorL = 9;
int motorR = 3;

int dutyCycle = 200;

int leftVal = 0;
int midVal = 0;
int rightVal = 0;    

int rBlack = 550;
int rWhite = 700;
int rAvg = 625;

int lBlack = 500;
int lWhite = 700;
int lAvg = 600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //delay(200);
  //read left and right inputs
  leftVal = analogRead(leftPin);
  rightVal = analogRead(rightPin);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);


  //go straight
  if (leftVal >= lAvg && rightVal >= rAvg) {
    analogWrite(motorL, 150);
    analogWrite(motorR, 150);
    digitalWrite(ledPinGreen, HIGH);
  }
  //turn right
  else if (leftVal >= lAvg && rightVal <= rAvg) {
    analogWrite(3, 0);
    analogWrite(9, 250);
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinBlue, LOW);
    //delay(500);
  }
  //turn left
  else if (leftVal <= lAvg && rightVal >= rAvg) {
    analogWrite(motorR, 250);
    analogWrite(motorL, 0);
    digitalWrite(ledPinBlue, HIGH);
    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinRed, LOW);
    //delay(500);
  }
  else if (leftVal <= lAvg && rightVal <= rAvg) {
    analogWrite(motorL, 0);
    analogWrite(motorR, 0);
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinBlue, HIGH);
    digitalWrite(ledPinGreen, LOW); 
    delay(2000);  
  }
  else {
    analogWrite(motorL, 0);
    analogWrite(motorR, 0);
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinBlue, HIGH);
    digitalWrite(ledPinGreen, HIGH);
  }

  String s1 = String();
  String li = String("L: ");
  s1 = li + leftVal;
  Serial.println(s1);

  String s2 = String();
  String ri = String("R: ");
  s2 = ri + rightVal;
  Serial.println(s2);
  //delay(300);

}
