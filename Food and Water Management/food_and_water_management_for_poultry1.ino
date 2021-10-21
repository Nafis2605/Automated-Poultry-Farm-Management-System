

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int cm = 0;
int pump = 8;
int read=0;
bool  STOP_pump = HIGH ;
bool  RUN_pump = LOW ;

void setup()
{
  Serial.begin(9600);
  pinMode(pump,OUTPUT);
  lcd.begin(16, 2);
  digitalWrite(pump,RUN_pump);
  

}

void loop()
{
  read= readUltrasonicDistance(7, 7);
  
  // measure the ping time in cm
  cm = 0.01723 * read;
  // convert to inches by dividing by 2.54
  int level = map(cm, 400 , 10, 0 , 100);
  lcd.setCursor(0, 0);
  lcd.print( "Food Completed");
  lcd.setCursor(0, 1);
  lcd.print(level);

  lcd.setCursor(3, 1);
  lcd.print("%");
  lcd.print(" ");
  delay(1000);
  
  
  
  
   
  if( level < 85)  {
    
    digitalWrite(pump,RUN_pump);
   
  }
  
  else {
   digitalWrite(pump,STOP_pump); // this is for safety in case.

  }
  

  
}


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
 
  return pulseIn(echoPin, HIGH);
}















