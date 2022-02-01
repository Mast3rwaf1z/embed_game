void hw_setup()
{
    // led
    pinMode(led, OUTPUT);
    // joystick
    pinMode(joy_x, INPUT);
    pinMode(joy_y, INPUT);
    pinMode(joy_sw, INPUT);
}
void display_setup()
{
    display.init();
    display.setFont(ArialMT_Plain_10);
    display.setColor(WHITE);
    display.display();
}
