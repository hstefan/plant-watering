const int sol0Pin = 13;
const int sol1Pin = 12;

void setup() {
  pinMode(sol0Pin, OUTPUT);
  pinMode(sol1Pin, OUTPUT);
  resetRelays();
}

void delayPreempt(unsigned long ms) {
  // for now this is just a wrapper for "delay"
  delay(ms);
}

void resetRelays() {
  digitalWrite(sol0Pin, HIGH);
  digitalWrite(sol1Pin, HIGH);
}

/*
 * The schedule below waits 30 seconds, enables first valve for 2 minutes,
 * waits 500ms, enables second valve for 2 minutes, sleeps for 12 hours and
 * repeats.
 */
void loop() {
  unsigned long start = millis();

  // wait 30 seconds before doing anything
  delayPreempt(30000L);

  // enables first valve
  digitalWrite(sol0Pin, LOW);
  // waits 2 minutes before closing the first valve
  delayPreempt(120000L);
  // disables first valve
  digitalWrite(sol0Pin, HIGH);

  // waits 500 ms
  delayPreempt(500L);

  // enables second valve
  digitalWrite(sol1Pin, LOW);
  // waits 2 minutes before closing the first valve
  delayPreempt(1200000L);
  // disables second valve
  digitalWrite(sol1Pin, HIGH);

  // waits for 12 hours
  delayPreempt(43200000L - (millis() - start);
}
