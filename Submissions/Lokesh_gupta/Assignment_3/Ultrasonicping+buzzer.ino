
int inches = 0;

int cm = 0;

int sensorReading = 0;

long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);  // Clear the trigger
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // Sets the pin on HIGH state for 10 micro seconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  // Reads the pin, and returns the sound wave travel time in microseconds
  return pulseIn(pin, HIGH);
}

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop()
{
  // read the sensor
  sensorReading = readUltrasonicDistance(A0);
  // print the sensor reading so you know its range
  Serial.println(sensorReading);
  // map the sensor reading to a range for the
  // speaker
  tone(9, 440 * pow(2.0, (constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000 / 2);
  delay(10); // Delay a little bit to improve simulation performance
}
