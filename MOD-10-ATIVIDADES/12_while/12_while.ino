
const int rele = 4;
const int botao = 7;
int flag = 0;

void setup() {
  
  Serial.begin(9600); //incializa a porta serial(externa)
  Serial.println("incializando ...");
  delay(500);

  pinMode(botao, INPUT);
  pinMode(rele, OUTPUT);// declara  rele como saida

  digitalWrite(rele, LOW);//declara a porta do rele como desligada
  
}

void loop() {

  if(digitalRead(botao) ==1 & flag == 0){
    Serial.println("sistema ligad ...");
    flag=2;
  }


  while(flag){

    digitalWrite(rele, HIGH);//liga a porta do rele, e ativa a porta externa do arduirno
  
    if(digitalRead(botao) == 0){
      flag = 3;
    }


    if(digitalRead(botao) == 1 & flag == 3){
      //quando o botao for acinado entra na condicao, junto com falg =3
       Serial.println("botao acionado novamente");

       digitalWrite(rele, LOW);
      
       Serial.println("O sistema foi desligado!"); 
    }


    //esse volta a primeira condicao
    if(digitalRead(botao) == 0){
      flag = 0;
    }
  }

}
