#include <Servo.h>
#include <Stepper.h>

Servo servo;
Stepper stepper(200, 8, 9, 10, 11);

int val_x;
int val_y;

void setup() {
servo.attach(7); 
servo.write(90);}

void loop() {
 val_x = analogRead(0);
 val_y = analogRead(1);
 
 val_x = map(val_x, 0, 1023, 0, 180);
 
 servo.write (val_x);

 
  if (val_y>=523)
 {int speed = map(val_y,523,1023,0,200);
  stepper.setSpeed(speed);
  stepper.step(-50);}
 
 if (val_y<=500)
{ int speed = map(val_y,500,0,0,200);
  stepper.setSpeed(speed);
  stepper.step(50); }}
