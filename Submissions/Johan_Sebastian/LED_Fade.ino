int ledPin = 9;    // LED connected to digital pin 9
int fadeValue = 0; // fadeValue is set to 0

void setup() {
Serial.begin(9600);
}

void loop() {

  while (fadeValue != 225) { // until the fadeValue reaches 225 the loop will run
    fadeValue += 5; // as long as fadeValue is not 225 it will increase the value by 10
    analogWrite(ledPin, fadeValue); // each time the loop runs, it will update the brightness of the LED
    Serial.print('LED Brightness: ');
    Serial.print(fadeValue); // It will print the fadeValue in the serial monitor
    delay(100);

  }

  while (fadeValue != 0) { // until the fadeValue reaches 0 the loop will run
    fadeValue -= 5; // as long as fadeValue is not 0 it will decrease the value by 10
    analogWrite(ledPin, fadeValue); // each time the loop runs, it will update the brightness of the LED
    Serial.print('LED Brightness: ');
    Serial.print(fadeValue); // It will print the fadeValue in the serial monitor
    delay(100);

  }
}
