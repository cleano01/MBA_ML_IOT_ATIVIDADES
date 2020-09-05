
//val responsavel por incrementar o valor de 1 em 1
int val=1;

void setup() {
  //funcao para inciar comunicação do computaor com uma outra frequencia
  Serial.begin(9600);


  //enviado informacao para porta serial
  Serial.print("ola");

  Serial.println("mundo :D");

}

void loop() {

  Serial.print("linha: ");
  Serial.println(val);
  val+=1;

  delay(2000);

}
