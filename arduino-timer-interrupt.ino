const int ledPin = 5;

void setup() {
  Serial.begin(9600);
  Serial.println("Timer Interrupt");

  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
