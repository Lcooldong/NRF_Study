// LEDR, LEDG, LEDB
#define BUFFER_SIZE 128

volatile bool led_state = 0;
volatile int led_count = 0;

char buffer[BUFFER_SIZE] = {0,};

enum LED_COLOR_t{
 RED = 0,
 GREEN,
 BLUE 
}LED_COLOR;

void setup() {
  Serial.begin(115200);
  
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
}

void loop() {
  

  sprintf(buffer, "count : %d, state : %d",led_count, led_state);
  Serial.println(buffer);
  
  led_state = !led_state;
  if(led_state == 0)
  {
    led_count++;
  }
  
  switch(led_count)
  {
    case RED:
      digitalWrite(LEDR, led_state);
      break;
    case GREEN:
      digitalWrite(LEDG, led_state);
      break;
    case BLUE:
      digitalWrite(LEDB, led_state);
      break;
    default:
      digitalWrite(LEDR, led_state);
      led_count = 0;
      break;  
  }
  delay(500);
}
