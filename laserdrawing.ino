#include <Servo.h> 
#define arr_len(x) (sizeof(x)/sizeof(*x))

int servoXPin = 10; // horizontal
int servoYPin = 9;  // vertical
int laserPin = 2;
int delaylength = 15;
int longdelay = 1000;

int min = 00;
int max = 30; // increase this for bigger drawing

Servo servoy;  
Servo servox;  

int xangle = 0;  // servo 2 position in degrees; start left
int yangle = 0;  // servo 1 position in degrees; start top 
 
void setup() { 
  servox.attach(servoXPin); 
  servoy.attach(servoYPin); 
  pinMode(laserPin, OUTPUT); 
  servox.write(xangle);
  servoy.write(yangle);
}

  int stroke1[] = {min,min,max,max};
  int stroke2[] = {max,min,min,max};

void loop() {
  gotopoint(stroke1[0], stroke1[1]);
  gotopoint(stroke1[2], stroke1[3]);
  delay(longdelay);
  gotopoint(max, min);
  gotopoint(max, max);
  delay(longdelay);
}

void gotopoint(int tox, int toy) {
  digitalWrite(laserPin, HIGH);
//  int steps = 2;
//  float xint = (tox - xangle) / steps;
//  float yint = (toy - yangle) / steps;
//  for(int i = 0; i < steps ; i++) {
//    xangle += xint;
//    yangle += yint;
//    servox.write(xangle);
//    servoy.write(yangle);
//    delay(longdelay / steps);
//  }
  xangle = tox;
  yangle = toy;
  delay(longdelay / 4);
  servox.write(xangle);
  servoy.write(yangle);
  delay(longdelay / 4);
  digitalWrite(laserPin, LOW);
}

void drawstroke(int strokedata[]) {
  int points = arr_len(strokedata)/2; // not sure if this works!
  for(int i = 1; i < points; i++) {
    int xpoint = strokedata[i * 2];
    int ypoint = strokedata[i * 2 + 1];
    gotopoint(xpoint, ypoint);
  }
}


// old:

//int yangle1 = max;  // servo 1 position in degrees; start top 
//int xangle2 = max;  // servo 2 position in degrees; start left


//void setup() { 
//  servox.attach(servoXPin); 
//  servoy.attach(servoYPin); 
//  pinMode(laserpin, OUTPUT); 
//  servox.write(xangle);
//  servoy.write(yangle);
//} 


//void loop() {
//  upstroke();
//  rightstroke();
//  downstroke();
//  leftstroke();
//  point(0, 0);
//  point(0, 10);
//  point(10, 10);
//  point(10, 0);
//  circle(5);
//}

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
  digitalWrite(laserPin, LOW);  
  xangle = xover;
  yangle = yover;
  servox.write(xangle);
  servoy.write(yangle);
  digitalWrite(laserPin, HIGH);
  delay(longdelay/2);
  digitalWrite(laserPin, LOW);  
}

void rightstroke() {
  digitalWrite(laserPin, HIGH);
  for(xangle = max; xangle > min; xangle--) {
    servox.write(xangle);
    delay(delaylength);
  }
  digitalWrite(laserPin, LOW);
}


void leftstroke() {
  digitalWrite(laserPin, HIGH);
  for(xangle = min; xangle < max; xangle++) {
    servox.write(xangle);
    delay(delaylength);
  }
  digitalWrite(laserPin, LOW);
}

void upstroke() {
  digitalWrite(laserPin, HIGH);
  for(yangle = max; yangle > min; yangle--) {
    servoy.write(yangle);
    delay(delaylength);
  }
  digitalWrite(laserPin, LOW);
}

void downstroke() {
  digitalWrite(laserPin, HIGH);
  for(yangle = min; yangle < max; yangle++) {
    servoy.write(yangle);
    delay(delaylength);
  }
  digitalWrite(laserPin, LOW);
}
