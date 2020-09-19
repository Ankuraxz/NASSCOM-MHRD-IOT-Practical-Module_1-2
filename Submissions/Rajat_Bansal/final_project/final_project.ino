int red = 2;
int pir = 3;
int pir_state = 0;
int const gas = A5;
int buzzer=4;
int threshold=0;
int temp = A2;
int motor=6;
int ldr = A3;
int bulb = 7;
#include<Servo.h>
int pos=0;
int pos1=0;
Servo servo;

void setup(){
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(pir,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(temp,INPUT);
  pinMode(motor,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(bulb,OUTPUT);
  servo.attach(10);
  
}


void loop(){
  pir_state=digitalRead(pir);
  servo.write(0);
  if (pir_state==HIGH){
    for (pos=0;pos<=90;pos++){
      servo.write(pos);
      delay(5);
      digitalWrite(red,HIGH);
    }
  }
   else{
     for(pos1=pos;pos1>=0;pos1--){
      servo.write(pos1);
      //delay(5);
     }
  }
  int gas_read=analogRead(gas);
  gas_read=map(gas_read, 300, 750, 0, 100);
  //Serial.print(gas_read);
  if (gas_read>threshold){
    digitalWrite(buzzer,HIGH);
    digitalWrite(red,HIGH);
  }
  else{
    digitalWrite(red,LOW);
    digitalWrite(buzzer,LOW);
  }
  float tempr= analogRead(temp);
  tempr=tempr*(0.48828);
  if (tempr>30){
    digitalWrite(motor,HIGH);
  }
  else{
  digitalWrite(motor,LOW);
  }
  float light = analogRead(ldr);
  Serial.print(light);
  if (light>25){
    digitalWrite(bulb,HIGH);
  }
  else{
    digitalWrite(bulb,LOW);
  }

    
  delay(1000);
  
}

  
  
