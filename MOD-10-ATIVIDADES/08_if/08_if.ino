
const int led = 7; // porta digital do led
const int bot1 = 8; //porta digital do botao

void setup() {
  pinMode(bot1, INPUT);
  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);// led comeca desligado

}

void loop() {

  if(digitalRead(bot1) == 1){
      digitalWrite(led, HIGH);// led liga

  }

   if(digitalRead(bot1) == 0){
      digitalWrite(led, LOW);// led desligado

  }

}
