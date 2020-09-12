//Programa: Teste de Display LCD 16 x 2
//
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que ser�o utilizados para liga��o ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int botao = 13; //define a porta digital do botao

boolean flag = false;
int count=1;
 
void setup(){
     pinMode(botao, INPUT);//define que a porta digital do botao e saida
 	 

 	 lcd.begin(16, 2); //Define o numero de colunas e linhas do LCD
	 lcd.clear(); //Limpa a tela
	
	  lcd.setCursor(1, 0); //Posiciona o cursor na coluna 1, linha 0;  
	  lcd.print("Cleano Ferreira"); //Envia o texto entre aspas para o LCD
	  
	  lcd.setCursor(3, 1); //Posiciona o cursor na coluna 3, linha 1;
	  lcd.print(" LCD 16x2"); //Envia o texto entre aspas para o LCD
	
	  delay(1000);//Delay de 1 segundo
	   
	  
	  for (int i = 0; i < 1; i++){ //For ser� executado duas vezes
	    lcd.scrollDisplayLeft(); //Rolagem para a esquerda
	    delay(200); //Delay de 0.3 segundos
	  }
	
	  for (int i = 0; i < 1; i++){ //For ser� executado duas vezes
	    lcd.scrollDisplayLeft(); //Rolagem para a esquerda
	    delay(200); //Delay de 0.3 segundos
	  }
	  
	 
	
	  for (int i = 0; i < 2; i++){ //For ser� executado duas vezes
	    lcd.scrollDisplayRight(); //Rolagem para a direita
	    delay(200); //Delay de 0.3 segundos
	  }
	  
	  for (int i = 0; i < 1; i++){ //For ser� executado duas vezes
	    lcd.scrollDisplayLeft(); //Rolagem para a esquerda
	    delay(200); //Delay de 0.3 segundos
	  }
	
	
	  delay(2000);
	  lcd.clear(); 
	  lcd.setCursor(3, 0);
	
	  lcd.print("Ola Mundo!!");
	 for (int i = 0; i <=11; i++){
	    lcd.scrollDisplayLeft(); //Rolagem para a esquerda
	    delay(400); 
	  }
	
	  for (int i = 0; i < 2; i++){ 
	    lcd.scrollDisplayLeft(); //Rolagem para a esquerda
	    delay(200); 
	  }

  
}
 
void loop(){

  if(digitalRead(botao)==1 && flag==false){
    	lcd.setCursor(0, 1); //Posiciona o cursor na coluna 0, linha 1;  
	lcd.print(count); //imprime o valor da variavel contador
	count++; //incrementa em 1 o valor do contador
	flag=true; //muda o stado da flag
  }
  if(digitalRead(botao)==0){ //se o botao nao estiver pressionado
	flag=0; //volta o valor do flag para 0
  }

 

  
  
}	