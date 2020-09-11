#include <IRremote.h>
int orangeLed = 5;
int yellowLed = 4;
int blueLed = 3;
int whiteLed = 2;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  
  pinMode(orangeLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  

  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); 
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value; 
    Serial.println(value);
    switch (value) {
      case 2295: 
      	digitalWrite(orangeLed, HIGH);
      	delay(500);
      	digitalWrite(orangeLed, LOW);
      	break;
      
      case 34935:
      	digitalWrite(yellowLed, HIGH);
      	delay(500);
      	digitalWrite(yellowLed, LOW);
      	break;
      
      case 18615:
      	digitalWrite(blueLed, HIGH);
      	delay(500);
      	digitalWrite(blueLed, LOW);
      	break;
      
      case 10455:
      	digitalWrite(whiteLed, HIGH);
      	delay(500);
      	digitalWrite(whiteLed, LOW);
    }
    
    
    irrecv.resume(); 
  }
}
