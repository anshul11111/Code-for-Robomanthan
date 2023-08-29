//automatic street light controller using ldr
int ldrPin = A0;// Define the LDR pin you can change it 
 
int ledPin = 13;// Define the LED pin

int threshold = 500;// Define the threshold value for light intensity changing it will change the sensitivity of the ldr sensor

void setup() {
   pinMode(ledPin, OUTPUT);// Initialize the LED pin as an output you can change it to your convenience
}

void loop() {
  
  int ldrValue = analogRead(ldrPin);// Read the LDR sensor value

  
  if (ldrValue < threshold) {// Check if it's dark (below the threshold)
   
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
   
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
}
