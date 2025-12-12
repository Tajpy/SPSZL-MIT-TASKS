#include <Keypad.h>
#include <Wire.h> 

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Wire.begin(); // Nezapomeň: Nutné pro I2C komunikaci!
}

void loop(){
  char key = keypad.getKey(); 
  
  if (key){ 
    // FILTR: Pustíme dál jen znaky '0' až '9'
    if (key >= '0' && key <= '9') {
      
      // Převedeme znak na reálné číslo (int)
      int cislo = key - '0'; 
      
      Serial.print("Odesilam cislo: ");
      Serial.println(cislo);

      Wire.beginTransmission(8); 
      
      // Odesíláme čistou hodnotu (např. číslo 5).
      // Příjemce tedy dostane bajt s hodnotou 5 (ne znak '5').
      Wire.write(cislo); 
      
      Wire.endTransmission();
    }
    // Pokud bylo stisknuto A, B, *, # atd., program neudělá nic.
  }
}
