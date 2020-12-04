#define ENABLE 4
#define DIRA 12
#define DIRB 13
#include <Stepper.h>

Stepper stepper(2048, 8, 10, 9, 11);

int val_x;
int val_y;

void setup() {
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
  }
void loop() {
  val_x = analogRead(0);
  val_y = analogRead(1);
  Serial.println(val_x);
  Serial.println(" ");
  
  if(val_x<480){
    Serial.println("forwards");
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIRB,LOW); //set motor direction to positive
    digitalWrite(DIRA,HIGH);
    }
  if(val_x>520){
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIRA,LOW); //set motor direction to positive
    digitalWrite(DIRB,HIGH);
    }
  else{
    digitalWrite(ENABLE,LOW);
    }
 
  if (val_y>=600){
    stepper.setSpeed(15);
    stepper.step(20);
    }
    
  if (val_y<=400){
    stepper.setSpeed(15);
    stepper.step(-20); 
    }
  }
