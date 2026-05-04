/*==========================================================================
// Auteur : Khaos "Kelshen" Viracocha
// Project : jipanco - Hermes
// Description : DM860Y Stepper Motor Driver
//==========================================================================
*/
int PUL=19; // Pulse pin
int DIR=18; // Direction pin
int ENA=5; // Enable Pin
void setup() {
 pinMode (PUL, OUTPUT);
 pinMode (DIR, OUTPUT);
 pinMode (ENA, OUTPUT);
}

digitalWrite(ENA,HIGH); // initialisation
delayMicroseconds(100);

void loop() {
 digitalWrite(DIR,LOW);
 delayMicroseconds(60);
 for (int i=0; i<6400; i++) //Forward 5000 steps
 {
 digitalWrite(PUL,HIGH);
 delayMicroseconds(30);
 digitalWrite(PUL,LOW);
 delayMicroseconds(30);
 }
 digitalWrite(DIR,LOW);
 delayMicroseconds(60);
 for (int i=0; i<6400; i++) //Forward 5000 steps
 {
 digitalWrite(PUL,HIGH);
 delayMicroseconds(30);
 digitalWrite(PUL,LOW);
 delayMicroseconds(30);
 }
}
