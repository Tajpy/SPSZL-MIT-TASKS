const int led = 13;
const int tlacitko = 2;

volatile bool vypzap = false;
unsigned long previousMillis = 0;
const unsigned long interval = 300;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(tlacitko, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(tlacitko), toggle, FALLING);
}

void loop() {
  if (vypzap) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digitalWrite(led, !digitalRead(led));
    }
  } else {
    digitalWrite(led, LOW);
  }
}

void toggle() {
  vypzap = !vypzap;
}
