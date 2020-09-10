void setup() 
{
 pinMode(8, OUTPUT); 
  }
void loop()
{
  tone(8,500);
  delay(1000);
  noTone(8);
  delay(1000);
}
