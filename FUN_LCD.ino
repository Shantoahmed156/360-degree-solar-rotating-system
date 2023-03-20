
//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,20,4);

//int analogInput = A0; 
//int analogInput2 = A1;
//int power= 13;
/*byte sell[] = {
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
*/
//void setup() {
 // pinMode(analogInput, INPUT);
  //pinMode(power,OUTPUT);
 // lcd.init();                      // initialize the lcd 
 // lcd.init();
 // lcd.backlight();
 // lcd.createChar(0, sell);
 // lcd.createChar(1, Batt);
 // lcd.createChar(2,spark);
 // lcd.clear();
 // lcd.print("   MPPT CONTROLLER ");
//}
//void loop() {
 // voltage();
 // voltage2();
  //current();
 void lcdd(){
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(0, 2);
  lcd.write(byte(1));
lcd.setCursor(0, 3);
lcd.write(byte(2));
lcd.setCursor(1, 3);
  lcd.write(byte(2));

  }
//}
