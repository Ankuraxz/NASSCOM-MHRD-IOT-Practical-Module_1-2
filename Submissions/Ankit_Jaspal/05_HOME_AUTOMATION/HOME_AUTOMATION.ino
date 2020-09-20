#include<Servo.h>
const int ping_pin = 7;
int servo_pin = 9;
int rled_pin = 3;
int gled_pin = 2;
int pir = 8;
int l29ic = 11;
int l29_in1=13;
int l29_in2=12;
int temp=A0;

Servo servo_test;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  servo_test.attach(servo_pin);
  pinMode(pir,INPUT);
  pinMode(rled_pin,OUTPUT);
  pinMode(gled_pin,OUTPUT);
  pinMode(l29ic,OUTPUT);
  pinMode(l29_in2,OUTPUT);
  pinMode(l29_in1,OUTPUT);
  pinMode(temp,INPUT);
  digitalWrite(pir,LOW);
  digitalWrite(l29ic,HIGH);
  digitalWrite(rled_pin,HIGH);
}

void loop() {
  
  long duration, inches, cm;

  pinMode(ping_pin, OUTPUT);
  digitalWrite(ping_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(ping_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ping_pin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(ping_pin, INPUT);
  duration = pulseIn(ping_pin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
 // if distance is less then make servo open the door 
  servo_test.write(0);
  
  if(cm < 40)
  {
    servo_test.write(90);
    delay(2000);
  }
  else
  {
    servo_test.write(0);
  }
  
  // PIR with LED starts
  int pir_val = digitalRead(pir);
  
  if(pir_val == HIGH)
  {
    digitalWrite(rled_pin,HIGH);
    delay(1000);
  }
  else if(pir_val == LOW)
  {
    digitalWrite(rled_pin,LOW );
  }
  
  //temp with fan
  float value=analogRead(temp);
  float temperature=value*0.48;
  
  Serial.println("temperature");
  Serial.println(temperature);
  
  if(temperature > 20)
  {
    digitalWrite(l29_in1,HIGH);
    digitalWrite(l29_in2,LOW);
  }
  else
  {
    digitalWrite(l29_in2,LOW);
    digitalWrite(l29_in1,LOW);
  }
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
