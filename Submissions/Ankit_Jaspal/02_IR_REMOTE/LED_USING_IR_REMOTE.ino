#include <IRremote.h>
 
const int IR_Recv = 5;   
const int blue_led = 11;
const int green_led = 10;
const int yellow_led = 9;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(blue_led, OUTPUT);      
  pinMode(green_led, OUTPUT);      
  pinMode(yellow_led, OUTPUT);      
}
 
void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 16582903://when you press the 1 button
      { 
        digitalWrite(blue_led, HIGH);
        delay(100);
      	digitalWrite(blue_led, LOW);
        delay(100);
      }
        break;   
      case 16615543: //when you press the 2 button
      {
        digitalWrite(green_led, HIGH);
        delay(100);
      	digitalWrite(green_led, LOW);
        delay(100);
      }   
        break;
       case 16599223: //when you press the 3 button
	  {
        digitalWrite(yellow_led, HIGH);
        delay(100);
      	digitalWrite(yellow_led, LOW);
        delay(100);
      }         
       break;           
       case 16591063: //when you press the 4 button
       {
        digitalWrite(blue_led, HIGH);
        delay(100);
      	digitalWrite(blue_led, LOW);
        delay(100);
        digitalWrite(green_led, HIGH);
        delay(100);
      	digitalWrite(green_led, LOW);
        delay(100);
        digitalWrite(yellow_led, HIGH);
        delay(100);
      	digitalWrite(yellow_led, LOW);
        delay(100) ; 
      }
        break;       
       case 16623703: //when you press the 5 button
      {
        digitalWrite(blue_led, HIGH);
        delay(500);
        digitalWrite(green_led, HIGH);
        delay(500);
        digitalWrite(yellow_led, HIGH);
        delay(500);
      	digitalWrite(blue_led, LOW);
        delay(500);
        digitalWrite(green_led, LOW);
        delay(500);
        digitalWrite(yellow_led, LOW);
        delay(500) ; 
      }  
        break;       
       case 16607383: //when you press the 6 button
      {
        digitalWrite(blue_led, HIGH);
        delay(100);
      	digitalWrite(blue_led, LOW);
        delay(100);
        digitalWrite(blue_led, HIGH);
        delay(100);
      	digitalWrite(blue_led, LOW);
        delay(100) ; 
        digitalWrite(green_led, HIGH);
        delay(100);
      	digitalWrite(green_led, LOW);
        delay(100);
        digitalWrite(green_led, HIGH);
        delay(100);
      	digitalWrite(green_led, LOW);
        delay(100);
        digitalWrite(yellow_led, HIGH);
        delay(100);
      	digitalWrite(yellow_led, LOW);
        delay(100) ;
        digitalWrite(yellow_led, HIGH);
        delay(100);
      	digitalWrite(yellow_led, LOW);
        delay(100);
        digitalWrite(yellow_led, HIGH);
        delay(100);
      	digitalWrite(yellow_led, LOW);
        delay(100);
        digitalWrite(green_led, HIGH);
        delay(100);
      	digitalWrite(green_led, LOW);
        delay(100) ;
        digitalWrite(blue_led, HIGH);
        delay(100);
      	digitalWrite(blue_led, LOW);
        delay(100) ; 
      }  
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}
