int arr[5]={12, 11, 10, 9, 8};

void setup()
{
  for(int i=0;i<5;i++)
  	pinMode(arr[i], OUTPUT);
}

void loop()
{	
  for(int i=0;i<5;i++){
    /*printf('%d', arr[i]);*/
    digitalWrite(arr[i], HIGH);
    delay(100); // Wait for 1000 millisecond(s)
    digitalWrite(arr[i], LOW);
    delay(100); // Wait for 1000 millisecond(s)
  }
}
