#include <IRremote.h> 
 //Define Pins   
int RECV_PIN =6;     
int redLed = 11;     
int greenLed = 10;        
int blueLed = 9;     
IRrecv irrecv(RECV_PIN);     
decode_results results;     
void setup()
{          
 pinMode(redLed, OUTPUT);     
 pinMode(greenLed, OUTPUT);     
 pinMode(blueLed, OUTPUT); 
 Serial.begin(9600);
 Serial.println("Enabling IRin");
 irrecv.enableIRIn();
 Serial.println("Enabled IRin");   
}     
void loop(){     
   if (irrecv.decode(&results)){     
int value = results.value;     
Serial.println(value);      
       switch(value)
       {     
         case 2295:          
         digitalWrite(redLed, HIGH);
         delay(1000);     
         digitalWrite(redLed, LOW);     
         break;     

         case 18615:
         digitalWrite(greenLed, HIGH);
         delay(1000);
         digitalWrite(greenLed, LOW);
         break;

         case 10455:
         digitalWrite(blueLed, HIGH);
         delay(1000);
         digitalWrite(blueLed, LOW);
       }
         
       irrecv.resume();      
   }     
}
