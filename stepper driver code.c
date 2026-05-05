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
 Serial.begin(9600);
 pinMode (PIN_ENA, OUTPUT);
 pinMode (PIN_DIR, OUTPUT);
 pinMode (PIN_PUL, OUTPUT);
 digitalWrite(PIN_ENA,LOW); // initialisation
 delayMicroseconds(100);
}


void loop() {
  
 digitalWrite(PIN_DIR,LOW);     // sens 1
 delayMicroseconds(1000);
 rotation(3,1,1);
 rotation(10,2,6);
 rotation(5,6,6);
 rotation(10,6,2);
 digitalWrite(PIN_DIR,HIGH);    // sens -1
 delayMicroseconds(1000);
 rotation(10,1,10);
 rotation(40,10,10);
 rotation(20,10,1);

}

// fonctions

 void rotation(int nb, int vinit, int vend)
 {
 
  float delay = 250 * (11 - vinit);
  float stepChange = 250.0 * (vinit - vend) / (nb * pulse);
  for (int t=0; t<nb; t++)
  {
   for (int i=0; i<pulse; i++) 
   {
   Serial.print("tour n° ");
   Serial.print(t + 1);
   Serial.print(" / ");
   Serial.print(nb);
   Serial.print(" | delay = ");
   Serial.println(delay);

   digitalWrite(PIN_PUL,HIGH);
   delayMicroseconds(delay);
   digitalWrite(PIN_PUL,LOW);
   delayMicroseconds(delay); 
   delay += stepChange; 
   }
  }
 }
 

