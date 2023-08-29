// Pin definitions for IR sensors
const int leftIRPin = A0;
const int centerIRPin = A1;
const int rightIRPin = A2;

// Motor pins
const int leftMotorPin1 = 2;
const int leftMotorPin2 = 3;
const int rightMotorPin1 = 4;
const int rightMotorPin2 = 5;

void setup()
{
    // Set motor pins as output
    pinMode(leftMotorPin1, OUTPUT);
    pinMode(leftMotorPin2, OUTPUT);
    pinMode(rightMotorPin1, OUTPUT);
    pinMode(rightMotorPin2, OUTPUT);

    // Set IR sensor pins as input
    pinMode(leftIRPin, INPUT);
    pinMode(centerIRPin, INPUT);
    pinMode(rightIRPin, INPUT);
}

void loop()
{
    // Read sensor values
    int leftIRValue = digitalRead(leftIRPin);
    int centerIRValue = digitalRead(centerIRPin);
    int rightIRValue = digitalRead(rightIRPin);

    // Check sensor readings and adjust motors
    if (leftIRValue == LOW && centerIRValue == LOW && rightIRValue == LOW)
    {
        // Move forward
        digitalWrite(leftMotorPin1, HIGH);  // Turn left motor forward
        digitalWrite(leftMotorPin2, LOW);   // Turn off left motor reverse
        digitalWrite(rightMotorPin1, HIGH); // Turn right motor forward
        digitalWrite(rightMotorPin2, LOW);  // Turn off right motor reverse
    }
    else if (leftIRValue == HIGH && centerIRValue == LOW && rightIRValue == LOW)
    {
        // Turn slightly left
        digitalWrite(leftMotorPin1, LOW);   // Turn off left motor forward
        digitalWrite(leftMotorPin2, HIGH);  // Turn left motor reverse
        digitalWrite(rightMotorPin1, HIGH); // Turn right motor forward
        digitalWrite(rightMotorPin2, LOW);  // Turn off right motor reverse
    }
    else if (leftIRValue == LOW && centerIRValue == LOW && rightIRValue == HIGH)
    {
        // Turn slightly right
        digitalWrite(leftMotorPin1, HIGH);  // Turn left motor forward
        digitalWrite(leftMotorPin2, LOW);   // Turn off left motor reverse
        digitalWrite(rightMotorPin1, LOW);  // Turn off right motor forward
        digitalWrite(rightMotorPin2, HIGH); // Turn right motor reverse
    }
    else if (leftIRValue == HIGH && centerIRValue == LOW && rightIRValue == HIGH)
    {
        // Stop and reposition (adjust this according to your needs)
        digitalWrite(leftMotorPin1, LOW);  // Turn off left motor forward
        digitalWrite(leftMotorPin2, LOW);  // Turn off left motor reverse
        digitalWrite(rightMotorPin1, LOW); // Turn off right motor forward
        digitalWrite(rightMotorPin2, LOW); // Turn off right motor reverse
        delay(500);                        // Delay for repositioning
    }
}
