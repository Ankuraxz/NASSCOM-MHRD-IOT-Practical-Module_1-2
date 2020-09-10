#include <IRremote.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int red=9;
int green=13;
int blue=10;
int RECV_PIN = 6;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  lcd.begin(16,2);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("Active Light");
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    
    if(results.value==0xFD08F7){
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(blue,LOW);
      lcd.setCursor(0,1);
      lcd.print("Red  ");
    }
       else if(results.value==0xFD48B7){
      digitalWrite(red,LOW);
      digitalWrite(green,LOW);
      digitalWrite(blue,HIGH);
      lcd.setCursor(0,1);
      lcd.print("Blue  ");
    }
       else if(results.value==0xFD8877){
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(blue,LOW);
      lcd.setCursor(0,1);
      lcd.print("Green");
    }
  }
  delay(100);
}
