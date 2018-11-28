/*
 Justus First Program
 */

int ledPin = 9;
String str = "value = ";
void increment();
void decrement();

void setup()
{
  // initialize pin  
  pinMode(ledPin, OUTPUT);
  // initialize serial communication
  Serial.begin(9600);
}

void loop()
{
  increment();
  decrement();
  // hold at off
  analogWrite(ledPin, 0);
  delay(1000);
}

void increment()
{
  int val;
  // Blink incrementally
  for (int i = 0; i < 257; i+=32)
  {
    if(i == 0) val = 0;
    else val = i - 1;
    Serial.print(str);
    Serial.println(val);
    analogWrite(ledPin, i);
    delay(1000);
  }
}

void decrement()
{
  // Blink decrementally
  int val;
  for (int i = 0; i < 225; i+=32)
  {
    if(i == 224) val = 223;
    else val = 223 - i;
    Serial.print(str);
    Serial.println(val);
    analogWrite(ledPin, val);
    delay(1000);
  }
}
