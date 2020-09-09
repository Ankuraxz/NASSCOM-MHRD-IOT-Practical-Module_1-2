int y;
void setup()
{
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}
void loop()
  {for(y=6;y<=13;y++)
    {
      digitalWrite(y,1);
      delay(500);
      digitalWrite(y,0);
      delay(1000);
    }
  }
