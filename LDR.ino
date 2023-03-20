int ldr0=A0;
int ldr1=A1;
int ldr2=A2;
int ldr3=A3;

void setup() {
// pinMode(A0,INPUT);
 //pinMode(A1,INPUT);
// pinMode(A4,INPUT);
// pinMode(A5,INPUT);
 Serial.begin(9600);
}

void loop() {
  ldr0=digitalRead(A0);
  ldr1=digitalRead(A1);
  ldr2=digitalRead(A2);
  ldr3=digitalRead(A3);
  //ldr0=map(ldr0,0,1000,0,10);
  //ldr1=map(ldr1,0,1000,0,10);
  //ldr2=map(ldr2,0,1000,0,10);
  //ldr3=map(ldr3,0,1000,0,10);
  Serial.print("ldr0 : ");
  Serial.println(ldr0);
  Serial.print("ldr1 : ");
  Serial.println(ldr1);
  Serial.print("ldr2 : ");
  Serial.println(ldr2);
  Serial.print("ldr3 : ");
  Serial.println(ldr3);
  

}
