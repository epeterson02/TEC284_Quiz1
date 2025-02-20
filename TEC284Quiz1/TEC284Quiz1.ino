// Pins for LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Pins for buttons
const int redButton = 2;
const int greenButton = 3;
const int blueButton = 4;

// Stores current color state when button is pressed
int redState = 0;
int greenState = 0;
int blueState = 0;

// Function to update LED color
void setColor(int red, int green, int blue) {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    pinMode(redButton, INPUT_PULLUP); // Pullup resistor to avoid noise
    pinMode(greenButton, INPUT_PULLUP);
    pinMode(blueButton, INPUT_PULLUP);

    setColor(0, 0, 0);  // Start with LED off
}

void loop() {
    redState = !digitalRead(redButton);
    greenState = !digitalRead(greenButton);
    blueState = !digitalRead(blueButton);
     // Check button states and mix colors by multiplying button state (1 or 0) by 255
    if (redState || greenState || blueState) {
        setColor(redState * 127, greenState * 255, blueState * 255); //adjusted red color to improve mixing
    }

}