/*
Author Github @Ankuraxz
*/

#include <Servo.h>

int pos = 0;

Servo servo_10;

void setup()
{
  servo_10.attach(10);
  Serial.begin(9600);

}

void loop()
{
  //CLOCKWISE
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_10.write(pos);
    Serial.println(pos);
    // wait 15 ms for servo to reach the position
    delay(10); // Wait for 15 millisecond(s)
  }
  //ANTI CLOCKWISE
  for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_10.write(pos);
    Serial.println(pos);
    // wait 15 ms for servo to reach the position
    delay(10); // Wait for 15 millisecond(s)
  }
  //Maxrotations
  for (pos = 0; pos <= 270; pos += 1) { //270 deg is max rotation
    // tell servo to go to position in variable 'pos'
    servo_10.write(pos);
    Serial.println(pos);
    // wait 15 ms for servo to reach the position
    delay(50); // Wait for 15 millisecond(s)
  }
}
