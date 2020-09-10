void setup() {
  // put your setup code here, to run once:
  for(int i=2; i <= 9; i++){
    pinMode(i, OUTPUT);// delcarando porta como sadida
  }

  for(int i=2; i <= 9; i++){
    digitalWrite(i, LOW);// delcarando leds para inicar desligado
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=2; i <= 9; i++){
    digitalWrite(i, HIGH);// ligando os leds
    delay(300);
  }


  for(int i=2; i <= 9; i++){
    digitalWrite(i, LOW);// desligando os leds 
    delay(300);
  }

}
