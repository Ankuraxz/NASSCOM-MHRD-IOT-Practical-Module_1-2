int led6=6,led7=7,led8=8,led9=9,led10=10,led11=11,led12=12,led13=13;
int i,j,k,l,m,n,o,p;
void setup()
{
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(led11,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(led13,OUTPUT);
}
void loop()
{
  for (i=0;i<6;i++)
  {
    digitalWrite(led6,1);
    delay(500);
    digitalWrite(led6,0);
    delay(1000);
  }
  for (j=0;j<7;j++)
  {
    digitalWrite(led7,1);
    delay(500);
    digitalWrite(led7,0);
    delay(1000);
  }
  for (k=0;k<7;k++)
  {
    digitalWrite(led8,1);
    delay(100);
    digitalWrite(led8,0);
    delay(100);
  }
  for(l=0;l<8;i++)
  {
    digitalWrite(led9,1);
    delay(500);
    digitalWrite(led9,0);
    delay(1000);
  }
  for(m=0;m<9;m++)
  {
    digitalWrite(led10,1);
    delay(500);
    digitalWrite(led10,0);
    delay(1000);
  }
  for(n=0;n<10;n++)
  {
    digitalWrite(led11,1);
    delay(500);
    digitalWrite(led11,0);
    delay(1000);
  }
  for(o=0;o<11;o++);
  {
    digitalWrite(led12,1);
    delay(500);
    digitalWrite(led12,0);
    delay(1000);
  }
  for(p=0;p<12;p++)
  {
    digitalWrite(led13,1);
    delay(500);
    digitalWrite(led13,0);
    delay(1000);
  }
}
