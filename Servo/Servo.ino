#include<Servo.h>
Servo Severus;

void setup() {
  pinMode(9,OUTPUT);
  pinMode(6, INPUT);
  Severus.attach(9);
  Severus.write(0);
}

void loop() {
  if(digitalRead(6) == 1){
    Severus.write(90);
    delay(500);
  } else {
    Severus.write(0);
    delay(500);
  }
}
