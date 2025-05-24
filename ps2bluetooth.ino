#define DEBUG 1
#define ARDUINOTRACE_ENABLE DEBUG
#include <ArduinoTrace.h>

#include <Arduino.h>
#include <PS2KeyAdvanced.h>

#define PS2_CLK_PIN 14
#define PS2_DATA_PIN 27

PS2KeyAdvanced keyboard;

void setup()
{
    Serial.begin(115200);
    Serial.println("ESP32 PS/2 Keyboard reader init");

    keyboard.begin(PS2_DATA_PIN, PS2_CLK_PIN);

    Serial.println("Keyboard is ready");
}

void loop()
{
    if (keyboard.available())
    {
        int key = keyboard.read();
    

        DUMP(key);



    } 
}
