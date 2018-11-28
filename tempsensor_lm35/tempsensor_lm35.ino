//Serial.print("The temperature is: ");
//Serial.print(temperature, 2);
//Serial.println(" degrees Celsius");
int redLED = 13; // define which colour LED is in which digital output
int greenLED = 12;
int blueLED = 11;
float sensor = 0;
float heaterOn = 15; // it's ok to turn on the heater if the temperature is below this value
float airconOn = 26;
float voltage = 0; // setup some variables
//float sensor = 0;
float celsius = 0;
float fahrenheit = 0;// it's ok to turn on the air conditioner if the temperature is above this value
void setup()
{
Serial.begin(9600);   // activate the serial output connection
pinMode(redLED, OUTPUT);    // set the digital pins for LEDs to outputs
pinMode(greenLED, OUTPUT);  // not necessary for analogue input pin
pinMode(blueLED, OUTPUT);


}

void loop()
{              // let's get measurin' ABIOLA
sensor = analogRead(0);
Serial.println(sensor);
delay(9600);
voltage = (sensor/1024)*5000; // convert raw sensor value to millivolts
voltage = 400-voltage;        // remove voltage offset
celsius = voltage/10;         // convert millivolts to Celsius
fahrenheit = ((celsius / 1.8)+32); // convert celsius to fahrenheit
Serial.print("Temperature: ");
Serial.print(celsius,2);
Serial.println(" degrees C");
Serial.print("Temperature: ");
Serial.print(fahrenheit,2);
Serial.println(" degrees F");
Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
Serial.println("ABIOLA VALENTINO, TEMP RATING");
digitalWrite(redLED, LOW);    // switch off the LEDs
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);


////
if (celsius>=airconOn)
  {
    digitalWrite(blueLED, HIGH); // ok to turn on the air conditioner
  }
  else if (celsius<=heaterOn)
  {
    digitalWrite(redLED, HIGH);
  }
  else
  {
    digitalWrite(greenLED, HIGH); // everything normal
  }
 delay(1000); // necessary to hold reading, otherwise the sketch runs too quickly and doesn't give the LEDs enough time to

}

