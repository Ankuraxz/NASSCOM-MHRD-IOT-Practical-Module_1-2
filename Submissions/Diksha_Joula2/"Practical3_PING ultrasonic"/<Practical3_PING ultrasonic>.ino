int inches=0;
int cn=0;
long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  return pulseIn(pin, HIGH);
}

void setup()
{
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop()
{
  cn=0.01723 * readUltrasonicDistance(7);
  inches=(cn / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cn);
  Serial.println("cn");
  delay(1000);
}
