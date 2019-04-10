/*


Link a TinkerCAD:
https://www.tinkercad.com/things/585BQwOFRRN 
** Al parecer la simulacion no toma bien los inputs de los pulsadores


*/
// Variable para llevar la cuenta del paso en el proceso de luces que se encuentra el semaforo
int cuenta = 0;

// Variables para definir si alguno de los botones fue utilizado
boolean S1 = false;
boolean S2 = false;

void setup() {
  // Declaración de modo de pin, OUTPUT para los pines de las luces de cada semaforo, Pines 2 y 3 son los input del usuario
  for (int i = 4; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2), pushS1, RISING);
  attachInterrupt(digitalPinToInterrupt(3), pushS2, RISING);
}

void loop() {
  // Se presiona el boton del semaforo N-S, pone su luz en rojo y en verde la del semaforo E-O
  if (S1 == true) {
    for (int i = 4; i < 10; i++) {
      digitalWrite(i, 0);
    }
    cuenta = 0;
    S1 = false;
  }
  
  // Se presiona el boton del semaforo E-O, pone su luz en rojo y en verde la del semaforo N-S
  if (S2 == true) {
    for (int i = 4; i < 10; i++) {
      digitalWrite(i, 0);
    }
    cuenta = 2;
    S2 = false;
  }
  // Iniciar la tarea de encender las luces del semaforo con los tiempos indicados para cada luz
  luces();
}

void pushS1() {
  // Evalua si la luz se encuentra en un color diferente a rojo para hacer el cambio solicitado por el usuario 
  if (digitalRead(5) == 1 || digitalRead(6) == 1) {
    S1 = true;
  }
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}

void pushS2() {
  // Evalua si la luz se encuentra en un color diferente a rojo para hacer el cambio solicitado por el usuario
  if (digitalRead(8) == 1 || digitalRead(9) == 1) {
    S2 = true;
  }
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
}

void luces() {
  if (cuenta == 0) {
    // Encender luz roja del semaforo N-S y luz verde del semaforo E-O durante 3 segundos
    digitalWrite(4, 1);
    digitalWrite(9, 1);
    delay(3000);
    digitalWrite(9, 0);
    cuenta++;
  } else if (cuenta == 1) {
    // Encender luces amarillas de los dos semaforos durante 1 segundo, en el semaforo N-S se combina con la luz roja
    digitalWrite(5, 1);
    digitalWrite(8, 1);
    delay(1000);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(8, 0);
    cuenta++;
  } else if (cuenta == 2) {
    // Encender luz verde del semaforo N-S y luz roja del semaforo E-O durante 3 segundos
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    delay(3000);
    digitalWrite(6, 0);
    cuenta++;
  } else if (cuenta == 3) {
    // Encender luz amarilla de los dos semaforos durante 1 segundo, en el semaforo E-O se combina con la luz roja
    digitalWrite(5, 1);
    digitalWrite(8, 1);
    delay(1000);
    digitalWrite(7, 0);
    digitalWrite(5, 0);
    digitalWrite(8, 0);
    cuenta = 0;
  }
}
