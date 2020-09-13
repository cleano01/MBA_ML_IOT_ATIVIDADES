#include "Servo.h" // Inclui a Biblioteca Servo.h
Servo meuservo; // Cria o objeto servo para programação

int angulo=0;

void setup() {
   Serial.begin(9600);
   meuservo.attach(5); // Declara o pino do servo
  
   Serial.println("iniciando ...");
   delay(100);
}

void loop() {
	Serial.println("Informe um numero: ");

	 angulo= serial_numero();
	
	if(angulo < 0){
	  Serial.println("Informe um número maior que 0");
	  angulo = 0;
	}
	
	if(angulo > 180){
	  Serial.println("Informe um número menor que 180 ");
	  angulo = 180;
	}
	
	meuservo.write(angulo); // Comando para angulo específico no servo motor
	delay(200);
}


int serial_numero(){
	 String sti = "";
	 int aux_num = 0;

    while(Serial.available() == 0){
     	/*aqui nesse fica travado, mas sem imprimir nada,
	     * enquanto nao tiver nada na porta serial vai ficar 
	     * tavado aqui
	    */
	}

	  if(Serial.available() > 0){//aqui verifica se tem algo na entrada da porta serial
    		  String sti = ""; 
	
	     while(Serial.available() > 0){
	        /* nesse while enquanto tiver dados
	         * na porta serial, vai manter o while
	         */

    		     char chat = Serial.read();//variavel para le o que esta na fila da porta serial
         	sti+= chat;

	         delay(100);
           }  

      aux_num = sti.toInt();

      Serial.print("O valor digitado e: ");
      Serial.println(sti); 
      Serial.println(" ");  
	  return aux_num;
	}
}