/*



Link a simulacion en TinkerCAD:
https://www.tinkercad.com/things/7AU6haVBylf 
** Al parecer la simulacion no toma bien los delays y no los realiza correctamente



*/

// Variables que manejas el estado de los sensores, 1=bajo, 2=medio y 3=alto
int sensorT = 0;
int sensorH = 0;

// Variables para definir los pines de alarma y aspersor
int alarm = 8;
int aspersor = 9;

// Arreglos de pines de leds de temperatura, leds de humedad e inputs
int tempLeds[] = {2, 3, 4};
int humLeds[] = {5, 6, 7};
int inputs[] = {10, 11, 12, 13};

void setup() {
  // Inicializacion de los pines, del 2-9 son OUTPUT para mostrar 
  // los estados de cada sensor y si la alarma o el aspersor estan encendidos
  pinMode(alarm, OUTPUT);
  pinMode(aspersor, OUTPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(tempLeds[i], OUTPUT);
    pinMode(humLeds[i], OUTPUT);
  }
  // Inicializacion de lo pines de entrada para seleccionar 
  // el estado de cada sensor
  for (int i = 0; i < 5; i++) {
    pinMode(inputs[i], INPUT);
  }
}

void loop() {
  // Se verifica el estado de los niveles de Humedad y temperatura
  verifyStatus();
  // humedad baja y temperatura alta
  if (sensorH == 1 && sensorT == 3) {
    verifyStatus();
    // se enciende la alarma
    digitalWrite(alarm, 1);
    // se enciende el aspersor
    digitalWrite(aspersor, 1);
    // Aspersor dura 6 segundos encendido
    delay(6000);
    verifyStatus();
    digitalWrite(aspersor, 0);
    // si la humedad sube a medio se apaga la alarma
    if (sensorH == 2) {
      verifyStatus();
      digitalWrite(alarm, 0);
    }
  } 
  // humedad media y temperatura alta
  else if (sensorH == 2 && sensorT == 3) {
    verifyStatus();
    digitalWrite(aspersor, 1);
    delay(3000);
    //apagar aspersor despues de 3 segundos
    verifyStatus();
    digitalWrite(aspersor, 0);
  } 
  // humedad alta y temperatura baja
  else if (sensorH == 3 && sensorT == 1) {
    verifyStatus();
    digitalWrite(alarm, 1);
    // si temperatura sube a media se apaga la alarma
    if (sensorT == 2) {
      verifyStatus();
      digitalWrite(alarm, 0);
    }
  } 
  // humedad baja y temperatura baja
  else if (sensorH == 1 && sensorT == 1) {
    verifyStatus();
    digitalWrite(alarm, 1);
    // si temperatura sube a media se apaga la alarma
    if (sensorT == 2) {
      verifyStatus();
      digitalWrite(alarm, 0);
    }
  } 
  // humedad baja y temperatura media
  else if (sensorH == 1 && sensorT == 2) {
    verifyStatus();
    digitalWrite(aspersor, 1);
    delay(3000);
    // se apaga el aspersor despues de 3 segundos
    verifyStatus();
    digitalWrite(aspersor, 0);
  } 
  // si no se cumple ninguna de las anteriores condiciones, se apagan
  // la alarma y el aspersor
  else {
    verifyStatus();
    digitalWrite(alarm, 0);
    digitalWrite(aspersor, 0);
  }
}

// metodo para verificar el estado de los sensores
void verifyStatus() {
  // se lee el estado del input
  int S0 = digitalRead(inputs[0]);
  int S1 = digitalRead(inputs[1]);
  int S2 = digitalRead(inputs[2]);
  int S3 = digitalRead(inputs[3]);

// si S0=0 se estan modificando los estados de humedad
// si S0=1 se estan modificando los estados de humedad
// cuando S1=1 el estado se coloca del sensor en bajo y se enciende su led
// cuando S2=1 el estado se coloca del sensor en medio y se enciende su led
// cuando S3=1 el estado se coloca del sensor en alto y se enciende su led
  if (S0 == 0 && S1 == 0 && S2 == 0 && S3 == 0) {
    digitalWrite(humLeds[0], 0);
    digitalWrite(humLeds[1], 0);
    digitalWrite(humLeds[2], 0);
    sensorH = 0;
  }
  if (S0 == 0 && S1 == 1 && S2 == 0 && S3 == 0) {
    digitalWrite(humLeds[0], 1);
    digitalWrite(humLeds[1], 0);
    digitalWrite(humLeds[2], 0);
    sensorH = 1;
  }
  if (S0 == 0 && S1 == 0 && S2 == 1 && S3 == 0) {
    digitalWrite(humLeds[0], 0);
    digitalWrite(humLeds[1], 1);
    digitalWrite(humLeds[2], 0);
    sensorH = 2;
  }
  if (S0 == 0 && S1 == 0 && S2 == 0 && S3 == 1) {
    digitalWrite(humLeds[0], 0);
    digitalWrite(humLeds[1], 0);
    digitalWrite(humLeds[2], 1);
    sensorH = 3;
  }
  if (S0 == 1 && S1 == 0 && S2 == 0 && S3 == 0) {
    digitalWrite(tempLeds[0], 0);
    digitalWrite(tempLeds[1], 0);
    digitalWrite(tempLeds[2], 0);
    sensorT = 0;
  }
  if (S0 == 1 && S1 == 1 && S2 == 0 && S3 == 0) {
    digitalWrite(tempLeds[0], 1);
    digitalWrite(tempLeds[1], 0);
    digitalWrite(tempLeds[2], 0);
    sensorT = 1;
  }
  if (S0 == 1 && S1 == 0 && S2 == 1 && S3 == 0) {
    digitalWrite(tempLeds[0], 0);
    digitalWrite(tempLeds[1], 1);
    digitalWrite(tempLeds[2], 0);
    sensorT = 2;
  }
  if (S0 == 1 && S1 == 0 && S2 == 0 && S3 == 1) {
    digitalWrite(tempLeds[0], 0);
    digitalWrite(tempLeds[1], 0);
    digitalWrite(tempLeds[2], 1);
    sensorT = 3;
  }
}
