#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(115200);
}

void loop() {
  // read the input on analog pin 0:
  int rain = analogRead(A0);
  Serial.println(rain);
  if (rain <= 164) {
    lcd.setCursor(0, 0);
    lcd.print("  Dry Weather   ");
    Serial.println("Dry Weather");
    lcd.setCursor(0, 1);
    lcd.print("    No Rain    ");
   }
  if ((rain > 165) && (rain <= 327)) {
    Serial.println("Dew or Heavy Mist ");
    lcd.setCursor(0, 0);
    lcd.print("     Dew or     ");
    lcd.setCursor(0, 1);
    lcd.print("   Heavy Mist   ");
   }
  if ((rain > 328) && (rain <= 511)) {
    Serial.println("Light Rain");
    lcd.setCursor(0, 0);
    lcd.print("  Wet Weather   ");
    lcd.setCursor(0, 1);
    lcd.print("   Light Rain   ");
  }
  if ((rain > 512) && (rain <= 696)) {
    Serial.println("Moderate Rain");
    lcd.setCursor(0, 0);
    lcd.print("  Wet Weather   ");
    lcd.setCursor(0, 1);
    lcd.print(" Moderate Rain  ");
  }
  if ((rain > 697) && (rain <= 854)) {
    Serial.println("Heavy Rain");
    lcd.setCursor(0, 0);
    lcd.print("  Wet Weather   ");
    lcd.setCursor(0, 1);
    lcd.print("   Heavy Rain   ");
  }
  if (rain > 855) {
    Serial.println("Very Heavy Rain");
    lcd.setCursor(0, 0);
    lcd.print("  Wet Weather   ");
    lcd.setCursor(0, 1);
    lcd.print("Very Heavy Rain");
   }
  
  delay(100);
}