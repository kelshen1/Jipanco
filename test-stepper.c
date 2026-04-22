/*==========================================================================
// Author : Handson Technology
// Project : Arduino Uno
// Description : TB6600 Stepper Motor Driver
// Source-Code : tb6600.ino
//==========================================================================
*/
int PUL=19; //define Pulse pin
int DIR=18; //define Direction pin
int ENA=5; //define Enable Pin
void setup() {
 pinMode (PUL, OUTPUT);
 pinMode (DIR, OUTPUT);
 pinMode (ENA, OUTPUT);
}

void loop() {
 for (int i=0; i<6400; i++) //Forward 5000 steps
 {
 digitalWrite(DIR,LOW);
 digitalWrite(ENA,HIGH);
 digitalWrite(PUL,HIGH);
 delayMicroseconds(50);
 digitalWrite(PUL,LOW);
 delayMicroseconds(50);
 }
 for (int i=0; i<6400; i++) //Backward 5000 steps
 {
 digitalWrite(DIR,HIGH);
 digitalWrite(ENA,HIGH);
 digitalWrite(PUL,HIGH);
 delayMicroseconds(50);
 digitalWrite(PUL,LOW);
 delayMicroseconds(50);
 }
}
