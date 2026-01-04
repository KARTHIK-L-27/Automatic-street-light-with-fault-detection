int ldrPin = A0;
int light1 = 8;
int light2 = 9;

void setup() {
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue < 500) { // Night condition
    digitalWrite(light1, HIGH);
    digitalWrite(light2, HIGH);
  } else {              // Day condition
    digitalWrite(light1, LOW);
    digitalWrite(light2, LOW);
  }

  // Simple fault detection logic (demo)
  if (ldrValue < 500 && digitalRead(light1) == LOW) {
    Serial.println("Fault detected in Street Light 1");
  }

  delay(1000);
}
