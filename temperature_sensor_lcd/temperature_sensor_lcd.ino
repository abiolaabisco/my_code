




#include <Adafruit_LiquidCrystal.h>
#include <Wire.h>
#include <DHT_U.h>
dht_DHT11
#include "DHT.H"
#define DHT11_PIN
sensorPin = 7;
int reading  = 0;
int outputpin = 0;
int sensorPin =A0;
int relay = 7;
const int numRows = 2;
const int numCols = 16;
//initialize the library with the numbers of the interface pinz
Adafruit_LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  
  Serial.begin(9600);
  lcd.begin(numCols, numRows);
  lcd.print("Tempe: ");
  pinMode(relay,OUTPUT);
}

//this the main loop writen by abisco
void loop()
{
  reading = analogRead(sensorPin);
  int celsius= reading/2;
  lcd.setCursor(0, 0);
  lcd.print("Temp");
  lcd.setCursor(0,1);
  lcd.print(celsius, DEC);
  lcd.print((char)223);
  lcd.print("c");
  if (celsius>35) {
    digitalWrite(7,HIGH);
  }else{
    digitalWrite(7,LOW);
    
  }
  delay(5000);
  lcd.clear();
  int rawvoltage = analogRead(outputpin);
  float millivolts = (rawvoltage/1024.0)*5000;
  float fahrenheit = millivolts/10;
  Serial.available();
  lcd.print(fahrenheit);
  lcd.print("F");
 lcd.print("THESE PRO");
 lcd.print("JOSH");
 lcd.print("ABIOLA");
  delay(5000);
  Serial.available();
   // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  
}


