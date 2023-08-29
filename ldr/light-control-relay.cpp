// AC Light Control (Using Relay or Solid State Relay
int ldrPin = A0;  // Pin connected to LDR sensor
int relayPin = 9; // Pin connected to relay module

int threshold = 500; // Value above which it's considered bright

void setup()
{
    pinMode(relayPin, OUTPUT); // Set relay pin as an output
}

void loop()
{
    int ldrValue = analogRead(ldrPin); // Read LDR sensor value

    if (ldrValue < threshold)
    {                                 // Check if it's dark
        digitalWrite(relayPin, HIGH); // Turn on the AC bulb using the relay
    }
    else
    {                                // If it's not dark
        digitalWrite(relayPin, LOW); // Turn off the AC bulb
    }
}
