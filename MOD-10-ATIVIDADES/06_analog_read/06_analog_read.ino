
//declaramos pot como uma porta analogica
const int pot = 0;


//ira receber o valor da porta analogica
float val = 0;

void setup() {
  
   //funcao para inciar comunicação do computaor com uma outra frequencia
  Serial.begin(9600);
  Serial.println("Inicializando ...");
  
  
  delay(2000);
}

void loop() {
  //analogRead ira le o valor da porta analogica
  //como pot e 0, entao a porta sera A0, val sera A0
  val = analogRead(pot);


  //aqui aplicamos regra de "3" para saber 
  //o valor que esta sendo em volts
  val = (5*val)/1024;

  
  //valor da porta logica
  Serial.println(val);


  delay(1000);
  
  
}
