int brightness=0;
void setup()
{
  pinMode(11, OUTPUT);
}

void loop()
{
  for(brightness=0; brightness<=255; brightness+=5)
  {
 analogWrite(11, brightness);
 delay(15);
  }
  for(brightness=255; brightness>=0; brightness-=5)
  {
    analogWrite(11, brightness);
 delay(15);
  }
} 
