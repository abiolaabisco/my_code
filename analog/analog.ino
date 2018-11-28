const int sensor = A1;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(sensor));
}
