int inch = 0;
int buzz2=9;
int cm = 0;

long readDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
   pinMode(buzz2, OUTPUT);
}

void loop()
{
  cm = 0.01723 * readDistance(7, 7);
  inch = (cm / 2.54);
  Serial.print(inch);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  if(cm>=120){
    digitalWrite(buzz2, HIGH);
  }
  else{
  digitalWrite(buzz2, LOW);
  }
  delay(100); 
}
