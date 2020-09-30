  
int outputpin=0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int rawvoltage=analogRead(outputpin);
  float millivolts=(rawvoltage/1024.0)*5000;
  int tempc=millivolts/10;
  int tempf=((tempc*9)/5 + 32);
  Serial.println("Temperature:");
  Serial.print("Celsius:");
  Serial.println(tempc);
  Serial.print("Fahrenheit:");
  Serial.println(tempf);
  delay(2000);
}
