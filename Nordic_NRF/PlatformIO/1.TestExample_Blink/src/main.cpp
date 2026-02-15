#include <Arduino.h>

unsigned long count = 0;

void setup() {
  Serial.begin(115200);
  // pinMode(LED_BUILTIN, OUTPUT); // RED
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT); 
  pinMode(LED_BLUE, OUTPUT);

  digitalWrite(LED_RED, HIGH);  // HIGH -> OFF (PULL-UP)
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
}

void loop() {

  count++;

  int value = count % 3;

  switch (value)
  {
  case 0:
    digitalWrite(LED_RED, LOW);
    break;
  case 1:
    digitalWrite(LED_GREEN, LOW);
    break;
  case 2:
    digitalWrite(LED_BLUE, LOW);
    break;

  default:
    break;
  }
  Serial.print(value);
  Serial.println(" : ON");
  // wait for a second
  delay(500);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  Serial.println("OFF");
   // wait for a second
  delay(500);
}

