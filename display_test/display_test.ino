#include <SSD1306.h>
#include <WiFi.h>
const int display_x = 127;
const int display_y = 63;
SSD1306 display(0x3c, 5, 4);
bool x_state = true, y_state = true;
int x_iterator = 0, y_iterator = 0;
const int led = 16;
bool ledc = false;
const int joy_x = 25, joy_y = 26, joy_sw = 15;

void setup()
{
  hw_setup();
  digitalWrite(led, HIGH);
  // network_setup();
  display_setup();
  display_debug();
  Serial.begin(9600);
  digitalWrite(led, LOW);
}

void loop()
{
  test_stage();
}
