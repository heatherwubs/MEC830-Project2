#define ENABLE 4
#define DIRA 12
#define DIRB 13
#include <Stepper.h>

Stepper stepper(2048, 8, 10, 9, 11); //stepper pin declaration

const int trigpin =5; //sensor pins 
const int echopin= 6;

int stepPos; //stepper position variable
float distance, duration; //variables for distance calculation


void setup() {  
  Serial.begin(9600);         
  stepper.setSpeed(15); 
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  delay(5000);
}

void loop() {
  
  dist(); //calling distance calculation function

  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,LOW); //set motor direction to positive
  digitalWrite(DIRB,HIGH);
    
  if (distance <= 500){ //if sensor detects less than 5, start turning sequence
    moves();
  }
  
  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,LOW); //set motor direction to positive
  digitalWrite(DIRB,HIGH);// after turning seq, keep going straight
  delay(1000);} //Adjust this delay if car needs to go straight longer, after the turns

float dist(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = duration*0.34/2;
  Serial.println(distance);
}


void moves(){
  digitalWrite(ENABLE,LOW);
  stepper.step(300);//First turn, change according to size of object
  delay(10);
  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,LOW); //set motor direction to positive
  digitalWrite(DIRB,HIGH); //Servo go straight
  delay(1500); // go straight for 1.5 sec, change with respect to object
  
  digitalWrite(ENABLE,LOW);//servo stop
  stepper.step(-600);//change direction to counteract first turn
  delay(10);//smal delay
  
  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,LOW); //set motor direction to positive
  digitalWrite(DIRB,HIGH); //go straight
  delay(3000);//go straight for 1.5 sec
  
  digitalWrite(ENABLE,LOW); //stop servo
  stepper.step(600); //counteract all angle changes 
  delay(10);//small delay

  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,LOW); //set motor direction to positive
  digitalWrite(DIRB,HIGH); //go straight
  delay(1500);//go straight for 1.5 sec

  digitalWrite(ENABLE,LOW); //stop servo
  stepper.step(-300); //counteract all angle changes 
  delay(10);//small delay

  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,LOW); //set motor direction to positive
  digitalWrite(DIRB,HIGH); //go straight
  delay(2000);

  digitalWrite(ENABLE,LOW);
  delay(10000);
 }
