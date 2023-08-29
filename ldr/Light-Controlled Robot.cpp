// Light-Controlled Robot
int motorEnablePin = 9; // Connect L298 enable pin to digital pin 9 on Arduino
int motorInput1 = 10;   // Connect L298 input 1 to digital pin 10 on Arduino
int motorInput2 = 11;   // Connect L298 input 2 to digital pin 11 on Arduino

int ldrPin = A0;     // Pin connected to LDR sensor
int threshold = 500; // Value above which it's considered bright

void setup()
{
    pinMode(motorEnablePin, OUTPUT); // Set motor enable pin as an output
    pinMode(motorInput1, OUTPUT);    // Set motor input 1 as an output
    pinMode(motorInput2, OUTPUT);    // Set motor input 2 as an output

    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop()
{
    int ldrValue = analogRead(ldrPin); // Read LDR sensor value

    Serial.println(ldrValue); // Display LDR value on the serial monitor

    if (ldrValue < threshold)
    {                                    // Check if it's dark
        digitalWrite(motorInput1, HIGH); // Turn on motor in one direction
        digitalWrite(motorInput2, LOW);
        analogWrite(motorEnablePin, 255); // Set motor speed to maximum
    }
    else
    {                                   // If it's not dark
        digitalWrite(motorInput1, LOW); // Turn off motor
        digitalWrite(motorInput2, LOW);
        analogWrite(motorEnablePin, 0); // Set motor speed to 0 (stop)
    }
}
