#include <Arduino.h>

#include <Servo.h>
int lasergate = 7;
Servo myservo;
int doorOpen = 0;
void setup() {
  // put your setup code here, to run once:
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
 int lasergateState = digitalRead(lasergate);

if (lasergateState && doorOpen){
 
    myservo.write(90);
    doorOpen = false;
}
else if(!lasergateState && !doorOpen)
{
  doorOpen = true;
}
}