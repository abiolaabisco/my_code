void buzz_both(int indicate){
  if(indicate == 0){
    // beep
    for(int i = 0; i < 1; i++){
      digitalWrite(buzzPin, HIGH);
      delay(500);
      digitalWrite(buzzPin, LOW);
      delay(500);
    }
    // check for stability
    while((digitalRead(sensorGen) == HIGH) && (digitalRead(sensorMain) == HIGH)){
      delay(5000);
      break;
    }
    // switch to Main if stable
    while((digitalRead(sensorGen) == HIGH) && (digitalRead(sensorMain) == HIGH)){
      digitalWrite(relayPin, LOW);
      digitalWrite(ignitionPin, HIGH);
    }
    if((digitalRead(sensorMain) == HIGH) && (digitalRead(sensorGen) == LOW)){
      powerMain();
    }
    else if((digitalRead(sensorMain) == LOW) && (digitalRead(sensorGen) == HIGH)){
      buzzer(1);
    }
  }
  if(indicate == 1){
    // beep
    for(int i = 0; i < 2; i++){
      digitalWrite(buzzPin, HIGH);
      delay(500);
      digitalWrite(buzzPin, LOW);
      delay(500);
    }
    // check for stability
    while((digitalRead(sensorGen) == HIGH) && (digitalRead(sensorMain) == HIGH)){
      delay(5000);
      break;
    }
    // switch to Gen if stable
    while((digitalRead(sensorGen) == HIGH) && (digitalRead(sensorMain) == HIGH)){
      digitalWrite(relayPin, HIGH);
      digitalWrite(ignitionPin, LOW);
    }
    if((digitalRead(sensorMain) == HIGH) && (digitalRead(sensorGen) == LOW)){
      buzzer(0);
    }
    else if((digitalRead(sensorMain) == LOW) && (digitalRead(sensorGen) == HIGH)){
      powerGen();
    }
  }
}
