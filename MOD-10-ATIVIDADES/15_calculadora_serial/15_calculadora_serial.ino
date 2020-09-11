float num1 = 0;
float num2 = 0;

float operacao = 0;

void setup() {  
  Serial.begin(9600); 
  Serial.println("inicializando ...");
  delay(100);
}

void loop() {
 Serial.println(" ");

 Serial.println("Informe o primeiro numero");
 num1 = serial_input();
 Serial.println(num1);
 
 Serial.println(" ");

 Serial.println("Informe o segundo numero");
 num2 = serial_input();
 Serial.println(num2);
 Serial.println(" "); 
 
 delay(200);
 
 Serial.println("Escolha uma operacao"); 
 Serial.println("1- Soma"); 
 Serial.println("2- Subtracao"); 
 Serial.println("3- Multiplicacao"); 
 Serial.println("4- Divisao"); 
 
 delay(10);

 int opc = serial_int_input();
 boolean flag = false;
 

 while(flag ==  false){
  if(opc == 1){
      Serial.print("soma: "); 
      float res = num1+num2; 
      Serial.println(res); 
    }
    else if(opc==2){
      Serial.print("A resposta da subtracao e: "); 
      float res = num1-num2; 
      Serial.println(res); 
    }
    else if(opc==3){
      Serial.print("A resposta da multiplicacao e: "); 
      float res = num1*num2; 
      Serial.println(res); 
    }
    else if(opc==4){
      if(num2 != 0){ 
        Serial.print("divisao: "); 
        float res = num1/num2; 
       Serial.println(res); 
      }else{
        Serial.println("nao pode divisao por 0"); 
      }
    }
    else{//Caso selecione uma operacao invalida
      Serial.println("nao existe essa opcao."); 
    }
    if(opc <= 0 || opc >=1){
      flag = true;
    }  
	delay(300);   

 }
 delay(300);   
}

float serial_input(){
  
  while(Serial.available() == 0){
    /*aqui nesse fica travado, mas sem imprimir nada,
     * enquanto nao tiver nada na porta serial vai ficar 
     * tavado aqui
    */
  }
  
  String temp_value = "";
  float  return_value = 0;

  while(Serial.available() > 0){
    char chat=0;
    chat = Serial.read();//variavel para le o que esta na fila da porta serial
	temp_value += chat;

    delay(100);

    return_value = temp_value.toFloat();
    return return_value;
   }   
}


int serial_int_input(){
  
  while(Serial.available() == 0){  }
  
  String temp_value = "";
  float  return_value = 0;


  while(Serial.available() > 0){
  char chat=0;
   chat = Serial.read();
   temp_value += chat;

   delay(100);

   return_value = temp_value.toInt();
   return return_value;
   }   
  
}
