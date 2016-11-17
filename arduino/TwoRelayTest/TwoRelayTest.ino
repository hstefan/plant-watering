const int sol0Pin = 13;
const int sol1Pin = 12;

void setup() {
  pinMode(sol0Pin, OUTPUT);
  pinMode(sol1Pin, OUTPUT);
}

void delayPreempt(unsigned long ms) {
  // for now this is just a wrapper for "delay"
  delay(ms);
}

void resetRelays() {
  digitalWrite(sol0Pin, HIGH);
  digitalWrite(sol1Pin, HIGH);
}

void loop() {
  resetRelays();
  // wait 30 seconds before doing anything
  delayPreempt(30000L);

  // enables first solenoid
  digitalWrite(sol0Pin, LOW);
  // waits for sixty seconds
  delayPreempt(60000L);
  // disables first solenoid
  digitalWrite(sol0Pin, HIGH);

  // waits one second
  delayPreempt(1000L);

  // enables second solenoid
  digitalWrite(sol1Pin, LOW);
  // waits 60 seconds
  delayPreempt(60000L);
  // disables second solenoid
  digitalWrite(sol1Pin, HIGH);
}
