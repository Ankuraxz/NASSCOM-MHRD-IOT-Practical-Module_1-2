 #include<IRremote.h>
int red = 9 ;
int blue = 11;
int green = 10;
int RECV_PIN = 6;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(red , OUTPUT);
  pinMode(blue , OUTPUT);
  pinMode(green , OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value , HEX);
    irrecv.resume();
    
    switch(results.value)
    {
      case 0xFD08F7 :
      	digitalWrite(red , HIGH);
      	digitalWrite(green , LOW);
      	digitalWrite(blue , LOW);
      	break;
      
      case 0xFD8877 :
      	digitalWrite(red , LOW);
      	digitalWrite(green , HIGH);
      	digitalWrite(blue , LOW);
      	break;
      
      case 0xFD48B7 :
      	digitalWrite(red , LOW);
      	digitalWrite(green , LOW);
      	digitalWrite(blue , HIGH);
      	break;
      
      case 0xFD30CF :
      	digitalWrite(red , LOW);
      	digitalWrite(green , LOW);
      	digitalWrite(blue , LOW);
      	break;
      
      default :
      	digitalWrite(red , LOW);
      	digitalWrite(green , LOW);
      	digitalWrite(blue , LOW);
      	break;
    }
    
  }
delay(100);
}
