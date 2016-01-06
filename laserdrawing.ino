#include <Servo.h> 
 
int servo1Pin = 9;  // vertical
int servo2Pin = 10; // horizontal
int laserpin = 2;
int delaylength = 15;
int longdelay = 1000;

int min = 0;
int max = 20; // increase this for bigger drawing

Servo servo1;  
Servo servo2;  

int angle1 = max;  // servo 1 position in degrees; start top 
int angle2 = max;  // servo 2 position in degrees; start left
 
void setup() { 
  servo1.attach(servo1Pin); 
  servo2.attach(servo2Pin); 
  pinMode(laserpin, OUTPUT); 
  servo1.write(angle1);
  servo2.write(angle2);
} 

void loop() {
//  upstroke();
//  rightstroke();
//  downstroke();
//  leftstroke();
//  point(0, 0);
//  point(0, 10);
//  point(10, 10);
//  point(10, 0);
  circle(5);
}

void circle(int radius) {
  point(min, radius);
  point(min, max-radius);
  point(radius, max);
  point(max-radius, max);
  point(max, max-radius);
  point(max, radius);
  point(max-radius, min);
  point(radius, min);
}

void point(int xover, int yover) {
  digitalWrite(laserpin, LOW);  
  angle1 = yover;
  angle2 = xover;
  servo1.write(angle1);
  servo2.write(angle2);
  digitalWrite(laserpin, HIGH);
  delay(longdelay/2);
  digitalWrite(laserpin, LOW);  
}

void rightstroke() {
  digitalWrite(laserpin, HIGH);
  for(angle2 = max; angle2 > min; angle2--) {
    servo2.write(angle2);
    delay(delaylength);
  }
  digitalWrite(laserpin, LOW);
}


void leftstroke() {
  digitalWrite(laserpin, HIGH);
  for(angle2 = min; angle2 < max; angle2++) {
    servo2.write(angle2);
    delay(delaylength);
  }
  digitalWrite(laserpin, LOW);
}

void upstroke() {
  digitalWrite(laserpin, HIGH);
  for(angle1 = max; angle1 > min; angle1--) {
    servo1.write(angle1);
    delay(delaylength);
  }
  digitalWrite(laserpin, LOW);
}

void downstroke() {
  digitalWrite(laserpin, HIGH);
  for(angle1 = min; angle1 < max; angle1++) {
    servo1.write(angle1);
    delay(delaylength);
  }
  digitalWrite(laserpin, LOW);
}
