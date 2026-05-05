/*==========================================================================
// Auteur : Khaos "Kelshen" Viracocha
// Project : jipanco - Hermes
// Description : Stepper Motor Driver code
//==========================================================================
*/
int PIN_DIR = 5; // Direction pin
int PIN_PUL = 6; // Pulse pin
int PIN_ENA = 19; // Enable Pin
int pulse = 400; // nb de pas par tour (voir reglage sur le driver)

void setup() {
 pinMode (PIN_ENA, OUTPUT);
 pinMode (PIN_DIR, OUTPUT);
 pinMode (PIN_PUL, OUTPUT);
 digitalWrite(PIN_ENA,LOW); // initialisation
 delayMicroseconds(100);
}


void loop() {
 digitalWrite(PIN_PUL,HIGH);
 delayMicroseconds(125);
 digitalWrite(PIN_PUL,LOW);
 delayMicroseconds(125);   
}

 
