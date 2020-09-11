const int pingPin = 7;
const int buzzer = 9;
void setup(){
  pinMode(buzzer , OUTPUT);
  Serial.begin(9600);
}

void loop(){
  long duration, inches , cm;
  pinMode(pingPin , OUTPUT);  //Ping is triggered
  digitalWrite(pingPin , LOW);
  //delayMicroseconds(1);
  digitalWrite(pingPin , HIGH);
  //delayMicroseconds(10);
  digitalWrite(pingPin , LOW);
  
  pinMode(pingPin , OUTPUT); //Same Pin is used to read signal
  duration = pulseIn(pingPin , HIGH);
  //convert time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  if(inches <= 20.3){
  tone(buzzer , 1000);
  delay(100);
  noTone(buzzer);
  delay(100);
  }
  
  Serial.print(inches);
  Serial.print("inches , ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
