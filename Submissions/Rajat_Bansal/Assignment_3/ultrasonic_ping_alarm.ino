const int pingPin = 7;
int const led1=8;
int const led2=9;
int const buzz=10;
int brightness=0;
int fadeAmount=5;

void setup() {
  Serial.begin(9600);
}

void loop() {

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(buzz,OUTPUT);
  long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm<100){
    analogWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(buzz,HIGH);
  }
  else{
    analogWrite(led2,LOW);
    digitalWrite(led1,HIGH);
    digitalWrite(buzz,LOW);
  }
  delay(100);
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
