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

int i;

float errCalc(int l, int m, int r) {
  //Serial.println(1/(float)m, 4);
  float left = l;
  float mid = m;
  float right = r;
  float a = ((1/left)-(1/mid));
  //Serial.println(a,4);
  float b = (1/mid)-(1/right);
  //Serial.println(b);
  float absB = abs(b);
  float absA = abs(a);
  float ab = (1/absA)-(1/absB);
  //Serial.println(ab);
  return ab;
}

void setup()
{
  Serial.begin(9600);              //  setup serial
  pinMode(motorL, OUTPUT);
  pinMode(motorR, OUTPUT);
  i = 0;
}

void loop()
{
  leftVal = analogRead(leftPin);     // read the input pin
  midVal = analogRead(midPin);
  rightVal = analogRead(rightPin);
  /*
  if (i > 255) {
    i = 0;
  }
  else {
    i += 25;
  }
  analogWrite(motorL, i);
  analogWrite(motorR, i);
  delay(100);
  */
  // less than 750 from analogRead is considered "on the track"

  float kp;
  kp = errCalc(leftVal, midVal, rightVal);
  //Serial.println(kp);

  /*
  if (midVal <= 750 && leftVal > 850 && rightVal > 850) {
    // go straight
    analogWrite(motorL, dutyCycle);
    analogWrite(motorR, dutyCycle);
  }
  */
  // need to turn left
  if (kp < 0) {
    if (kp > -100) {
      analogWrite(motorL, dutyCycle);
      analogWrite(motorR, dutyCycle);
    }
    else if (kp > -250) {
      analogWrite(motorL, dutyCycle - 25);
      analogWrite(motorR, dutyCycle + 25);
    }
    else if (kp > -500) {
      analogWrite(motorL, dutyCycle - 50);
      analogWrite(motorR, dutyCycle + 50);
    }
    /*
    else if (kp < -1250) {
      analogWrite(motorL, 0);
      analogWrite(motorR, 0);
    }
    */
  }
  else if (kp > 0) {
    if (kp < 100) {
      analogWrite(motorL, dutyCycle);
      analogWrite(motorR, dutyCycle);
    }
    else if (kp < 250) {
      analogWrite(motorL, dutyCycle + 25);
      analogWrite(motorR, dutyCycle - 25);
    }
    else if (kp < 500) {
      analogWrite(motorL, dutyCycle + 50);
      analogWrite(motorR, dutyCycle - 50);
    }
    /*
    else if (kp > 1250) {
      analogWrite(motorL, 0);
      analogWrite(motorR, 0);
    }
    */
  }
  if ((leftVal < 400 && midVal < 400) || (rightVal < 400 && midVal < 400)) {
    analogWrite(motorL, 0);
    analogWrite(motorR, 0);
  }

  
  String s1 = String();
  String leftS = String("L: ");
  s1 = leftS + leftVal;
  Serial.println(s1);
  
  //Serial.println(rightVal);             // debug value
  //delay(50);

  
  String s2 = String();
  String midS = String("M: ");
  s2 = midS + midVal;
  Serial.println(s2);
  //Serial.println("M: " + midVal);
  //Serial.println(midVal);
  //delay(1000);

  String s3 = String();
  String rightS = String("R: ");
  s3 = rightS + rightVal;
  Serial.println(s3);
  //Serial.println("R: " + rightVal);
  //Serial.println(rightVal);
  delay(300);
  
}
