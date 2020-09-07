 
/* Author: Github @Ankuraxz
*/ 
//PIR
int sensorState = 0;
//SERVO
#include <Servo.h>
int pos = 0;
int pos1 =0;
Servo servo_5;
//LDR
int ldr =0;

//
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(4,INPUT);
  servo_5.attach(5);
  pinMode(A1, INPUT);
  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
}

void loop()
{ sensorState =0;
  ldr =100;
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  // PIR + SERVO (DOOR)
  sensorState = digitalRead(4);
  if (sensorState == HIGH){
    for (pos = 0; pos <= 270; pos += 1) {
    servo_5.write(pos);
    delay(5); // Wait for 15 millisecond(s)
    }
  }
  else {
    //  Door open
    for (pos1 = pos; pos1 >= 0; pos1 -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_5.write(pos1);
    // wait 15 ms for servo to reach the position
    delay(5); // Wait for 15 millisecond(s)
    }
  }
  
  // LDR + BULB (Automated Lights)
  ldr = analogRead(A1);
  if (ldr <30){
    digitalWrite(6,HIGH);
    delay(10);
  }
  else{
    digitalWrite(6,LOW);
  }
  
 //TEMP + FAN MOTOR
  //{}
}
