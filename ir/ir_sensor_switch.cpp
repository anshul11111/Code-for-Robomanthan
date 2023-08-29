const int irPin = 2;   // IR sensor pin
const int ledPin = 13; // LED pin

void setup()
{
    pinMode(ledPin, OUTPUT); // Set LED pin as output
    pinMode(irPin, INPUT);   // Set IR sensor pin as input
}

void loop()
{
    int irValue = digitalRead(irPin); // Read IR sensor value

    if (irValue == HIGH)
    {
        digitalWrite(ledPin, HIGH); // Turn on LED if object detected
    }
    else
    {
        digitalWrite(ledPin, LOW); // Turn off LED if no object detected
    }

    delay(100); // Delay for stability
}
