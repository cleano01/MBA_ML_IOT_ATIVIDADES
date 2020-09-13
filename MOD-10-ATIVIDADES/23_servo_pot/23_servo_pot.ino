#include "Servo.h" // Inclui a Biblioteca Servo.h
Servo meuservo; // Cria o objeto servo para programação

int angulo = 0;
const int pot = 0; //potenciometro


void setup() {
   Serial.begin(9600);
   meuservo.attach(5); // Declara o pino do servo
  
   Serial.println("iniciando ...");
   delay(100);
}


void loop() {

   angulo= map(analogRead(pot), 0, 1024, 10, 100);
   meuservo.write(angulo); // Comando para angulo específico no servo motor
   
   delay(50);
}
