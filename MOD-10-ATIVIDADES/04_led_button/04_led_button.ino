
  /* 7 e entrada para recebeer o valor do botao 1(ligado) ou 0(desligado) */
  const int button = 7;

  //a entrada com entrada 5, vai ficar ligado enquanto o botao fica precionado
  const int led1 = 5;
  
  //a entrada com entrada 6, vai ficar desligado enquanto o botao fica precionado
  const int led2 = 6;

  // guarda o estado do botao
  int state = 0;

void setup() {

   //definimos button, como porta de entarda, ela recebera a tensao
  pinMode(button, INPUT);


  //led1 e led2 sao as saidas, definimos abaixo
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);


  //definos que os leds vao inicar desligados
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

}

void loop() {
  //com o digitalRead capturamos tensao 1 ou 0  quando presionar o botao
  state = digitalRead(button);


  //captura o valor do botao para ligar(1) ou desligar(0)  led
  digitalWrite(led1, state);
  digitalWrite(led2, !state);

  
}
