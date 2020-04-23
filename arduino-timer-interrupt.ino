const int ledPin = 5;
const int risePin = 2;

void setup() {
  Serial.begin(9600);
  Serial.println("Timer Interrupt");

  pinMode(ledPin, OUTPUT);
  pinMode(risePin, INPUT);
}

void loop() {
  if (digitalRead(risePin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
