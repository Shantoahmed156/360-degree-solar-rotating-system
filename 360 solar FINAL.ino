
// UITS solar project //
#include <Stepper.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
//#include <Stepper.h>

//defining pins section

int stepIN1Pin = 2;         
int stepIN2Pin = 3;   //down steeper
int stepIN3Pin = 4;
int stepIN4Pin = 5;

int step1Pin = 6;         
int step2Pin = 7; // up steeper
int step3Pin = 8;
int step4Pin = 9;

int steps = 2048; // amount of steps per revolution
int steps2 = 2048;

const int ldr0Pin = 10;  
const int ldr1Pin = 11;  //ldr pin 
const int ldr2Pin = 12; 
const int ldr3Pin = A0;   

int analogInput = A1;  // battery
int analogInput2 = A2; // solar    //current A6
int power= A3;  //relay    // sda A4 scl A5


byte sell[] = {
  B11111,
  B10101,
  B11111,
  B10101,
  B11111,
  B10101,
  B11111,
  B00000
};
byte Batt[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000
};
byte spark[] ={
  B00010,
  B00100,
  B01000,
  B11111,
  B00010,
  B00100, 
  B01000,
  B00000     
};

Stepper myStepper(steps, stepIN1Pin, stepIN3Pin, stepIN2Pin, stepIN4Pin);
Stepper myStepper2(steps2, step1Pin, step3Pin, step2Pin, step4Pin);
void setup() {
  pinMode(analogInput, INPUT);
  pinMode(analogInput2, INPUT);
  pinMode(power,OUTPUT);
  pinMode(ldr0Pin, INPUT);
  pinMode(ldr1Pin, INPUT);
  pinMode(ldr2Pin, INPUT);
  pinMode(ldr3Pin, INPUT);
   

myStepper.setSpeed(10);
myStepper2.setSpeed(5);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, sell);
  lcd.createChar(1, Batt);
  lcd.createChar(2,spark);
  lcd.clear();
  lcd.print("   MPPT CONTROLLER ");
 // onoff();
//  voltage();
//  voltage2(); // FUNCTION ();
// current();
 // lcdd();

 
}


void loop() {

   

 int state0, state1,state2, state3;
 state0 = digitalRead(ldr0Pin);
state1 = digitalRead(ldr1Pin);
  state2 = digitalRead(ldr2Pin);
   state3 = digitalRead(ldr3Pin);

    if ((( state0 == HIGH)||(state1 == HIGH))&&(( state2 == LOW)&&(state3 == LOW))){  
  myStepper.step(steps/64);
 }  
  if((( state2 == HIGH)||(state3 == HIGH))&&(( state0 == LOW)&&(state1 == LOW))) {  
  myStepper.step(-steps/64);
  }

   if ((( state1 == HIGH)&&(state2 == HIGH))&&((state0==LOW)&&(state3==LOW))){ 
  myStepper2.step(-steps2/64);
   }  
  if((( state0== HIGH)&&(state3 == HIGH))&&((state1==LOW)&&(state2==LOW))) { 
  myStepper2.step(steps2/64);
   }
   if ((( state0 == HIGH)&&(state1 == HIGH)&&( state2 == HIGH)&&(state3 == HIGH))||(( state0 == LOW)&&(state1 == LOW)&&( state2 == LOW)&&(state3 == LOW))) {
 
  digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 digitalWrite(9,LOW);

 onoff();
  voltage();
  voltage2(); // FUNCTION ();
  current();
  lcdd();
}
  
  // onoff();
 // voltage();
 // voltage2(); // FUNCTION ();
 // current();
 // lcdd();


}

  
