#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Set the LCD I2C address

const int ledPin = 12; // Pin number for the LED, we use 12 instead of 13 (internal LED) to prevent blinks during boot
const int delayTime = 250; // Duration of each blink and pauses between blinks (250ms)
const int pauseTime = 2500; // Pause time between digits (2500ms)
const int firstDigitDelay = 3300; // Delay between initial blink and first digit (3300ms)

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  // Initialize the LCD
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
  // Print a message to the LCD
  lcd.print("Current PIN:");
}

void loop() {
  // Loop through all possible PINs from 0000 to 9999
  for (int pin = 0; pin <= 9999; pin++) {
    // Split the PIN into its individual digits
    int digits[4];
    splitPin(pin, digits);

    // Print the current PIN to the Serial Monitor
    Serial.print("Current PIN: ");
    if (pin < 1000) Serial.print("0");
    if (pin < 100) Serial.print("0");
    if (pin < 10) Serial.print("0");
    Serial.println(pin);

    // Print the current PIN to the LCD
    lcd.setCursor(0, 1); // Move to the second line
    if (pin < 1000) lcd.print("0");
    if (pin < 100) lcd.print("0");
    if (pin < 10) lcd.print("0");
    lcd.print(pin);

    // Initial blink to start PIN input
    blinkDigit(1);

    delay(firstDigitDelay); // wait 3.3 seconds before starting to blink the first digit

    // Blink each digit
    for (int i = 0; i < 4; i++) {
      blinkDigit(digits[i]);
    }

    // Pause before moving to the next PIN
    delay(pauseTime);
  }
}

// Function to split a PIN into its individual digits
void splitPin(int pin, int digits[]) {
  for (int i = 3; i >= 0; i--) {
    digits[i] = pin % 10;
    pin /= 10;
  }
}

// Function to blink a digit
void blinkDigit(int digit) {
  if (digit == 0) {
    // Wait for 3 seconds if the digit is 0
    delay(pauseTime);
  } else {
    // Blink the LED (digit) times
    for (int i = 0; i < digit; i++) {
      digitalWrite(ledPin, HIGH); // Turn the LED on
      delay(delayTime); // Wait for 250 milliseconds
      digitalWrite(ledPin, LOW); // Turn the LED off
      delay(delayTime); // Wait for 250 milliseconds
    }
    // Pause for 2.5 seconds before the next digit
    delay(pauseTime);
  }
}