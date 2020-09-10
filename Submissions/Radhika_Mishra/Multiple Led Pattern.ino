void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  digitalWrite(11, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(11, LOW);
  delay(500);
  
  digitalWrite(10, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(10, LOW);
  delay(500);
  
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(500);
  
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  delay(500);
  }
