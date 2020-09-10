#include <IRremote.h>

// This will print in order 1234567890
int one = 12;
int two = 11;
int three = 9;
int four = 8;
int five = 7;
int six = 6;
int seven = 5;
int eight = 4;
int nine = 3;
int zero = 2;
int RECV_PIN = 10;

IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  pinMode(four, OUTPUT);
  pinMode(five, OUTPUT);
  pinMode(six, OUTPUT);
  pinMode(seven, OUTPUT);
  pinMode(eight, OUTPUT);
  pinMode(nine, OUTPUT);
  pinMode(zero, OUTPUT);
  
  
  Serial.begin(9600);
  
  irrecv.enableIRIn(); 
  
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch (value) {
      case 2295:
        Serial.println("Pressed 1");
      	digitalWrite(one, HIGH);
      	delay(500);
      	digitalWrite(one, LOW);
      	break;
      
      case 34935:
      Serial.println("Pressed 2");
      	digitalWrite(two, HIGH);
      	delay(500);
      	digitalWrite(two, LOW);
      	break;
      
      case 18615:
      	Serial.println("Pressed 3");
      	digitalWrite(three, HIGH);
      	delay(500);
      	digitalWrite(three, LOW);
      	break;
      
      case 10455:
      	Serial.println("Pressed 4");
      	digitalWrite(four, HIGH);
      	delay(500);
      	digitalWrite(four, LOW);
      	break;
      
      case 43095:
      	Serial.println("Pressed 5");
      	digitalWrite(five, HIGH);
      	delay(500);
      	digitalWrite(five, LOW);
      	break;
      
      case 26775:
      	Serial.println("Pressed 6");
      	digitalWrite(six, HIGH);
      	delay(500);
      	digitalWrite(six, LOW);
      	break;
      
      case 6375:
      	Serial.println("Pressed 7");
      	digitalWrite(seven, HIGH);
      	delay(500);
      	digitalWrite(seven, LOW);
      	break;
      
      case 39015:
      	Serial.println("Pressed 8");
      	digitalWrite(eight, HIGH);
      	delay(500);
      	digitalWrite(eight, LOW);
      	break;
      
      case 22695:
      	Serial.println("Pressed 9");
      	digitalWrite(nine, HIGH);
      	delay(500);
      	digitalWrite(nine, LOW);
      	break;
      
      case 12495:
      	Serial.println("Pressed 0");
      	digitalWrite(zero, HIGH);
      	delay(500);
      	digitalWrite(zero, LOW);
      	break;
    }
    irrecv.resume();
  }
}
