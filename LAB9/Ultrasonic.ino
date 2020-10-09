int sensor=7;
int red=13;
const int blue=10;
int green=9;
void setup()
{
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  pinMode(7,OUTPUT);
  Serial.begin(9600);
}
long duration,inches,cm;
void loop()
{
  
  pinMode(sensor,OUTPUT);
  digitalWrite(sensor,LOW);
  delay(2);
  digitalWrite(sensor,HIGH);
  delay(5);
  digitalWrite(sensor,LOW);
  
  
  pinMode(sensor,INPUT);
  duration=pulseIn(sensor,HIGH); //reading duration for a HIGH puise
  
  //time -> distance
  
  inches=microsecondsToInches(duration);
  cm=microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("Cm, ");
  Serial.println();
  
  if(inches<10)
  {
    digitalWrite(red,HIGH);
   digitalWrite(green,LOW);
   digitalWrite(blue,LOW);
  }
  else if (inches>10 && inches<50)
  {
   digitalWrite(red,LOW);
   digitalWrite(green,LOW);
    digitalWrite(blue,HIGH); 
  }
  
  else
  { 
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    
    digitalWrite(blue,LOW); 
  }
}

long microsecondsToInches(long microseconds)
{
   return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
