//HOW TO USE THIS PROGRAM
//1. attach DC motor/servo to pin 3 or modify "motorpin" in line 7 to match your pin
//2. set up a measuring tape or ruler on the ground and set up the reference point of the car at 0
//3. run this program
//4. when the motor stops spinning record the distance the car has travelled.

int motorpin = 3;

void setup(){
  pinMode(motorpin, OUTPUT);

}
void loop(){
  analogWrite(motorpin, 255); //full power to motor, turns at full speed
  delay(5000); //keep motor on for 5 seconds
  analogWrite(motorpin, 0); //no power to motor, turns motor off
  delay(10000); //keep motor off for 10 seconds
}

//HOW TO CALCULATE SPEED
//Speed = distance travelled in mm / moving time in miliseconds
//for example: the car travelled 250mm in 5 seconds. speed = 250/5000 = 0.05mm/ms

//USING THIS FOR PROJECT
//since we need to tell the robot to travel a desired distance, we need to tell it to run for a sepcified amount of time.
//in this context, we need to know how many ms it takes to travel 1mm
//1. use the inverse of the previous speed, or: moving time in miliseconds / distance travelled in mm
//2. multiply this value by the distance we need to travel
//3. the resulting number is the number of miliseconds to set the delay at after the motor is activated.
//for example: our motors inverse speed is 20ms/mm. we want to travel 800mm. 
//(20ms/mm)(800mm)= 16000ms
//therefore, the motor must run for 16000ms to travel 800mm.
