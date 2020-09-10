int led1=11;
int led2=10;
int led3=9;
int fadevalue=0;
void setup()
{
pinMode (led1,OUTPUT);
pinMode (led2,OUTPUT);
pinMode (led3,OUTPUT);
}

void loop()
{
  for(int fadevalue=0; fadevalue<=255; fadevalue +=5)
  {
    analogWrite(led1, fadevalue);
    delay(1000);
  }
  for(int fadevalue=255; fadevalue>=0; fadevalue -=5)
  {
    analogWrite(led1, fadevalue);
    delay(1000);
  }
  for(int fadevalue=0; fadevalue<=255; fadevalue +=5)
  {
    analogWrite(led2, fadevalue);
    delay(1000);
  }
  for(int fadevalue=255; fadevalue>=0; fadevalue -=5)
  {
    analogWrite(led2, fadevalue);
    delay(1000);
  for(int fadevalue=0; fadevalue<=255; fadevalue +=5)
  {
    analogWrite(led3, fadevalue);
    delay(1000);
  }
  for(int fadevalue=255; fadevalue>=0; fadevalue -=5)
  {
    analogWrite(led3, fadevalue);
    delay(1000);
  }
}
}
