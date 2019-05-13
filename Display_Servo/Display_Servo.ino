#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include<Servo.h>
Servo Severus;

int contador = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(9, OUTPUT);
  Severus.attach(9);
  Severus.write(0);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Grados:");
  lcd.print(contador);
  Severus.write(contador);
  contador++;
  if (contador == 15) {
    contador = 0;
  }
  delay(500);
  Severus.write(contador);
  lcd.clear();
}
