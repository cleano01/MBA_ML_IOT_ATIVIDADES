

const int led1 = 7;
const int led2 = 8;
const int led3 = 9;

const int pot = 0;  //porta do potenciometro


void setup() {
  Serial.begin(9600);//porta serial
  Serial.println("inicializando ...");
  delay(1000);


  pinMode(led1, OUTPUT);//saida
  digitalWrite(led1, LOW);//led inicializa desligado

  
  pinMode(led2, OUTPUT);//saida
  digitalWrite(led2, LOW);//led inicializa desligado
  
  pinMode(led3, OUTPUT);//saida
  digitalWrite(led3, LOW);//led inicializa desligado

  
}

void loop() {
  
	Serial.println(analogRead(pot));
 	delay(300);
  
  if(analogRead(pot) > 700){ 
     digitalWrite(led1, HIGH);// led liga
     digitalWrite(led2, LOW);//led  desligado
     digitalWrite(led3, LOW);//led  desligado
  }
  
 
  else if(analogRead(pot) <= 700  && analogRead(pot) >= 300){ 
      digitalWrite(led2, HIGH);// led liga
      digitalWrite(led3, LOW);//led  desligado
      digitalWrite(led1, LOW);//led  desligado
  }

  else{
     digitalWrite(led3, HIGH);// led liga
     digitalWrite(led1, HIGH);// led liga
     digitalWrite(led2, LOW); // desliga led
  }
  
  
}
