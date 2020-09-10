#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
#include <IRremote.h>
#define led1 8
#define led2 9
#define led3 10

int RECV_PIN = 11;//The definition of the infrared receiver pin 11
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600); //Open serial 
  irrecv.enableIRIn(); // Initialization infrared receiver
  lcd.begin(16, 2);
  lcd.setCursor(2,0);
  lcd.print("ASSIGNMENT 2");
  lcd.setCursor(2,1);
  lcd.print("Press Button");
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
} 

void loop() 
{
  if (irrecv.decode(&results)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Value ");
    lcd.setCursor(5,0);
    lcd.print(results.value);
    switch (results.value) {
                    case 16582903:
            digitalWrite(led1,1);//led1 on button 1
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("ASSIGNMENT 2");
            lcd.setCursor(3,1);
            lcd.print("LED1 IS ON");
            delay(250);
            break;
                    case 16615543:
            digitalWrite(led1,0);//led1 off button 2
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("ASSIGNMENT 2");
            lcd.setCursor(3,1);
            lcd.print("LED1 IS OFF");
            delay(250);
            break;      
                     case 16599223:
            digitalWrite(led2,1);//led2 on button 3
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("ASSIGNMENT 2");
            lcd.setCursor(3,1);
            lcd.print("LED2 IS ON");
            delay(250);
            break;
                      case 16591063:
            digitalWrite(led2,0);//led2 off button 4
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("ASSIGNMENT 2");
            lcd.setCursor(3,1);
            lcd.print("LED2 IS OFF");
            delay(250);
            break;
                      case 16623703:
            digitalWrite(led3,1);//led3 on button 5
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("ASSIGNMENT 2");
            lcd.setCursor(3,1);
            lcd.print("LED3 IS ON");
            delay(250);
            break;
                      case 16607383:
            digitalWrite(led3,0);//led3 off button 6
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("ASSIGNMENT 2");
            lcd.setCursor(3,1);
            lcd.print("LED3 IS OFF");
            delay(250);
            break;
           }
 
    irrecv.resume();
  }
}
