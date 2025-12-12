#include <Wire.h>

// Nastavíme výchozí hodnotu na 'x' (zhasnuto), aby displej po startu neblikal náhodně
volatile char vypis = 'x'; 

const int segmentA = 13;
const int segmentB = 12;
const int segmentC = 11;
const int segmentD = 10;
const int segmentE = 9;
const int segmentF = 8;
const int segmentG = 7;

void setup() {
  Wire.begin(8);                // Připojení na I2C s adresou 8
  Wire.onReceive(receiveEvent); // <--- TOTO CHYBĚLO! Spustí funkci při příjmu dat
  
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  
  Serial.begin(9600);
  ZhasnutiDisplaye();
}

void loop() {
  // Displej neustále obnovujeme podle poslední přijaté hodnoty
  RosvititZnak(vypis);
  // Malé zpoždění není nutné, ale může být (stačí menší, aby displej reagoval rychle)
  delay(10); 
}

// Funkce, která se spustí automaticky, když přijdou data z druhého Arduina
void receiveEvent(int howMany) {
  if (Wire.available()) {
    int prijateCislo = Wire.read(); // Přečteme čisté číslo (např. 5)
    
    // Převedeme číslo na znak pro SWITCH (5 -> '5')
    // Protože tvůj vysílač posílá int, ale tvůj switch čeká char.
    vypis = prijateCislo + '0'; 
  }
}

void ZhasnutiDisplaye() {
  // Podle tvého kódu máš displej se SPOLEČNOU ANODOU (HIGH = zhasnuto)
  for (int i = 13; i > 6; i--) {
    digitalWrite(i, HIGH);
  }
}

void RosvititZnak(char znak) {
  // Poznámka: Tvůj kód používá logiku pro SPOLEČNOU ANODU
  // LOW = svítí, HIGH = nesvítí
  
  switch (znak) {
    case '0':  // A B C D E F svítí, G zhasnutý
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;

    case '1':  // B C
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;

    case '2':  // A B D E G
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);
      break;

    case '3':  // A B C D G
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);
      break;

    case '4':  // B C F G
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;

    case '5':  // A C D F G
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;

    case '6':  // A C D E F G
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;

    case '7':  // A B C
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;

    case '8':  // A B C D E F G
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;

    case '9':  // A B C D F G
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;

      case 'x':  // Vše zhasnuto (default)
      ZhasnutiDisplaye();
      break;
  }
}
