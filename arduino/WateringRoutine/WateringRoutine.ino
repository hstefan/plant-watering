#include <avr/wdt.h>

const int sol0Pin = 13;
const int sol1Pin = 12;

void setup() {
  pinMode(sol0Pin, OUTPUT);
  pinMode(sol1Pin, OUTPUT);

  resetRelays();

  // configures watchdog with one second timeout
  wdt_enable(WDTO_1S);
}

void safeDelay(unsigned long ms) {
  const unsigned long start = millis();
  while (millis() - start < ms)
    wdt_reset();
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
  const unsigned long start = millis();

  // wait 30 seconds before doing anything
  safeDelay(30000L);

  // enables first valve
  digitalWrite(sol0Pin, LOW);
  // waits 2 minutes before closing the first valve
  safeDelay(120000L);
  // disables first valve
  digitalWrite(sol0Pin, HIGH);

  // waits 500 ms
  safeDelay(500L);

  // enables second valve
  digitalWrite(sol1Pin, LOW);
  // waits 45 seconds before closing the first valve
  safeDelay(45000L);
  // disables second valve
  digitalWrite(sol1Pin, HIGH);

  // waits for 12 hours
  safeDelay(43200000L - (millis() - start));
}
