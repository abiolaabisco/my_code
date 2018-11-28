void buzzer(int indicator){
  if(indicator == 1){
    // beep
    for(int i = 0; i < 3; i++){
      digitalWrite(buzzPin, HIGH);
      delay(500);
      digitalWrite(buzzPin, LOW);
      delay(500);
    }
    // check for stability
    while(digitalRead(sensorGen) == HIGH){
      delay(5000);
      break;
    }
    // switch to Generator if stable
    if(digitalRead(sensorGen) == HIGH){
      powerGen();
    }
    // return to Main if unstable
    else powerMain();
  }
  
  else if(indicator == 0){
    // beep
    for(int i = 0; i < 2; i++){
      digitalWrite(buzzPin, HIGH);
      delay(500);
      digitalWrite(buzzPin, LOW);
      delay(500);
    }
    // check for stability
    while(digitalRead(sensorMain) == HIGH){
      delay(5000);
      break;
    }
    // switch to Main if stable
    if(digitalRead(sensorMain) == HIGH){
      powerMain();
    }
    // return to Gen if unstable
    else powerGen();
  }
}
