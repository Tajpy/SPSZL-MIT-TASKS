

void setup() {

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  
  for (int i = 6; i <= 13; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  for(int i = 13; i >= 6; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW); // smooth verzi jsem zapomnel :/
  }




}
