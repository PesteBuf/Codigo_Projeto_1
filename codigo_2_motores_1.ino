// pins debounce
int buttonPin = 6 ;
int buttonState;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;



const int dirPin_frontal_motor = 4;  //motor com base por cima
const int stepPin_frontal_motor = 5;
const int steps_froltal_motor = 200;  // Passos por revolução do motor frontal
const int dirPin_back_motor = 2;      //motor com parafuso por cima
const int stepPin_back_motor = 3;
const int steps_back_motor = 200;  // Passos por revolução do motor traseiro

long last_millis = 0;


bool buttonPressed() {
  int reading = digitalRead(buttonPin);
  bool pressed = false;

  if (reading != lastButtonState) {
     lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;


      if (buttonState == HIGH) {
        pressed = true;
      }
    }
  }

  lastButtonState = reading;
  return pressed;
}


enum Estados_scanner{
  ON,
  OFF
} estado;


void setup() {
  // Configurando os pinos como saída
  pinMode(stepPin_frontal_motor, OUTPUT);
  pinMode(dirPin_frontal_motor, OUTPUT);
  pinMode(stepPin_back_motor, OUTPUT);
  pinMode(dirPin_back_motor, OUTPUT);
  pinMode( buttonPin , INPUT);

  // Configurando a direção inicial dos motores
  digitalWrite(dirPin_frontal_motor, HIGH);  // Sentido horário
  digitalWrite(dirPin_back_motor, HIGH);     // Sentido horário
   
  lastButtonState = digitalRead(buttonPin);

  estado = OFF;
}



void loop() {

  Serial.println(buttonState);

switch(estado ){

  case OFF: 

    if ( buttonPressed() ){

      estado = ON;
    }

    break;

  case ON: 



  //volta motor com a base


  
  for (int x = 0; x < steps_froltal_motor; x++) {
    digitalWrite(stepPin_frontal_motor, HIGH);
    delayMicroseconds(10000);  //(ajustar depois com a base do objeto)
    digitalWrite(stepPin_frontal_motor, LOW);
    delayMicroseconds(10000);

    if (  buttonPressed()){

      estado = OFF;
    }

  }


  


  

for (int y = 0; y < steps_back_motor; y++) {
    digitalWrite(stepPin_back_motor, HIGH);
    delayMicroseconds(3000);  // Atraso menor para alta velocidade (200 µs)
    digitalWrite(stepPin_back_motor, LOW);
    delayMicroseconds(3000);
    if (  buttonPressed()){
      estado = OFF;
    }
  }
 

  
  //motor de tras (volta rapdida)
  
    // Pausa de 1 segundo após o motor frontal completar a volta

  
  break;
  
}

}
