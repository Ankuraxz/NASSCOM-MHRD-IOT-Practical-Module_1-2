int temp = 0;

void setup()
{
  pinMode(A1, INPUT); // TMP36 connected to Analog pin A1
  Serial.begin(9600);
  pinMode(3, OUTPUT); // DC Motor Connected to Digital pin 3
}

void loop()
{
  temp = -40 + 0.488155 * (analogRead(A1) - 20); // Calculates the temperature from the TMP36 sensor readings
  Serial.println(temp); // Prints the value
  if (temp > 30) { // Checks whether the temperature is greater than 30 degrees celcius (can be changed to temperature of choice)
    digitalWrite(3, HIGH); // If yes then spins the motor (fan)
  } else {
    digitalWrite(3, LOW); // else if remains off
  }
}
