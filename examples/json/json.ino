#include <ArduinoJson.h>
#include "HRM.h"
HRM input;

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nJSON Test\n");

    if (input.begin()) {
        Serial.println("Input initialized successfully.");
    } else {
        Serial.println("Failed to initialize input!");
        while(true);
    }
}

void loop() {
    JsonDocument doc;

    if (input.getJSON(doc)) {
        serializeJsonPretty(doc, Serial);
        Serial.println();
    } else {
        Serial.println("Failed to get input data.");
    }

    delay(2000);
}
