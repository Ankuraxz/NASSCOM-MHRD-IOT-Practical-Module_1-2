void setup()
{
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  digitalWrite(11, HIGH);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  delay(150); // Wait for 1000 millisecond(s)
  digitalWrite(6, HIGH);
  delay(450); // Wait for 1000 millisecond(s)
  digitalWrite(6, LOW);
  delay(300); // Wait for 1000 millisecond(s)
}
