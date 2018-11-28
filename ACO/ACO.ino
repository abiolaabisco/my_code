const int sensorGen = 2;
const int sensorMain = 3;
const int relayPin = 5;
const int ignitionPin = 6;
const int buzzPin = 7;

void buzzer(int indicator);
void buzz_both(int indicate);
void powerMain();
void powerGen();

void setup() {
  // initialize pins
  pinMode(sensorGen, INPUT);
  pinMode(sensorMain, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(ignitionPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);

  if(digitalRead(sensorMain) == HIGH){
    powerMain();
  }
  else if(digitalRead(sensorGen) == HIGH){
    buzzer(1);
  }
}

void loop() {
  
}
