int matriz[4][3] = 	{ {1,2,3},
					  {4,5,6},
					  {7,8,9},
					  {12,0,13},
					};
 

void setup() {
   Serial.begin(9600);
   
   //saidas(linhas)
   for(int porta = 2; porta <= 5; porta++){
	pinMode(porta, OUTPUT);
	digitalWrite(porta, LOW);
   }

   //entradas (colunas)
   for(int porta = 6 ; porta <= 8; porta++){
	 pinMode(porta, INPUT);
   } 
	
   Serial.println("iniciando ...");
   delay(50);
}

void loop() {
 
	for(int linha = 2; linha <= 5; linha++){
		digitalWrite(linha, HIGH); //envia o sinal para as linhas
		
		for(int coluna = 6; coluna<= 8; coluna++){

			//verifica se a coluna foi acionada
			if(digitalRead(coluna) == 1){
			  /*Serial.println("linha: ");
			  Serial.println(linha);
               Serial.println("coluna: ");
			  Serial.println(coluna);*/


			  int linha_aux = linha-2;
			  int coluna_aux = coluna-6;
				
			  if(matriz[linha_aux][coluna_aux] == 12){
			   Serial.println("*");
			  }			    	
			 
			  else if(matriz[linha_aux][coluna_aux] == 13){
			    Serial.println("#");
			  }
			
			  else{
			   Serial.println(matriz[linha_aux][coluna_aux]);
			   Serial.println("aqui");
			  }

        while(digitalRead(coluna)==1){
         //fica tudo branco, caso deixe o botao precionado
        }
			
		  }
	   }
   digitalWrite(linha, LOW); //desativa a linha
	}
}
