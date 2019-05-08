#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int contador = 0;

void setup() {
  lcd.begin(16,2);
  lcd.print("Conteo:");
}

void loop() {
  lcd.setCursor(7,0);
  lcd.print(contador);
  contador++;
  delay(10);
}
