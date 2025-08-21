#include <Arduino.h>
#include <SoftwareSerial.h>
// #define HIGH_LEVEL_CHARGE P0_13

uint32_t curretMillis = 0;
uint32_t previousMillis = 0;

int ledPins[] = {LED_GREEN, LED_BLUE, LED_RED};
int ledIndex = 0;

void setup() {
  Serial.begin(9600); // CDC 
  while ( !Serial ) delay(10);

  for (uint8_t i = 0; i < sizeof(ledPins)/sizeof(int); i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH); // Initialize LEDs to LOW
  }
  
}

void loop() {
  curretMillis = millis();
  if(curretMillis - previousMillis >= 1000) {
    previousMillis = curretMillis;

    // Toggle the LEDs
    switch (ledIndex)
    {
    case 0:
      digitalWrite(ledPins[0], LOW);  // RED
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      break;
    case 1:
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], LOW);  // GREEN
      digitalWrite(ledPins[2], HIGH);
      break;
    case 2:
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], LOW);  // BLUE
    default:
      break;
    }
    ledIndex++;
    if (ledIndex >= sizeof(ledPins)/sizeof(int)) {
      ledIndex = 0; // Reset index after all LEDs have been toggled
    }
    Serial.println("LEDs toggled");
  }
}

