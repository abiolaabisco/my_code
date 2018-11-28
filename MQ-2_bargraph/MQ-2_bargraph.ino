const int analogPin = A0;    // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph

int ledPins[] = {
  2,3,4,5,6,7,8,9,10,11 // Here we have the number of LEDs to use in the BarGraph
  };   


void setup() {

  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
    Serial.begin(9600);
  }
  }

void loop() {
  //This is the code to light up LED's
  int sensorReading = analogRead(analogPin);
  Serial.println(sensorReading);
  delay(500);

  int ledLevel = map(sensorReading, 200, 800, 0, ledCount);


  for (int thisLed = 0; thisLed < ledCount; thisLed++) {

    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }

    else {
      digitalWrite(ledPins[thisLed], LOW);
    }  
  }
}
