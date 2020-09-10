float x =0 ;
float y = 0;
int n = 0, k = 0;

void setup() {
  Serial.begin(9600); //Enviar uma mensagem na porta serial
}

void loop() {
  String sti = "";

  Serial.println("Digite um valor");

  while(Serial.available() == 0){
    /*aqui nesse fica travado, mas sem imprimir nada,
     * enquanto nao tiver nada na porta serial vai ficar 
     * tavado aqui
    */
  }

  if(Serial.available() > 0){//aqui verifica se tem algo na entrada da porta serial
      String sti = ""; 

      while(Serial.available() > 0){
        /*
         * nesse while enquanto tiver dados
         * na porta serial, vai manter o while
         */

         char chat = Serial.read();//variavel para le o que esta na fila da porta serial
         sti+= chat;

         delay(100);
      }  

      x = sti.toInt();
      y = sti.toFloat();

      Serial.print("O valor digitado e: ");
      Serial.println(sti); 
      Serial.println(" ");    
  }
}
