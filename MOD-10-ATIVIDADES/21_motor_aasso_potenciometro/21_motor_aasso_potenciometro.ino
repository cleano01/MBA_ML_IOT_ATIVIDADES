const int pot = 0;//potenciometro
int variations=0; 

void setup() {
		
	//incializando as portas 2 a 5
	for(int p = 2; p <= 5; p++){
		pinMode(p, OUTPUT);
		digitalWrite(p, LOW);
	}
	
	
}

void loop() {

   // faz esse sentindo o motor >>>>>>>>
   for(int p=2; p <=5; p++){
		 digitalWrite(p,HIGH);
		 variations = map(analogRead(pot), 0, 1024, 10, 100);
		 delay(variations);
		 digitalWrite(p,LOW);
		
	}
	
	

		
	
}