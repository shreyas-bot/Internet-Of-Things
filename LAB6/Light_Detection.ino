int ldr=A0;
int ldrvalue=0;
int light_sensitivity =500;
void setup()
{
Serial.begin(9600);
  pinMode(13,OUTPUT);
}
void loop()
{
  ldrvalue=analogRead(ldr);
  Serial.println(ldrvalue);
  delay(50);
  if(ldrvalue<light_sensitivity)
  {
   digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
delay(1000);
}
