#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeMono9pt7b.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);



const int ping_sen = 11;
const int led=8;
const int buzz=10;
long duration, inches, cm;

void setup() {
  Serial.begin(115200);

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
    }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);

  pinMode(led,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(ping_sen, OUTPUT);
}

void loop() {

  digitalWrite(ping_sen, LOW);
  delayMicroseconds(2);
  digitalWrite(ping_sen, HIGH);
  delayMicroseconds(5);
  digitalWrite(ping_sen, LOW);
  pinMode(ping_sen, INPUT);
  duration = pulseIn(ping_sen, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  display.clearDisplay();
  display.setFont(&FreeSerif9pt7b);
  display.setTextSize(1);
  display.print("Distance(inches):- ");
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(0.75);
  display.println(inches);
  display.setFont(&FreeSerif9pt7b);
  display.setTextSize(1);
  display.println("Distance(cms):- ");
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(0.75);
  display.println(cm);
  if (cm>10 && cm<300){
    digitalWrite(led,HIGH);
    digitalWrite(buzz,HIGH);
    display.println("Motion Detected");
    delay(200);
    }
  else{
    digitalWrite(led,LOW);
    digitalWrite(buzz,LOW);
    display.println("Motion Not Detected");
    delay(200);
  }
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
