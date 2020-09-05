
//porta do botao que estara desligado
const int button = 7;

//muda o estado do botao para desligado ou ligado
int state= 0;

void setup() {
  //definimos que a variavel 'button' e uma porta de entrada
  //neste caso entra tensao pela porta
  pinMode(button, INPUT);

  //LED_BUILTIN porta do led
  //com o LED_BUILTIN declaramos que e uma saida
  pinMode(LED_BUILTIN, OUTPUT);

  //definimos que a porta de led da placa
  //vai inciar desligada
  digitalWrite(LED_BUILTIN, LOW);

}

void loop() {
  //digitalRead e o estado da porta
  //retornado 0 para desligada e 1 para ligada
  state = digitalRead(button);


  //ligando ou desligando
  digitalWrite(LED_BUILTIN, state);
}
