float num1 = 0;
float num2 = 0;

float operacao = 0;

//teclado
byte matriz[4][3] = { {1,2,3},
            {4,5,6},
            {7,8,9},
            {12,0,13},};
 
void setup() {
  Serial.begin(9600); 

   //saidas teclado(linhas)
   for(int porta = 2; porta <= 5; porta++){
    pinMode(porta, OUTPUT);
    digitalWrite(porta, LOW);
   }

   //entradas teclado (colunas)
   for(int porta = 6 ; porta <= 8; porta++){
    pinMode(porta, INPUT);
   } 
  
  Serial.println("inicializando ...");
  delay(100);
}


void loop() {
 Serial.println(" ");

 Serial.println("Informe o primeiro numero");
 num1 = teclado();
 Serial.println(num1);

 Serial.println("");

 Serial.println("Informe o segundo numero");
 num2 = teclado();
 Serial.println(num2);
 
 
 Serial.println(" "); 
 
 delay(100);

 Serial.println("Escolha uma operacao"); 
 Serial.println("1- Soma"); 
 Serial.println("2- Subtracao"); 
 Serial.println("3- Multiplicacao"); 
 Serial.println("4- Divisao"); 
  
 int opc = teclado();
 
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
   
  delay(300);   
  Serial.println(" ");
 

 delay(1000);

}


float teclado(){ 
  float valor_temp = 0; 
  String num_aux = ""; //String temporaria para ir armazenando os caracteres da porta serial
  boolean flag = false;
  while(flag==false){
	  for(int linha=2;linha<=5;linha++){
		
		digitalWrite(linha,HIGH);	
	
		for(int coluna =6; coluna<=8; coluna++){		    
			if(digitalRead(coluna)==1){
			
				int lin_matriz = linha -2;
				
				int coluna_matriz = coluna-6;
			    
				//Verifica se o valor encontrado e 12 ou maior, sai do loop
				if( matriz[lin_matriz][coluna_matriz] >=12){				
					flag=true;
				}
												
				else{
					Serial.print(matriz[lin_matriz][coluna_matriz]);
					num_aux+= matriz[lin_matriz][coluna_matriz];
				}
	
				while(digitalRead(coluna)==1){}/* Funcao while sem nada, para travar o programa enquanto o usuario
				nao soltar a tecla pressionada */				
			}
		}
		digitalWrite(linha,LOW); //Desliga a porta digital da linha em questao
	  }
  }
  
  valor_temp = num_aux.toFloat();
  return valor_temp;
}


