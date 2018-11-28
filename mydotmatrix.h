
int latchPin = 8; //Pin connected to Pin 12 of 74HC595 (Latch)
int clockPin = 12; //Pin connected to Pin 11 of 74HC595 (Clock)

int dataPin = 11; //Pin connected to Pin 14 of 74HC595 (Data)
String Str;
byte alphabets[][8] =
{  {0,0,0,0,0},
  {0,56,125,56,0},//!
  {80,96,0,80,96},//"
  {20,127,20,127,20},//#
  {18,42,127,42,36},//$
  {98,100,8,19,35},//%
  {54,73,85,34,5},//&
  {0,80,96,0,0},//'(7)
  {0,28,34,65,0},//(
  {0,65,34,28,0},//)
  {20,8,62,8,20},//*
  {8,8,62,8,8},//+
  {0,5,6,0,0},//,(12)
  {8,8,8,8,8},//-
  {0,3,3,0,0},//.(14)
  {2,4,8,16,32},///
  {62,69,73,81,62},//0
  {17,33,127,1,1},//1
  {33,67,69,73,49},//2
  {34,65,73,73,54},//3
  {12,20,36,127,4},//4
  {114,81,81,81,78},//5
  {62,73,73,73,38},//6
  {64,71,72,80,96},//7
  {54,73,73,73,54},//8
  {50,73,73,73,62},//9
  {0,54,54,0,0},//:(26)
  {0,53,54,0,0},//;(27)
  {8,20,34,65,0},//<
  {20,20,20,20,20},//=
  {0,65,34,20,8},//>
  {32,64,69,72,48},//?
  {62,73,87,85,62},//@
  {31, 36, 68, 36, 31},//A
  {127, 73, 73, 73, 54},//B
  {62, 65, 65, 65, 34},//C
  {127, 65, 65, 34, 28},//D
  {127, 73, 73, 65, 65},//E
  {127, 72, 72, 72, 64},//F
  {62, 65, 65, 69, 38},//G
  {127, 8, 8, 8, 127},//H
  {65, 65, 127, 65, 65},//I
  {2, 1, 1, 1, 126},//J
  {127, 8, 20, 34, 65},//K
  {127, 1, 1, 1, 1},//L
  {127, 32, 16, 32, 127},//M
  {127, 16, 8, 4, 127},//N
  {62, 65, 65, 65, 62},//O
  {127, 72, 72, 72, 48},//P
  {62, 65, 69, 66, 61},//Q
  {127, 72, 76, 74, 49},//R
  {50, 73, 73, 73, 38},//S
  {64, 64, 127, 64, 64},//T
  {126, 1, 1, 1, 126},//U
  {124, 2, 1, 2, 124},//V
  {126, 1, 6, 1, 126},//W
  {99, 20, 8, 20, 99},//X
  {96, 16, 15, 16, 96},//Y
  {67, 69, 73, 81, 97},//Z
  {0,127,65,65,0},//[
  {32,16,8,4,2},//
  {0,65,65,127,0},
  {16,32,64,32,16},//^
  {1,1,1,1,1},//_
  {0,64,32,16,0},//`
  {2,21,21,14,1},//a
  {64,126,9,17,14},//b
  {14,17,17,17,10},//c
  {14,17,74,127,1},//d
  {14,21,21,21,9},//e
  {1,9,63,72,32},//f
  {9,21,21,21,30},//g
  {127,8,8,8,7},//h
  {0,0,46,1,1},//i
  {2,1,1,1,94},//j
  {1,127,4,10,17},//k
  {0,65,127,1,0},//l
  {31,16,14,16,31},//m
  {31,8,16,16,15},//n
  {14,17,17,17,14},//o
  {127,20,20,20,8},//p
  {8,20,20,31,1},//q
  {31,8,16,16,8},//r
  {9,21,21,21,18},//s
  {16,16,126,17,18},//t
  {30,1,1,30,1},//u
  {28,2,1,2,28},//v
  {30,1,6,1,30},//w
  {17,10,4,10,17},//x
  {16,9,6,8,16},//y
  {17,19,21,25,17},//z
  {8,54,65,65,0},//{
  {0,0,127,0,0},//|(92)
  {0,65,65,54,8},//}
  {32,64,32,16,32},//~

  
  
};

int M[8],ap,ai,space=0;


