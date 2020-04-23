const int ledPin = 5;
const int risePin = 2;
const int lowPin = 4;

// 16MHz = 16x10^6 Hz
// max of 0xFFFF is 65535
// 65535 - ( 16x10^6 x 2 / 1024 )
float counter = 34285; // 2 seconds

void setup() {
  Serial.begin(9600);
  Serial.println("Timer Interrupt");
  Serial.println(counter);

  pinMode(ledPin, OUTPUT);
  pinMode(risePin, INPUT);
  pinMode(lowPin, INPUT);

  noInterrupts();

  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = counter;

  // set prescaler value to 1024
  TCCR1B |= (1 << CS10) | (1 << CS12);

  // enable global timer1 overflow flag
  TIMSK1 |= (1 << TOIE1);

  interrupts();
}

void loop() {
  if (digitalRead(risePin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(lowPin) == HIGH) {
    digitalWrite(ledPin, LOW);
  }
}
