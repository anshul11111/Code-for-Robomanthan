// Define IR sensor input pin
const int irSensorPin = 2;

// Define solenoid lock control pin
const int solenoidPin = 3;

void setup()
{
    pinMode(irSensorPin, INPUT);  // Set IR sensor pin as input
    pinMode(solenoidPin, OUTPUT); // Set solenoid lock control pin as output
}

void loop()
{
    // Read the IR sensor state
    int irSensorState = digitalRead(irSensorPin);

    if (irSensorState == HIGH)
    {
        // If IR sensor detects an object, unlock the solenoid lock
        digitalWrite(solenoidPin, HIGH); // Apply power to solenoid
        delay(1000);                     // Keep solenoid powered for 1 second
        digitalWrite(solenoidPin, LOW);  // Turn off solenoid
    }
}
