/*==========================================================================
// Auteur : Khaos "Kelshen" Viracocha
// Project : jipanco - Hermes
// Description : Stepper Motor Driver code
//==========================================================================
*/
int DIR=5; // Direction pin
int PUL=6; // Pulse pin
int ENA=19; // Enable Pin
int REV=1600; // Pulse/Rev calibré sur le Driver
int VIT=50; // Vitesse choisie
int DLY=REV/VIT; // (2,5 minimum !!)

void setup() {
 pinMode (ENA, OUTPUT);
 pinMode (DIR, OUTPUT);
 pinMode (PUL, OUTPUT);
 digitalWrite(ENA,LOW); // initialisation
 delayMicroseconds(100);
}
void loop() {
 digitalWrite(DIR,LOW);
 delayMicroseconds(60);
 for (int i=0; i<REV+1; i++)
 {
 digitalWrite(PUL,HIGH);
 delayMicroseconds(DLY);
 digitalWrite(PUL,LOW);
 delayMicroseconds(DLY);
 }
 delayMicroseconds(1000);
 digitalWrite(DIR,HIGH);
 delayMicroseconds(60);
 for (int i=0; i<REV+1; i++)
 {
 digitalWrite(PUL,HIGH);
 delayMicroseconds(DLY);
 digitalWrite(PUL,LOW);
 delayMicroseconds(DLY);
 }
 delayMicroseconds(1000);
}
