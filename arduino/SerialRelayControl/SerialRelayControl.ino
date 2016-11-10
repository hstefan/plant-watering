const int sol0Pin = 11;
const int sol1Pin = 12;
const int sol2Pin = 13;

long lastSerialCommand = 0;

void setup() {
  Serial.begin(9600);

  pinMode(sol0Pin, OUTPUT);
  pinMode(sol1Pin, OUTPUT);
  pinMode(sol2Pin, OUTPUT);
}

void resetAll() {
  digitalWrite(sol0Pin, LOW);
  digitalWrite(sol1Pin, LOW);
  digitalWrite(sol2Pin, LOW);
}

// control: each bit enables or disables the solenoid outputs
void updateSolenoids(int control) {
  digitalWrite(sol0Pin, control & 0x1 ? HIGH : LOW);
  digitalWrite(sol1Pin, control & 0x2 ? HIGH : LOW);
  digitalWrite(sol2Pin, control & 0x4 ? HIGH : LOW);
}

void loop() {
  while (Serial.available() > 0) {
    int control = Serial.read();
    Serial.write(control);
    Serial.flush();
    if (Serial.available() == 0)
      updateSolenoids(control);
    lastSerialCommand = millis();
  }

  if (millis() - lastSerialCommand > 800)
    resetAll();

  delay(300);
}
