/* Author: Github @Ankuraxz
*/ 
int sensorState = 0;
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
void setup()
{
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");

}

void loop()
{
  lcd.setCursor(0, 1);
  // read the state of the sensor/digital input
  sensorState = digitalRead(2);
  // check if sensor pin is HIGH. if it is, set the
  // LED on.
  if (sensorState == HIGH)
  {
    lcd.clear();
    lcd.print("STATE");
    lcd.setCursor(0, 1);
    lcd.print("HIGH");
    digitalWrite(13, HIGH);
    Serial.println("Sensor activated!");
  } 
  else 
  {
    lcd.clear();
    lcd.print("STATE");
    lcd.setCursor(0, 1);
    lcd.print("LOW");
    digitalWrite(13, LOW);
    Serial.println("Sensor deactivated!");
  }
  delay(10); 
}
