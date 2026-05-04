/*==========================================================================
// Auteur : Khaos "Kelshen" Viracocha
// Project : jipanco - Hermes
// Description : Stepper Motor Driver code
//==========================================================================
*/
int PIN_DIR=5; // Direction pin
int PIN_PUL=6; // Pulse pin
int PIN_ENA=19; // Enable Pin
int PULSE=400; // Pulse/Rev calibré sur le Driver
int TIME=1000; // temps par tour (en millisecondes)
int DLY=TIME*1000/PULSE; // Délai entre chaque pulse ( en microsecondes)

void setup() {
 pinMode (PIN_ENA, OUTPUT);
 pinMode (PIN_DIR, OUTPUT);
 pinMode (PIN_PUL, OUTPUT);
 digitalWrite(PIN_ENA,LOW); // initialisation
 delayMicroseconds(100);
}
void loop() {
 digitalWrite(PIN_DIR,LOW);     // dans un sens
 delayMicroseconds(1000000);
 for (int i=0; i<PULSE+1; i++)
 {
 digitalWrite(PIN_PUL,HIGH);
 delayMicroseconds(DLY);
 digitalWrite(PIN_PUL,LOW);
 delayMicroseconds(DLY);
 }
 digitalWrite(PIN_DIR,HIGH);    // dans l'autre sens
 delayMicroseconds(1000000);
 for (int i=0; i<PULSE+1; i++)
 {
 digitalWrite(PIN_PUL,HIGH);
 delayMicroseconds(DLY);
 digitalWrite(PIN_PUL,LOW);
 delayMicroseconds(DLY);
 }

}

/*     sequence acceleration

 digitalWrite(PIN_DIR,LOW);     
 delayMicroseconds(1000000);
 for (int i=0; i<PULSE+1; i++)
 {
 digitalWrite(PIN_PUL,HIGH);
 delayMicroseconds(DLY);
 digitalWrite(PIN_PUL,LOW);
 delayMicroseconds(DLY);
 TIME -= 50
 }

*/
