#include <string.h>

int rightPin = 1;
int midPin = 4;
int leftPin = 7;

int motorL = 3;
int motorR = 9;

int dutyCycle = 200;

int leftVal = 0;
int midVal = 0;
int rightVal = 0;    

int maxW = 986;
int maxB = 210;
int midBWM = 500;
int midBWR = 750;
int offset = 100;

int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);              //  setup serial
  pinMode(motorL, OUTPUT);
  pinMode(motorR, OUTPUT);
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  //leftVal = analogRead(leftPin);     // read the input pin
  midVal = analogRead(midPin);
  rightVal = analogRead(rightPin);

  // guardrail 
  if (midVal <= midBWM && rightVal > midBWR) {
    // go straight
    analogWrite(motorL, 120);
    analogWrite(motorR, 150);
  }
  // turn right
  if (midVal > midBWM && rightVal <= midBWR) {
    analogWrite(motorL, 160);
    analogWrite(motorR, 20);
  }
  // turn left
  if (rightVal > midBWR && midVal > midBWM) {
    analogWrite(motorL, 20);
    analogWrite(motorR, 175);
  }
  // stop
  if (rightVal <= midBWR &&  midVal <= midBWM) {
    analogWrite(motorL, 0);
    analogWrite(motorR, 0);
  }
  String s2 = String();
  String midS = String("M: ");
  s2 = midS + midVal;
  Serial.println(s2);

  String s3 = String();
  String rightS = String("R: ");
  s3 = rightS + rightVal;
  Serial.println(s3);

  //delay(300);
}
