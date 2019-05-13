#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include<Servo.h>
Servo Severus;

int hora = 0;
int frM = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hora:");
  pinMode(9, OUTPUT);
  Severus.attach(9);
  Severus.write(0);
  Serial.begin(9600);
}

void loop() {
  int sixAm = analogRead(A3);
  sixAm = map(sixAm, 0, 1023, 0, 255);
  //Serial.println(sixAm);

  int neinAm = analogRead(A2);
  neinAm = map(neinAm, 0, 1023, 0, 255);
  //Serial.println(neinAm);

  int tresPm = analogRead(A1);
  tresPm = map(tresPm, 0, 1023, 0, 255);
  //Serial.println(tresPm);

  int sixPm = analogRead(A0);
  sixPm = map(sixPm, 0, 1023, 0, 255);
  //Serial.println(sixPm);

  int fotoResistencias[] = {sixAm, neinAm, tresPm, sixPm};
  for (int i = 0; i < sizeof(fotoResistencias); i++) {
    frM = fotoResistencias[i];
    for (int j = 1; j < sizeof(fotoResistencias); j++) {
      if (frM < fotoResistencias[j]) {
        frM = fotoResistencias[j];
      }
    }
  }
//  Serial.println("Fotoresistencia mayor: ");
//  Serial.print(frM);
//  Serial.println(" ");
//  Serial.println(" ");
//  Serial.println(" ");

  if (frM == sixAm) {
    hora = 6;
    lcd.setCursor(7, 0);
    lcd.print(hora);
    lcd.print(" am");
    Severus.write(0);
  } else if (frM == neinAm) {
    hora = 9;
    lcd.setCursor(7, 0);
    lcd.print(hora);
    lcd.print(" am");
    Severus.write(45);
  } else if (frM == tresPm) {
    hora = 15;
    lcd.setCursor(7, 0);
    lcd.print(hora);
    lcd.print(" pm");
    Severus.write(135);
  } else if (frM == sixPm) {
    hora = 18;
    lcd.setCursor(7, 0);
    lcd.print(hora);
    lcd.print(" pm");
    Severus.write(155);
  }
  delay(500);
}
