void powerGen(){
  while((digitalRead(sensorGen) == HIGH) && (digitalRead(sensorMain) == LOW)){
    digitalWrite(relayPin, HIGH);
    digitalWrite(ignitionPin, LOW);
  }
  if((digitalRead(sensorGen) == HIGH) && (digitalRead(sensorMain) == HIGH)){
    buzz_both(0);
  }
  else if((digitalRead(sensorMain) == HIGH) && (digitalRead(sensorGen) == LOW)){
    buzzer(0);
  }
}

void powerMain(){
  while((digitalRead(sensorMain) == HIGH) && (digitalRead(sensorGen) == LOW)){
    digitalWrite(relayPin, LOW);
    digitalWrite(ignitionPin, HIGH);
  }
  if((digitalRead(sensorMain) == HIGH) && (digitalRead(sensorGen) == HIGH)){
    buzz_both(1);
  }
  else if((digitalRead(sensorGen) == HIGH) && (digitalRead(sensorMain) == LOW)){
    buzzer(1);
  }
}
