const char *ssid = "2E8";
const char *passwd = "yeetyeet";
const char *dest_ip = "192.168.0.138";
const uint16_t dest_port = 8090;

void network_setup()
{
    WiFi.begin(ssid, passwd);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("wifi connected!");
}

void network_test()
{
    WiFiClient client;
    if (!client.connect(dest_ip, dest_port))
    {
        Serial.println("Did not connect");
        delay(1000);
        return;
    }
    Serial.println("Connected!");
    client.print("Hello World!");
    Serial.println("Disconnecting");
    client.stop();

    delay(10000);
}
