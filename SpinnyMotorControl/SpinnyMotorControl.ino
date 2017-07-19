#include <Servo.h>

#include <TimerOne.h>

#define CLOCK 16
#define LATCH 15
#define DATA 14

int Numbers[10] = {B00111111,B0000110,B01011011,B01001111,B01100110,B01101101,B01111101,B00000111,B01111111,B01100111};
int x= 0;
int y= 0;
int z= 0;

unsigned int counter = 0;
#define numSpokes 1
int thresh = 115;

int revolutions = 0;
int val = 0;

void addPulse (){
  counter++;
}

void WriteDisplay(int revs){
  int number = revs;
  int temp = 0;
  temp = number/100;
  int x = temp;
  number-=temp*100;
  temp = number/10;
  int y = temp;
  number-=temp*10;
  int z =number;

  digitalWrite(LATCH,LOW);
  shiftOut(DATA,CLOCK,MSBFIRST,byte(Numbers[z]));
  shiftOut(DATA,CLOCK,MSBFIRST,byte(Numbers[y]));
  shiftOut(DATA,CLOCK,MSBFIRST,byte(Numbers[x]));
  //shift
  digitalWrite(LATCH,HIGH);
}

void timerIsr(){
  Timer1.detachInterrupt();
  Serial.print("Wheel Speed: ");
  revolutions = (counter / numSpokes);
  WriteDisplay(constrain(map(revolutions,0,thresh,0,100),0,100));
  Serial.print (revolutions, DEC);
  Serial. println( " Revolutions per second");
  val = map(revolutions,0,thresh,0,4096);
  counter = 0;
  Timer1.attachInterrupt(timerIsr);
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogWriteResolution(12);
    pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(DATA,OUTPUT);

  digitalWrite(CLOCK,LOW);
  digitalWrite(LATCH,HIGH);

  pinMode(2,INPUT);


  Timer1.initialize(1000000);
  attachInterrupt(2,addPulse,RISING);

  Timer1.attachInterrupt(timerIsr);
}

void loop() {

  analogWrite(A14,(int)val);
  // put your main code here, to run repeatedly:
}
