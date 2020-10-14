void setup()
{
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int value=analogRead(A0);
  Serial.println(value);
  if(value>400)
  {
    digitalWrite(3,HIGH);
  }
  else
  {
    digitalWrite(3,LOW);
  }
  delay(1000);
}
