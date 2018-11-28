#include <AFMotor.h>

#define echoPin 13
#define trigPin 2

AF_DCMotor backleft(1);
AF_DCMotor backright(2);
AF_DCMotor frontleft(4);
AF_DCMotor frontright(3);

int s = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  pinMode(echoPin, OUTPUT);
  pinMode(trigPin,INPUT);

  /*
  Stop();
 
  delay(2000);
  Forward();
  delay(2000);
  Backward();
  delay(2000);
  Stop();
  */
 
}

void Forward()
{
    backleft.setSpeed(240);
    backright.setSpeed(240);

   
    frontleft.setSpeed(240);
    frontright.setSpeed(240);
   
    backleft.run(FORWARD);
    backright.run(FORWARD);
    frontleft.run(FORWARD);
    frontright.run(FORWARD);
}

void Backward()
{
    backleft.setSpeed(240);
    backright.setSpeed(240);
   
    frontleft.setSpeed(240);
    frontright.setSpeed(240);
   
    backleft.run(BACKWARD);
    backright.run(BACKWARD);
    frontleft.run(BACKWARD);
    frontright.run(BACKWARD);
}

void Left()
{
    backleft.setSpeed(240);
    backright.setSpeed(240);

   
    frontleft.setSpeed(60);
    frontright.setSpeed(240);
   
    //backleft.run(FORWARD);
    //backright.run(BACKWARD);
    frontleft.run(FORWARD);
    //frontright.run(BACKWARD);
}

void Right()
{
    backleft.setSpeed(240);
    backright.setSpeed(240);

   
    frontleft.setSpeed(240);
    frontright.setSpeed(60);
   
    //backleft.run(FORWARD);
    //backright.run(BACKWARD);
    //frontleft.run(FORWARD);
    frontright.run(FORWARD);
}

void Stop()
{
    backleft.run(RELEASE);
    backright.run(RELEASE);
    frontleft.run(RELEASE);
    frontright.run(RELEASE);
}

void loop()
{
    Forward();
    delay(2000);
    Left();
    delay(100);
    Right();
    delay(100);
    Backward();
    delay(2000);

    int ss = Serial.read();
    if ((ss < 1) && (ss < 5)){
      while ((ss < 1) && (ss < 5)){
        Stop();
      }
    }
    else s = ss;

    if (s == 1){
      while(s == 1){
        Forward();
      }
      loop();
    }
    else if (s == 2){
      while(s == 2){
        Left();
      }
      loop();
    }
    else if (s == 3){
      while(s == 3){
        Right();
      }
      loop();
    }
    else if (s == 4){
      while(s == 4){
        Backward();
      }
      loop();
    }
    else if (s == 5){
      while(s == 5){
        Stop();
      }
      loop();
    }
}

