void setup() {
 /* Declara que todas as portas no qual os leds 
  estão ligados, é saída */
  for (int led = 2; led <= 9; led++) {
      pinMode(led, OUTPUT);
  }

  /* Declara que todas as portas no qual declaradas
  como saídas, iniciem desligadas */
  for (int led = 2; led <= 9; led++) {
      digitalWrite(led, LOW);
  }
}


void loop() {
  
  vermelho();
  delay(3000);
  verde();
  delay(3000);
  amarelo();
  delay(3000);

}

void verde(){  
   for (int led = 2; led <= 9; led++) {
      if(led >= 2 &  led <= 4){
         digitalWrite(led, HIGH);
      }else{
        digitalWrite(led,LOW);
      }      
  }
}

void vermelho(){
    for (int led = 2; led <= 9; led++) {
      if(led >= 7 &  led <= 9){
         digitalWrite(led, HIGH);
      }else{
        digitalWrite(led,LOW);
      }      
  }
}

void amarelo(){
    for (int led = 2; led <= 9; led++) {
      if(led >= 4 &  led <= 5){
         digitalWrite(led, HIGH);
      }else{
        digitalWrite(led,LOW);
      }      
  }
  
}
