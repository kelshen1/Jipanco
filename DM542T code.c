/*==========================================================================
// Auteur : Khaos "Kelshen" Viracocha
// Project : jipanco - Hermes
// Description : Stepper Motor Driver code
//==========================================================================
*/
int DIR=5; // Direction pin
int PUL=6; // Pulse pin
int ENA=19; // Enable Pin
int REV=1600; // Pulse/Rev
int DLY=30; // Delay between pulses ( min 25 ) 

void setup() {
 pinMode (PUL, OUTPUT);
 pinMode (DIR, OUTPUT);
 pinMode (ENA, OUTPUT);
}

digitalWrite(ENA,LOW); // initialisation
delayMicroseconds(100);

void loop() {
 digitalWrite(DIR,LOW);
 delayMicroseconds(60);
 for (int i=0; i<1600; i++)
 {
 digitalWrite(PUL,HIGH);
 delayMicroseconds(30);
 digitalWrite(PUL,LOW);
 delayMicroseconds(30);
 }
 digitalWrite(DIR,LOW);
 delayMicroseconds(60);
 for (int i=0; i<1600; i++)
 {
 digitalWrite(PUL,HIGH);
 delayMicroseconds(30);
 digitalWrite(PUL,LOW);
 delayMicroseconds(30);
 }
}
