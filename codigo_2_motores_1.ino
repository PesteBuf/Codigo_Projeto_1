const int dirPin_frontal_motor = 4;  //motor com base por cima
const int stepPin_frontal_motor = 5;
const int steps_froltal_motor = 200;  // Passos por revolução do motor frontal
const int dirPin_back_motor = 2;      //motor com parafuso por cima
const int stepPin_back_motor = 3;
const int steps_back_motor = 200;  // Passos por revolução do motor traseiro

void setup() {
  // Configurando os pinos como saída
  pinMode(stepPin_frontal_motor, OUTPUT);
  pinMode(dirPin_frontal_motor, OUTPUT);
  pinMode(stepPin_back_motor, OUTPUT);
  pinMode(dirPin_back_motor, OUTPUT);

  // Configurando a direção inicial dos motores
  digitalWrite(dirPin_frontal_motor, HIGH);  // Sentido horário
  digitalWrite(dirPin_back_motor, HIGH);     // Sentido horário
}

void loop() {



  //volta motor com a base
  for (int x = 0; x < steps_froltal_motor; x++) {
    digitalWrite(stepPin_frontal_motor, HIGH);
    delayMicroseconds(10000);//(ajustar depois com a base do objeto)
    digitalWrite(stepPin_frontal_motor, LOW);
    delayMicroseconds(10000);
  }
  delay(1000);
  //motor de tras (volta rapdida)
  for (int y = 0; y < steps_back_motor; y++) {
    digitalWrite(stepPin_back_motor, HIGH);
    delayMicroseconds(3000);  // Atraso menor para alta velocidade (200 µs)
    digitalWrite(stepPin_back_motor, LOW);
    delayMicroseconds(3000);
  }
  delay(1000);  // Pausa de 1 segundo após o motor frontal completar a volta
}
