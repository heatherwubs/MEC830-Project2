//measure car speed with CarSpeedTest.ino and modify hilighted sections accordingly
#include <Stepper.h>
Stepper stepper(2048, 8, 10, 9, 11);
int motorpin = 3;

int carspeed=20;        //ENTER SPEED OF MOTOR IN MS/MM HERE
int L = 30;            //ENTER L OF YOUR CAR IN MM HERE 
int rightturn = 100;     //ADJUST DEPENDING ON STEPPER/WHEEL ORIENTATION
int leftturn = -100;     //ADJUST DEPENDING ON STEPPER/WHEEL ORIENTATION

void setup(){
  pinMode(motorpin, OUTPUT);
  stepper.setSpeed(20);
  analogWrite(motorpin, 255); //full power to motor, turns at full speed
  delay(5*L*carspeed);        //car continues forward for 5/6 of distance
  stepper.step(rightturn);    //car begins to turn right
  delay(L*carspeed);          //car continues to turn right for 1/6 of distance
  stepper.step(leftturn);     //wheels straighten
  delay(5*L*carspeed);        //car continues straight for 5/6 of second distance
  stepper.step(leftturn);     //car begins to turn left
  delay(L*carspeed);          //car continues to turn left for remaining 1/6 of distance
  stepper.step(rightturn);    //wheels straighten
  delay(6*L*carspeed);        //car travels full final distance
  analogWrite(motorpin, 0);   //motor turns off, car stops
}

void loop(){
  
}
