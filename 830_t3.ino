#include <Servo.h>
#include <Stepper.h>

Servo servo1;
Stepper stepper(260, 8, 10, 9, 11); //stepper pin declaration

const int trigpin =12; //sensor pins 
const int echopin= 13;

int stepPos; //stepper position variable
float distance, duration; //variables for distance calculation
//int x = 0;

void setup() {  
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);         
  servo1.attach(7);  //servo pin attatchment  
  servo1.write(90);
  stepper.setSpeed(50); 
}

void loop() {
  
    dist(); //calling distance calculation function

    servo1.write(0);//servo forward, change according to your directions
    //delay(1000); delay if needed  

    //servo1.write(90); to stop servo if needed
    
      if (distance <= 5){ //if sensor detects less than 5, start turning sequence
        moves();}

    servo1.write(0);// after turning seq, keep going straight
    delay(5000);} //Adjust this delay if car needs to go straight longer, after the turns

float dist(){
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = 100.0*(343.0*(duration/2.0))/1000000.0; }


void moves(){
  stepper.step(340);//First turn, change according to size of object
  servo1.write(0); //Servo go straight
  delay(1500); // go straight for 1.5 sec, change with respect to object
  
  servo1.write(90);//servo stop
  stepper.step(-680);//change direction to counteract first turn
  delay(10);//smal delay
  
  servo1.write(0); //go straight
  delay(3000);//go straight for 1.5 sec
  
   servo1.write(90);//servo stop
  stepper.step(680);//change direction to counteract first turn
  delay(10);//smal delay
  
  servo1.write(0); //go straight
  delay(1500);//go straight for 1.5 sec
  servo1.write(90); //stop servo
  
  stepper.step(-340); //counteract all angle changes 
    delay(10);//small delay
    }
