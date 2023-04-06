#include <Servo.h>

// initializing servo motor pins
int servoGrip = 4;
int servoWrist = 3;
int servoElbow = 10;
int servoShoulder = 9;
int servoRotating = 11;

//The pin used to contoll motor driver 
int conveyMotor =8 ;
// ultrasonic sensor pins iniialization
int trigger = 6;
int echo = 5 ;
  
float distance ;  

// The names of the servo motors used and there position on the robotic arm
Servo ServoG; // Servo for griping objects
Servo ServoW; // wrist servo motor
Servo ServoE; //elbow servo motor
Servo ServoS; // shoulder servo motor
Servo ServoR; //Rotating servo motor 
 

void setup()
{
  // We need to attach the servo to the used pin number 
   ServoG.attach(servoGrip); 
   ServoW.attach(servoWrist); 
   ServoE.attach(servoElbow); 
   ServoS.attach(servoShoulder); 
   ServoR.attach(servoRotating); 
  
  // Activiting the pins for the ultra sonic sensor
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);

  //initializing the convey motor 
  pinMode(conveyMotor, OUTPUT);
  
  //Beging the serial communication at 9600 baud rate
  Serial.begin(9600);
  
}

void loop()
{
  // Resets the Robotic Arm co ordinates to the initial position
  initialPosition();
  delay(1000);
  
  // turns off motor if the object is at the pick up location 
  digitalWrite(conveyMotor,LOW);
  
  //The distance of the object is determined in order to pick it up
   CheckForObject();

}

float CheckForObject(){
  //location of the object on the conyver belt
  digitalWrite(trigger, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
   
  // distance in centimeters
  float distance = pulseIn(echo, HIGH) / 58;
  Serial.println(distance);
  
 //digitalWrite(conveyMotor,LOW);
 // delay(1000);
  
  if (distance > 100) {
  objectCapture();
    delay(1000);
    
   // When the object is near the pick up distance on the convey belt the motor is turned oof
  
    digitalWrite(conveyMotor,HIGH);
   objectRelease();
  }
  return distance;
  }


void initialPosition(){
  // Resets the Robotic arm co ordinates to original position
  
   // closed grip
  ServoG.write(0);
  delay(1000);
  ServoS.write(60);
  delay(1000);
  ServoE.write(60);
  delay(1000);
  ServoW.write(180);
  delay(1000);
  ServoR.write(0);
  delay(1000);

}

void objectCapture(){
  // The co ordinates used to capture the object off the convey belt
  
  //open grip
  ServoG.write(180);
  delay(1000);
  ServoS.write(60);
  delay(1000);
  ServoW.write(90);
  delay(1000);
  ServoG.write(0);
   delay(1000);
  ServoR.write(180);
  delay(1000);
  
}
void objectRelease(){
  //Co ordinates to release the object into the correct container
 //open grip
  ServoG.write(180);
  delay(1000);
  ServoS.write(60);
  delay(1000);
  ServoR.write(0);
  delay(1000);
  
}