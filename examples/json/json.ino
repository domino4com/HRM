#include <ArduinoJson.h>
#include <Wire.h>
#ifndef I2C_SDA
#define I2C_SDA SDA
#endif
#ifndef I2C_SCL
#define I2C_SCL SCL
#endif

#include "IWA.h"
IWA input;

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nIWA JSON Test\n");

    Wire.setPins(I2C_SDA, I2C_SCL);
    Wire.begin();

    if (input.begin()) {
        Serial.println("IWA initialized successfully.");
    } else {
        Serial.println("Failed to initialize IWA!");
        exit(0);
    }
}

void loop() {
    StaticJsonDocument<256> doc;
    JsonObject root = doc.to<JsonObject>();

    if (input.getJSON(root)) {
        serializeJsonPretty(root, Serial);
        Serial.println();
    } else {
        Serial.println("Failed to get IWA data.");
    }

    delay(2000);
}
