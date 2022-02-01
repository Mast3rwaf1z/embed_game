void screensaver()
{
    if (x_iterator >= display_x - 4)
    {
        digitalWrite(led, LOW);
        x_state = false;
    }
    else if (x_iterator <= 0)
    {
        digitalWrite(led, HIGH);
        x_state = true;
    }
    if (y_iterator >= display_y - 5)
    {
        y_state = false;
    }
    else if (y_iterator <= 0)
    {
        y_state = true;
    }
    if (x_state)
    {
        x_iterator = x_iterator + 2;
    }
    else
    {
        x_iterator--;
    }
    if (y_state)
    {
        y_iterator = y_iterator + 2;
    }
    else
    {
        y_iterator--;
    }
    display.clear();
    display.drawString(x_iterator, y_iterator, "o");
    display.display();
    delay(10);
}
void display_debug()
{
    for (int i = 0; i < display_x; i++)
    {
        for (int j = 0; j < display_y; j++)
        {
            display.setPixel(i, j);
            delay(0.1);
        }
        display.display();
    }
    display.clear();
}