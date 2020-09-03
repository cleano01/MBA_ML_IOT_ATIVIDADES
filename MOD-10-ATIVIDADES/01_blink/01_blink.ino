void setup() {
  //LED_BUILTIN =  porta(13) padrao para o led
  pinMode(LED_BUILTIN, OUTPUT);//saida

  digitalWrite(LED_BUILTIN, LOW);//informando(comeca) que a porta esta desligada
  
}

void loop() {

  digitalWrite(LED_BUILTIN, HIGH);//ligando o led
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);//desligando o led
  delay(5000);

}
