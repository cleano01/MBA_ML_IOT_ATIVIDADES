
const int botao = 10;

const int led1 = 7;
const int led2 = 8;
const int led3 = 9;

const int pot = 0;  //porta do potenciometro


void setup() {
  Serial.begin(9600);//porta serial
  Serial.println("inicializando ...");
  delay(1000);

  pinMode(botao, INPUT);//entarda

  pinMode(led1, OUTPUT);//saida
  digitalWrite(led1, LOW);//led inicializa desligado

  
  pinMode(led2, OUTPUT);//saida
  digitalWrite(led2, LOW);//led inicializa desligado
  
  pinMode(led3, OUTPUT);//saida
  digitalWrite(led3, LOW);//led inicializa desligado

  
}


void loop() {
  
  if(digitalRead(botao) == 1){
     digitalWrite(led1, HIGH);// led liga
  }else{
      digitalWrite(led1, LOW);//led  desliga
  }

  Serial.println(analogRead(pot));
  delay(200);
  
  if(analogRead(pot) > 700){
     digitalWrite(led2, HIGH);// led liga

  }else{
     digitalWrite(led2, LOW);//led  desliga
  }

  

  if(analogRead(pot) >=700 && digitalRead(botao) == 1){
     digitalWrite(led3, HIGH);// led liga

  }else{
     digitalWrite(led3, LOW);//led  desliga
  }

  
  
}
