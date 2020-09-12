const int buzzer = 8; //porta do buzzer digital 
const int botao = 6; //porta do boato digital
void setup() {
   Serial.println("Iniciando ....");

  pinMode(botao, INPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer, LOW);//inicia desliado 

}

void loop() {
 if(digitalRead(botao) == 1){
  Serial.println("Som sendo ativiado ....");
  tone(buzzer, 150);//150 e a frequencia enviada em Hz
  
 }
 else{
  noTone(buzzer);
 }

}
