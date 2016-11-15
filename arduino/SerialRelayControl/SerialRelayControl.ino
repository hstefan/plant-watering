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
  // REVERSE LOGIC
  digitalWrite(sol0Pin, HIGH);
  digitalWrite(sol1Pin, HIGH);
  digitalWrite(sol2Pin, HIGH);
}

// control: each bit enables or disables the solenoid outputs
void updateSolenoids(int control) {
  // relays use inverse logic, so we *enable* them with LOW and
  // disable with HIGH, leaving the interrupted wire plugged on
  // "normally closed" to prevent flooding if something goes
  // wrong
  digitalWrite(sol0Pin, control & 0x1 ? LOW : HIGH);
  digitalWrite(sol1Pin, control & 0x2 ? LOW : HIGH);
  digitalWrite(sol2Pin, control & 0x4 ? LOW : HIGH);
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
