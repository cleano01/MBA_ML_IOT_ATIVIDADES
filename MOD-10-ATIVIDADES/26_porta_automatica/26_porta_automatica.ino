//teclado(linhas e colunas)
int matriz[4][3] ={ {1,2,3},
{4,5,6},{7,8,9},{12,0,13},};


//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
//Define os pinos que serao utilizados para ligado ao display
LiquidCrystal lcd(12, 11, 9, 8, 7, 6);


#include "Servo.h" // Inclui a Biblioteca Servo.h 
Servo meuservo; // Cria o objeto servo para programa��o 
int angulo = 0;
int angulo_max = 180;//aberto


const String senha = "1230";

int botao_insert = 1;//A1
int botao_reset = 2;//A2


void setup() {  
   Serial.begin(9600);

   meuservo.attach(10); // Declara o pino do servo
   meuservo.write(angulo);

  
   lcd.begin(16, 2); //Define o numero de colunas e linhas do LCD
   lcd.clear(); //Limpa a tela

   lcd.setCursor(2.5, 0); //Posiciona o cursor na coluna 1, linha 0;  
   lcd.print("Iniciando ..."); //Envia o texto entre aspas para o LCD
	
   lcd.setCursor(3,1);
   lcd.print("LCD 16x2");

   delay(1000);
   
   lcd.clear();
}

  
void loop() {

  String receber_senha = teclado();

   lcd.setCursor(1, 0); //Posiciona o cursor na coluna 1, linha 0;  
   lcd.print("Verificando..."); //Envia o texto entre aspas para o LCD
   delay(1000);
   
  if(senha == receber_senha )	{
     lcd.clear();
     lcd.setCursor(1, 0); //Posiciona o cursor na coluna 1, linha 0;  
     lcd.print("Porta aberta"); //Envia o texto entre aspas para o LCD
     
	meuservo.write(angulo_max);
     
	delay(3000);
	
	lcd.clear();
	
	lcd.setCursor(1, 0);  
    lcd.print("Porta fechada"); 

    delay(1000);

    meuservo.write(angulo);
    
    lcd.clear();
    receber_senha ="";
  }
  else{
     lcd.clear();
     lcd.setCursor(1, 0);  
     lcd.print("Senha errada"); 

     delay(3000);
	 lcd.clear();
   
   }

}


String teclado(){ 
  String num_aux = ""; 

  lcd.setCursor(1, 0);  
  lcd.print("Digite a senha");

  boolean flag = false;

  while(flag==false){
	  for(int linha=2;linha<=5;linha++){		
		digitalWrite(linha,HIGH);	
	
		for(int coluna =5; coluna<=7; coluna++){		    
		  if(analogRead(coluna) >= 900){ //le se esta entrando tensao vindo do telcado, na porta serial
			
				int lin_matriz = linha -2;
				
				int coluna_matriz = coluna-5;
			    
				if( matriz[lin_matriz][coluna_matriz] == 12 ){				
				 num_aux+="*";
         		 for(int n = 0; n <= (num_aux.length()-1); n++){
					lcd.setCursor(n, 1); //Posiciona o cursor na coluna 0, linha 1;   
  					lcd.print("@"); //imprime o valor da variavel contador
					}
				}
				else if(matriz[lin_matriz][coluna_matriz] == 13){
				  num_aux+="#";
				  for(int n = 0; n <= (num_aux.length()-1); n++){
					lcd.setCursor(n, 1); 
  					lcd.print("@"); 
					}
				}												
				else{
					Serial.print(matriz[lin_matriz][coluna_matriz]);
					num_aux+= matriz[lin_matriz][coluna_matriz];
					
				  for(int n = 0; n <= (num_aux.length()-1); n++){
						lcd.setCursor(n, 1);    
  					lcd.print("@"); 
					}
				}
	 			
				if(analogRead(botao_insert) >=900){
					flag = true;	
					delay(100);
					lcd.clear();			 
				}
				else if(analogRead(botao_reset) >=900){
				 	lcd.clear();			 
		          	num_aux = ""; 
				  
					lcd.setCursor(3,1); 
		          	lcd.print("Resetando...");
						  
		          	delay(300);						
					lcd.clear();			 
				}				
			while(analogRead(coluna)>=900){
	           /* Funcao while sem nada, para travar 
			  o programa enquanto o usuario 	nao soltar a tecla pressionada */	
	         	if(analogRead(botao_insert) >=900){
					flag = true;	
					delay(100);
					lcd.clear();			 
					}
						 
		         else if(analogRead(botao_reset) >=900){
				    lcd.clear();			 
					num_aux = ""; 
				    lcd.setCursor(3,1); 
		             lcd.print("Resetando...");
						  
		             delay(1000);						
				    lcd.clear();			 
				}				
	        	}//fim while			
		}
		}

		if(analogRead(botao_insert) >=900){
			flag = true;	
			delay(100);
			lcd.clear();			 
		}
		else if(analogRead(botao_reset) >=900){
			lcd.clear();			 
      num_aux = ""; 
			lcd.setCursor(3,1); 
      lcd.print("Resetando...");
				  
      delay(300);						
			lcd.clear();			 
		}				
		digitalWrite(linha,LOW); //Desliga a porta digital da linha em questao
	  }
  }
  Serial.println(num_aux);
  return num_aux;
}
