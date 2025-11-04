int counter = 0; // Start at Green (Normal Operation)
String dir = "";

// LEDs
const int LED1 = 6; // Green - Normal Operation
const int LED2 = 7; // Yellow - Primary Trip
const int LED3 = 5; // Red - Backup Trip

// Relays
const int RELAY_A = 8; // Relay for Normal Operation
const int RELAY_B = 9; // Relay for Primary Trip
const int RELAY_C = 10; // Relay for Backup Trip

// Rotary Encoder pins
const int CLK = 3;
const int DT = 4;

unsigned long last_run = 0;

void setup() {
Serial.begin(9600);

pinMode(CLK, INPUT_PULLUP);
pinMode(DT, INPUT_PULLUP);

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);

pinMode(RELAY_A, OUTPUT);
pinMode(RELAY_B, OUTPUT);
pinMode(RELAY_C, OUTPUT);

updateOutputs(); // Set initial state

attachInterrupt(digitalPinToInterrupt(CLK), shaft_moved, FALLING);
}

void shaft_moved() {
if (millis() - last_run > 5) {
if (digitalRead(DT) == HIGH) counter++;
else counter--;

// Wrap counter 0 -> 1 -> 2 -> 0 ...
if (counter > 2) counter = 0;
if (counter < 0) counter = 2;

last_run = millis();
updateOutputs();
}
}

void loop() {
Serial.print("Counter: ");
Serial.println(counter);
delay(100);
}

void updateOutputs() {
// Reset all LEDs and Relays first
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(RELAY_A, LOW);
digitalWrite(RELAY_B, LOW);
digitalWrite(RELAY_C, LOW);

// Map counter to LEDs and Relays
if (counter == 0) {
// Green - Normal Operation
digitalWrite(LED1, HIGH);
digitalWrite(RELAY_A, HIGH);
}
else if (counter == 1) {
// Yellow - Primary Trip
digitalWrite(LED3, HIGH);
digitalWrite(RELAY_C, HIGH);
}
else if (counter == 2) {
// Red - Backup Trip
digitalWrite(LED2, HIGH);
digitalWrite(RELAY_B, HIGH);
}
}
