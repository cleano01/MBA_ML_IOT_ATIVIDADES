const int buzzer = 8; //porta do buzzer digital 
const int variation[] = {150, 170, 190, 200};
void setup() {
  
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer, LOW);//inicia desliado 
  Serial.println("Iniciando ....");
  delay(100);
}

void loop() {

  for(int i=0; i <=3; i++ ){
      tone(buzzer, variation[i]);

  }
  

}
