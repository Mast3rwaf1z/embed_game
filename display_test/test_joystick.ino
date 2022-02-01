void joy_test()
{
    if (!ledc)
    {
        ledcSetup(0, 5000, 8);
        ledcAttachPin(led, 0);
        ledc = true;
    }
    int x_value = analogRead(joy_x);
    int y_value = analogRead(joy_y);
    ledcWrite(0, (x_value + y_value) / 16);
}
void draw()
{
    int x_value = analogRead(joy_x);
    int y_value = analogRead(joy_y);
    if (digitalRead(joy_sw) == HIGH)
    {
        display.clear();
    }
    display.drawString(x_value / 35, y_value / 80, "o");
    display.display();
}