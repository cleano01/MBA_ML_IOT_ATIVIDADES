
char c = 'A'; //o tipo char tem que ser declarado em aspas simples
char b = '5';

char s2[] = "arduino";//declarando uma string
char *s3[] = {"frase1", "frase2", "frase1"}; // declarando varias strings em um variavel


String s4 = "Ardunio"; //com esse tipo de declaracao, podemos fazer concatenacao de strings

void setup() {

    Serial.begin(9600);
    Serial.println("inciando ...");

}

void loop() {

  if(isAlpha(c)){//aqui vertifica se e do tipo char e uma letra
    Serial.println(c);
    delay(600);
  }
  else{
    Serial.println("não é letra");
    delay(600);
  }

  
  if(isDigit(b)){//aqui verifica se e do tipo char e um numero
    Serial.println(b);
    delay(600);
  }
  else{
    Serial.println("não é um numero");
  }


  Serial.println(s2[0]);
  delay(600);

  Serial.println(s2);
  delay(600);


  for(int i=0; i <= 2; i++){
    Serial.println(s3[i]);
    delay(500);
  }

  s4+= s2; //concatenando strings
  Serial.println(s4);
  delay(500);

}
