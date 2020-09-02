void setup() {
  // put your setup code here, to run once:
	/*
	Output = saida
	*/
  pinMode(5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // HIGH =  acende o leds

  digitalWrite(5, HIGH);
  delay(1000);

  // LOW = desliga
  digitalWrite(5, LOW);
  delay(9000);
  
}
