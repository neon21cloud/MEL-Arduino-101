int ledPin() = 13;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledpin, OUTPUT); //Pin 13 puede declararse aqui como LED_BUILTIN
}

void loop() {
  // da 5 o 3.3v. Conectar con multimetro a tierra para ver
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, HIGH);
  delay(1000);
}
