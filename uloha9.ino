// Z VELKÉ ČÁSTI UDĚLÁNO CHATEM GPT
const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;
const int LED4 = 10;
const int LED5 = 9;
const int LED6 = 8;

const int tlacitko1 = 3;  // musí být pin s interrupt
const int tlacitko2 = 2;  // musí být pin s interrupt

volatile int pocetLED = 0;  // musí být volatile, mění se v ISR

void pridatLED() {
  if (pocetLED < 6) pocetLED++;
}

void ubratLED() {
  if (pocetLED > 0) pocetLED--;
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  pinMode(tlacitko1, INPUT_PULLUP); // doporučené
  pinMode(tlacitko2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(tlacitko1), pridatLED, FALLING);
  attachInterrupt(digitalPinToInterrupt(tlacitko2), ubratLED, FALLING);
}

void loop() {
  // Zapnout přesně tolik LED, kolik je v pocetLED
  digitalWrite(LED1, pocetLED >= 1 ? HIGH : LOW);
  digitalWrite(LED2, pocetLED >= 2 ? HIGH : LOW);
  digitalWrite(LED3, pocetLED >= 3 ? HIGH : LOW);
  digitalWrite(LED4, pocetLED >= 4 ? HIGH : LOW);
  digitalWrite(LED5, pocetLED >= 5 ? HIGH : LOW);
  digitalWrite(LED6, pocetLED >= 6 ? HIGH : LOW);
}