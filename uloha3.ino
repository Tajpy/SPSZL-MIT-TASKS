int zap = 12;
int vyp = 11;
int led = 4;
int zdroj = 2;

void setup() {

  pinMode(zap, INPUT);
  pinMode(vyp, INPUT);
  pinMode(led, OUTPUT);
  pinMode(zdroj, OUTPUT);

  digitalWrite(zdroj, HIGH); // zdroj pro tlacitka vyo a zap
}

void loop() {

  if (digitalRead(12) == HIGH) {
    digitalWrite(led, HIGH);
  }
  if (digitalRead(11) == HIGH) {
    digitalWrite(led, LOW);
  }
  delay(50);



}
