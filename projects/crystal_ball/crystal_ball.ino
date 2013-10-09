#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const short switchPin = 6;
const short tempPin = A0;

float temperature = 0;

void setup() {
  lcd.begin(16,2);
  lcd.print("Ask Me");
  lcd.setCursor(0,1);
  lcd.print("Anything!");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("Temperatuur:");
}

void loop() {
  temperature = (temperature + ((((analogRead(tempPin)/1024.0)*5.0) - .5) * 100) + 3)/2;
  
  lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.print(" ");
  lcd.print(char(176));
  lcd.print("C");
  delay(3000);
}
