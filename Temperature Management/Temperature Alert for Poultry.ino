//CREATED BY GIOVANNI, LUCAS B, LUCAS F & THIAGO.
//WHEN THE TEMPERATURE IS HIGHER THAN 35ºC IT PLAYS ANOTHER SOUND FREQUENCY.

//Include the library code.
#include <LiquidCrystal.h>
//Initialize the library with the numbers of the interface pins.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//This is the Arduino Pin that will read the sensor output.
int sensePin = A0;
//The variable we will use to store the sensor input.
int sensorInput;
//The variable we will use to store temperature in degrees.
double temp;

void setup()
{
  //Pin of the led.
  pinMode(13, OUTPUT);
  
  //Initialize the LCD's number of columns and rows.
  lcd.begin(16, 2);
  
  //Start the Serial Port at 9600 baud (default).
  Serial.begin(9600);
}

void loop()
{  
  //Set the cursor to column 0, line 0
  lcd.setCursor(0, 0);
  
  //Read the analog sensor and store it.
  sensorInput = analogRead(A0);
  //Find percentage of input reading.
  temp = (double)sensorInput / 1024;
  //Multiply by 5V to get voltage.
  temp = temp * 5;
  //Subtract the offset.
  temp = temp - 0.5;
  //Convert to degrees.
  temp = temp * 100;
  
  if (temp > 40)
  {
    //INPUT - FREQUENCY - TIME THAT LASTS
    tone(8, 800, 300);
    delay(250);
    
  	digitalWrite(13, HIGH);
  	delay(500); // Wait for 500 millisecond(s)
  	digitalWrite(13, LOW);
  	delay(500); // Wait for 500 millisecond(s)
    lcd.clear();
    lcd.print(temp);
    lcd.print(" Celsius");
    lcd.setCursor(0, 1);
    lcd.print("Turn on Fan!");
  }
  
  else if (temp < 30)
  {
    //INPUT - FREQUENCY - TIME THAT LASTS
    tone(8, 500, 300);
    delay(500);

    digitalWrite(13, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(13, LOW);
    delay(500); // Wait for 500 millisecond(s)
    
    lcd.clear();
    lcd.print(temp);
    lcd.print(" Celsius");
    lcd.setCursor(0, 1);
    lcd.print("Turn on Heater!");
  }  
  else {
 
    delay(1000);
    
    lcd.clear();
    lcd.print(temp);
    lcd.print(" Celsius");
    lcd.setCursor(0, 1);
    lcd.print("Stable!");
  }

  

}