/*==========================================================================
  Auteur : Khaos "Kelshen" Viracocha
  Project : jipanco - Hermes
  Description : Stepper Motor Driver code
==========================================================================*/

const int PIN_DIR = 5;
const int PIN_PUL = 6;
const int PIN_ENA = 19;
const int PIN_FCB = 1;
const int PIN_FCH = 2;
const int PIN_SWT = 23;

const float DELAY_MAX    = 1250.0;
const float DELAY_MIN    = 250.0;
const float ACCEL_FACTOR = 0.999;
const float DECEL_FACTOR = 1.0 / 0.999;

bool goingDown = true;  // true = vers le bas

void setup() {
  Serial.begin(9600);
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_PUL, OUTPUT);
  pinMode(PIN_FCH, INPUT_PULLUP);
  pinMode(PIN_FCB, INPUT_PULLUP);
  pinMode(PIN_SWT, INPUT_PULLUP);

  digitalWrite(PIN_ENA, LOW);
  setDir(goingDown);
}

// FC câblée NC avec INPUT_PULLUP → LOW = activée
bool fcActive(int pin, int confirmations = 5, int delayUs = 200) {
  for (int i = 0; i < confirmations; i++) {
    if (digitalRead(pin) == LOW) return false;
    delayMicroseconds(delayUs);
  }
  return true;
}


void loop() {
  int fcPin = goingDown ? PIN_FCB : PIN_FCH;  // on surveille uniquement la FC devant nous
  float d = DELAY_MAX;

  // --- Accélération -------------------------------------------------------
  while (d > DELAY_MIN) {
    if (fcActive(fcPin)) goto deceleration;
    stepPulse(d);
    d *= ACCEL_FACTOR;
  }

  // --- Vitesse constante --------------------------------------------------
  while (!fcActive(fcPin)) {
    stepPulse(DELAY_MIN);
  }

deceleration:
  // --- Décélération -------------------------------------------------------
  d = DELAY_MIN;  // repart explicitement de la vitesse max
  while (d < DELAY_MAX) {
    stepPulse(d);
    d *= DECEL_FACTOR;
  }

  // --- Inversion ----------------------------------------------------------
  goingDown = !goingDown;
  setDir(goingDown);
  Serial.print("Inversion → "); Serial.println(goingDown ? "bas" : "haut");
  delay(300);
}

// ── Helpers ───────────────────────────────────────────────────────────────

void setDir(bool down) {
  digitalWrite(PIN_DIR, down ? HIGH : LOW);
}

void stepPulse(float d) {
  digitalWrite(PIN_PUL, HIGH);
  delayMicroseconds((unsigned int)d);
  digitalWrite(PIN_PUL, LOW);
  delayMicroseconds((unsigned int)d);
}

