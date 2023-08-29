// Define the pins for IR sensor and pump
const int irSensorPin = 2; // IR sensor output pin
const int pumpPin = 3;     // Pump control pin

void setup()
{
    pinMode(pumpPin, OUTPUT); // Set pump pin as output

   
}

void loop()
{
    // Read the value of the IR sensor pin
    int irValue = digitalRead(irSensorPin);

    // Check if the IR sensor detects an object (e.g., a hand)
    if (irValue == HIGH)
    {
        // Activate the pump for a certain duration (1 seconds)
        digitalWrite(pumpPin, HIGH); // Turn on the pump
        delay(1000);                 // Pump remains on for 1 seconds
        digitalWrite(pumpPin, LOW);  // Turn off the pump
    }
}
