/* Author: Github @Ankuraxz

A photoresistor is a passive component that
decreases resistance with respect to receiving
luminosity on the component's sensitive surface. 
*/
int value=0;
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");

}

void loop()
{
  lcd.setCursor(0, 1);
  value= analogRead(A0);
  if(value<30)
  {
    digitalWrite(13, HIGH); 
    Serial.println("Light ON");
    Serial.println(value);
    lcd.clear();
    lcd.print("STATE");
    lcd.setCursor(0, 1);
    lcd.print("HIGH LED ON");
  }
  else
  {
     digitalWrite(13, LOW);
    Serial.println("Light OFF");
    Serial.println(value);
    lcd.clear();
    lcd.print("STATE");
    lcd.setCursor(0, 1);
    lcd.print("LOW LED OFF");
  }
 delay(100); 
}
