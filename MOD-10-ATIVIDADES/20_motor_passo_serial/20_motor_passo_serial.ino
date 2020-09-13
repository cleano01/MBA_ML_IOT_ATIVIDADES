const int botao1=9, botao2=10; 

void setup() {
	pinMode(botao1, INPUT);
	pinMode(botao2, INPUT);
	
	//incializando as portas 2 a 5
	for(int p = 2; p <= 5; p++){
		pinMode(p, OUTPUT);
		digitalWrite(p, LOW);
	}
	
	
}

void loop() {
	// faz esse sentindo o motor >>>>>>>>
	if(digitalRead(botao1) == 1 && digitalRead(botao2) == 0){
	
		for(int p=2; p <=5; p++){
		 digitalWrite(p,HIGH);
		 delay(50);
		 digitalWrite(p,LOW);
		}
	}
	
	//faz esse sentindo  motor <<<<<<<<<<
	if(digitalRead(botao1) == 0 && digitalRead(botao2) == 1){
	
	for(int p=5;p>=2;p--){
		 digitalWrite(p,HIGH);
		 delay(50);
		 digitalWrite(p,LOW);
		}
	}

		
	
}
