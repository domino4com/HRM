#include <ArduinoJson.h>
#include <Wire.h>

#include "IWA.h"
IWA iwa;

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nIWA Test\n");

    Wire.setPins(I2C_SDA, I2C_SCL);
    Wire.begin();

    if (iwa.begin()) {
        Serial.println("IWA sensor initialized successfully.");
    } else {
        Serial.println("Failed to initialize IWA sensor!");
        exit(0);
    }
}

void loop() {
    StaticJsonDocument<256> doc;
    JsonObject root = doc.to<JsonObject>();

    if (iwa.getJSON(root)) {
        serializeJsonPretty(root, Serial);
        Serial.println();
    } else {
        Serial.println("Failed to IWA data.");
    }

    delay(2000);
}
