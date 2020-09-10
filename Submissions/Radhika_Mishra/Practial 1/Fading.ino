int brightness = 0;
void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  for(brightness = 0; brightness <= 255; brightness += 5)
  {
  analogWrite(9, brightness);
  delay(50); // Wait for 50 millisecond(s)
  }
  for(brightness = 255; brightness >0; brightness -= 5)
  {
  analogWrite(9, brightness);
  delay(50); // Wait for 50 millisecond(s)
  }
}
