
const int led = 9; //porta digital
const int pot = 0; //portal analogia(A0)

int val = 0; //valor do potenciometro
int val1 = 0; //interpolacao do potenciometro  10 bits apra 8 bits PWM(modulacao de largura de pulso).

void setup() {
  pinMode(led, OUTPUT);//saida
  pinMode(led, LOW);//desligado
}

void loop() {
  val = analogRead(pot); //leitura da porta do poteciometro

  val1 = map(val, 0, 1023, 0, 255);//interpolacao de valores e uma variavel

  /*
  os parametros da funcao sao os seguintes:

  lim_max = limite superior da variavel
  lim_min = limite inferior da variavel
  des_min = minimo valor desejado
  des_max = maximo valor desejado
  map(variavel, lim_min, lim_mas, des_min, des_max);
  */


  analogWrite(led, val1); /*Insere os valores do PWM + porta digital
  no led esta conectado */
  
}
