int buttonpin = 1;
void setup() {
 pinMode(buttonpin, INPUT);
 Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
   Serial.println(analogRead(buttonpin));
   delay(1000);// put your main code here, to run repeatedly:

}
