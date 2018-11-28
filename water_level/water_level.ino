#include <LiquidCrystal.h>

const int sensor = A1;
LiquidCrystal lcd(2,3,4,5,6,7);
void setup()
{
  pinMode(sensor, INPUT);
  lcd.begin(16, 2);
}
void loop()
{
  lcd.setCursor(0, 0);
  height = calcHeight()
  lcd.println(height);
  
}
int calcHeight()
{
  int value = analogRead(sensor);
  Vout = map(value, j, k, 0, l);
  return Vout;
}

