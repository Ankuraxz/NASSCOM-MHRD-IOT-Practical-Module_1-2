int pot_pin=A5;
int led_count=9;
int led_pin[]={2,3,4,5,6,7,8,9,10};
int pot,led_level,led;

void setup()
{
  for(led=0;led<=led_count;led++)
	{
  		pinMode(led_pin[led], OUTPUT);
	}
}

void loop()
{ 
  pot=analogRead(pot_pin);
  led_level=map(pot,0, 1023,0,led_count);
  for(led=0;led<led_count;led++)
  {
    if(led<led_level){
      digitalWrite(led_pin[led],HIGH);
  }
  
   else
  {
      digitalWrite(led_pin[led],LOW);}
  }
}