void setup() {
  Serial.begin(9600);
pinMode(latchPin, OUTPUT); // set the 3 digital pins to outputs
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
//Timer1.initialize(10000); // set a timer of length 10000 microseconds
//Timer1.attachInterrupt(screenUpdate); // attach the screenUpdate function
}
void loop() {
 while (Serial.available()) {
  delay(1000000);
  if (Serial.available() >0) {
 char c = Serial.read();
  Str+= c;}
    }
  Str="ABIOLA";
  for(int t=0;t<2;t++)
  { 
  text();
  ai=0;
  for(byte ap=0;ap<=6;ap++)
  {  M[7]=alphabets[ai][ap];
    for(byte i=0;i<7;i++)
    M[i]=M[i+1];

  screenUpdate(250);
  }
  ap=0;
  }
 if (Str.length() >0) 
  {
  Serial.println("A B I O L A");
  Str="";
  delay(9600);
  }
}
void screenUpdate(unsigned long frametime) 
{ // function to display image

  unsigned long startime=millis();
  while(millis()-startime<frametime)
  {
    byte row = B0000001; // row 1
    for (byte k = 0; k < 8; k++) 
    {
      digitalWrite(latchPin, LOW); // open latch ready to receive data
      shiftIt(row); // row binary number
      shiftIt(~M[k] ); // LED array (inverted)

      // Close the latch, sending the data in the registers out to the matrix
      digitalWrite(latchPin, HIGH);
      row = row<< 1; // bitshift right
    }
  } 
}

void shiftIt(byte dataOut) {
// Shift out 8 bits LSB first, on rising edge of clock
boolean pinState;

//clear shift register read for sending data
digitalWrite(dataPin, LOW);
// for each bit in dataOut send out a bit
for (int i=0; i<8; i++) {
//set clockPin to LOW prior to sending bit
digitalWrite(clockPin, LOW);
// if the value of DataOut and (logical AND) a bitmask
// are true, set pinState to 1 (HIGH)
if ( dataOut & (1<<i) ) {
pinState = HIGH;
}
else {
pinState = LOW;
}
//sets dataPin to HIGH or LOW depending on pinState
digitalWrite(dataPin, pinState);
//send bit out on rising edge of clock
digitalWrite(clockPin, HIGH);
digitalWrite(dataPin, LOW);
}
digitalWrite(clockPin, LOW); //stop shifting
}

void text()
{
  int i=0;
  while (Str[i]!=NULL)
  {
     ai=Str[i]-'!'+1;
   if(ai==0)
    {
      for(byte i=0;i<7;i++)
      M[i]=M[i+1];
      screenUpdate(250);
      ap=5;
    }
  if(ai==1)
    {
    for(ap=1;ap<=3;ap++)
    { 
     for(byte i=0;i<7;i++)
    M[i]=M[i+1];
    M[7]=alphabets[ai][ap];
    screenUpdate(250);
    }
   ap=5;
    }
    if(ai==7)
    {
      for(ap=1;ap<=2;ap++)
    { 
      for(byte i=0;i<7;i++)
    M[i]=M[i+1];
    M[7]=alphabets[ai][ap];
    screenUpdate(250);
    }
   ap=5;
    }
    if(ai==12)
    {
    for(ap=1;ap<=3;ap++)
    {    
    for(byte i=0;i<7;i++)
    M[i]=M[i+1];
    M[7]=alphabets[ai][ap];
    screenUpdate(250);
    }
   ap=5;
    }
  if(ai==14)
    {
    for(ap=1;ap<=3;ap++)
    {    
    for(byte i=0;i<7;i++)
    M[i]=M[i+1];
    M[7]=alphabets[ai][ap];
    screenUpdate(250);
    }
   ap=5;
    }
    if(ai==26)
    {
    for(ap=1;ap<=3;ap++)
    {    
    for(byte i=0;i<7;i++)
    M[i]=M[i+1];
    M[7]=alphabets[ai][ap];
    screenUpdate(250);
    }
   ap=5;
    }
        if(ai==27)
    {
    for(ap=1;ap<=3;ap++)
    {    
    for(byte i=0;i<7;i++)
    M[i]=M[i+1];
    M[7]=alphabets[ai][ap];
    screenUpdate(250);
    }
   ap=5;
    }
        if(ai==92)
    {
    for(ap=2;ap<=3;ap++)
    {    
    for(byte i=0;i<7;i++)
    M[i]=M[i+1];
    M[7]=alphabets[ai][ap];
    screenUpdate(250);
    }
   ap=5;
    }
   for(int i=0;i<7;i++)
    {

     M[i]=M[i+1];
    }
   if(ap==5)
    {
      M[7]=0;
      ap=0;
      ai=Str[++i]-'!'+1;
    }
   else
   {
      M[7]=alphabets[ai][ap++];
   }
   screenUpdate(250);

  }

}

