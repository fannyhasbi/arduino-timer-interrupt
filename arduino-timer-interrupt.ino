const int ledPin = 5;
const int risePin = 2;
const int lowPin = 4;

void setup() {
  Serial.begin(9600);
  Serial.println("Timer Interrupt");

  pinMode(ledPin, OUTPUT);
  pinMode(risePin, INPUT);
  pinMode(lowPin, INPUT);
}

void loop() {
  if (digitalRead(risePin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(lowPin) == HIGH) {
    digitalWrite(ledPin, LOW);
  }
}
