int lightLeds[] = {8, 9, 10};
int humLeds[] = {11, 12, 13};
int calef = 6;
int aircond = 7;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(lightLeds[i], OUTPUT);
    pinMode(humLeds[i], OUTPUT);
  }
  pinMode(calef, OUTPUT);
  pinMode(aircond, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //L < 85, M = 85<=m<170, H >=170
  int Luz = analogRead(A0);
  Luz = map(Luz, 0, 1023, 0, 255);
  int Hum = analogRead(A1);
  Hum = map(Hum, 0, 1023, 0, 255);
  delay(100);
  Serial.println(Luz);
  Serial.println(Hum);

  if (Hum < 42) {
    digitalWrite(humLeds[0], 0);
    digitalWrite(humLeds[1], 0);
    digitalWrite(humLeds[2], 1);
  } else if (Hum >= 42 && Hum < 85) {
    digitalWrite(humLeds[0], 0);
    digitalWrite(humLeds[1], 1);
    digitalWrite(humLeds[2], 0);
  } else if (Hum >= 85) {
    digitalWrite(humLeds[0], 1);
    digitalWrite(humLeds[1], 0);
    digitalWrite(humLeds[2], 0);
  }

  if (Luz < 85) {
    digitalWrite(lightLeds[0], 0);
    digitalWrite(lightLeds[1], 0);
    digitalWrite(lightLeds[2], 1);
  } else if (Luz >= 85 && Luz < 170) {
    digitalWrite(lightLeds[0], 0);
    digitalWrite(lightLeds[1], 1);
    digitalWrite(lightLeds[2], 0);
  } else if (Luz >= 170) {
    digitalWrite(lightLeds[0], 1);
    digitalWrite(lightLeds[1], 0);
    digitalWrite(lightLeds[2], 0);
  }

  if (Hum >= 85 && Luz < 85) {
    digitalWrite(calef, 1);
    digitalWrite(aircond, 0);
  }
  else if (Hum < 42 && Luz >= 170) {
    digitalWrite(calef, 0);
    digitalWrite(aircond, 1);
  }
  else if (Hum >= 42 && Hum < 85 && Luz >= 85 && Luz < 170) {
    digitalWrite(calef, 0);
    digitalWrite(aircond, 0);
  } else {
    digitalWrite(calef, 0);
    digitalWrite(aircond, 1);
  }
}
