void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  if (Serial.available() > 0) {
    Serial.read(); // Read the incoming byte (not used in this case)
    unsigned long timestamp = millis(); // Get current time in milliseconds
    Serial.println(timestamp); // Send timestamp back to PC
  }
}
