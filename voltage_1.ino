
int ch = 0;
float vout = 0.0;
float vin = 0.0;
float vin2 = 0.0;
float R1 = 100000.0; 
float R2 = 10000.0; 
int value = 0;


void voltage( ){
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; 
   vin = vout / (R2/(R1+R2)); 
   ch = map(vin,0,6,0,100);
   if(ch>100){
    ch=100;
   }
   if (vin<0.09) {
   vin=0.0;
   }                        ///BATTERY///
lcd.setCursor(2,2);
lcd.print(vin);
lcd.setCursor(6,2);
lcd.print("V");
lcd.setCursor(4,3);
lcd.print(ch);
lcd.setCursor(7,3);
lcd.print("%");
delay(500);
 }
  void voltage2( ){
   value = analogRead(analogInput2);
   vout = (value * 5.0) / 1024.0; 
   vin2 = vout / (R2/(R1+R2)); 
   if (vin2<0.09){
   vin2=0.0;
   }                       //SOLAR///
lcd.setCursor(2, 1);
lcd.print(vin2);
lcd.setCursor(6, 1);
lcd.print("V");
delay(500);
 }
 //CURRENT//
  void current(){
   float average = 0;
   float I ;
  for(int i = 0; i < 1000; i++) 
  {
   average = average + (.0264 * analogRead(A6) -13.51) / 1000;
   I = average+0.10;
   if((I<0.09)&&(I>-0.09)){
    I=0; 
   }
    delay(1);
  }
  lcd.setCursor(9,1);
 // lcd.setCursor(10,0);     ///CURRENT///
  lcd.print(I);
  delay(500);
  lcd.setCursor(15,1);
  lcd.print("A");
}
void onoff(){
  if((vin<6)&&(vin2>7)){
    digitalWrite(power,HIGH);
  }
  else {
    digitalWrite(power,LOW);
  }
  
}
