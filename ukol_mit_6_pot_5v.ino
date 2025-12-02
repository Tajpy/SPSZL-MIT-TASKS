int hodnotapot;

void setup() {

  Serial.begin(9600);
  pinMode(A0, INPUT);

}

void loop() {

    hodnotapot = analogRead(A0);
    hodnotapot = map(hodnotapot, 0, 1023, 0, 255);
    Serial.println(hodnotapot);
    delay(100);
}
