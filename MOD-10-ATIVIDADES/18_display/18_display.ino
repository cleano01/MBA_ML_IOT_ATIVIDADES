byte numeros[10][8] = { { 0,0,1,1,1,1,1,1 },  // = numero 0 
                         { 0,0,0,0,0,1,1,0 },  // = numero 1
                         { 0,1,0,1,1,0,1,1 },  // = numero 2
                         { 0,1,0,0,1,1,1,1 },  // = numero 3
                         { 0,1,1,0,0,1,1,0 },  // = numero 4
                         { 0,1,1,0,1,1,0,1 },  // = numero 5
                         { 0,1,1,1,1,1,0,1 },  // = numero 6
                         { 0,0,0,0,0,1,1,1 },  // = numero 7
                         { 0,1,1,1,1,1,1,1 },  // = numero 8
                         { 0,1,1,0,0,1,1,1 },  // = numero 9
                         };
void setup() {
  Serial.begin(9600); 
  Serial.println("inicializando display...");
  delay(10);

  for(int s=0; s<1; s++){
    pinMode(s,OUTPUT);
  }

  //todas as portas desligadas
  desliga_leds();
}


void loop() {
  value_leds();//imprimi os numeros

  desliga_leds(); //chama uma funcao que desliga todos os pinos
  delay(4000); //4 segundos antes de reiniciar o programa
}

void desliga_leds(){
  for(int l = 2; l <=9; l++){
    digitalWrite(l, LOW);//porta desligada
  }
}


void value_leds(){
   for (int i = 0; i <=9; i++){
    Serial.println(i); 
    //varia o pino que vai ser utilizado "C" e a coluna que representa aquele pino "C-2"
   		for (int c = 2; c <= 9; c++){ 
        		digitalWrite(c, numeros[i][c-2]);//define se o pino "C" vai ficar ligado ou desligado "numeros[n-2]"
     	}
   delay(1000); //espera 1 segundo antes de trocar de numero
  }
}
