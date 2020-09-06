/* Author: Github @Ankuraxz

A photoresistor is a passive component that
decreases resistance with respect to receiving
luminosity on the component's sensitive surface. 
*/
int value=0;
int lumen =0;
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");

}

void loop()
{
  lcd.setCursor(0, 1);
  value= analogRead(A0);
  lumen = 255- (map(value,0,942,0,255));
  analogWrite(9, lumen);
  if(value<395)
  {
    //analogWrite(9, lumen); 
    Serial.println("Light ON");
    Serial.println(value);
    lcd.clear();
    lcd.print("STATE");
    lcd.setCursor(0, 1);
    lcd.print("HIGH BULB ON");
  }
  else
  {
    //analogWrite(9, lumen); 
    Serial.println("Light OFF");
    Serial.println(value);
    lcd.clear();
    lcd.print("STATE");
    lcd.setCursor(0, 1);
    lcd.print("LOW BULB OFF");
  }
 delay(100); 
}
