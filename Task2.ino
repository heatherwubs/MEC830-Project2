//measure car speed with CarSpeedTest.ino and modify hilighted sections accordingly
#define ENABLE 4
#define DIRA 12
#define DIRB 13
#include <Stepper.h>
Stepper stepper(2048, 8, 10, 9, 11);


int carspeed=3;        //ENTER SPEED OF MOTOR IN MS/MM HERE
int L = 230;            //ENTER L OF YOUR CAR IN MM HERE 
int rightturn = 270;     //ADJUST DEPENDING ON STEPPER/WHEEL ORIENTATION
int leftturn = -270;     //ADJUST DEPENDING ON STEPPER/WHEEL ORIENTATION

void setup(){
  delay(5000);
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  stepper.setSpeed(15);
  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,LOW); //set motor direction to positive
    digitalWrite(DIRB,HIGH);; //full power to motor, turns at full speed
  delay(5.65*L*carspeed);        //car continues forward for 5/6 of distance
  stepper.step(rightturn);    //car begins to turn right
  delay(2*L*carspeed);          //car continues to turn right for 1/6 of distance
  stepper.step(leftturn);
  digitalWrite(ENABLE,HIGH);//wheels straighten
  delay(2.5*L*carspeed);        //car continues straight for 5/6 of second distance
  stepper.step(leftturn);     //car begins to turn left
  delay(1.7*L*carspeed);          //car continues to turn left for remaining 1/6 of distance
  stepper.step(rightturn);    //wheels straighten
  delay(5.5*L*carspeed);        //car travels full final distance
   digitalWrite(ENABLE,LOW);   //motor turns off, car stops
}

void loop(){
  
}
