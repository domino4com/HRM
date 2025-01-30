#include <ArduinoJson.h>
#include "HRM.h"
HRM input;
float var1;
char s[] = "Heart Rate: %.2f bpm\n";

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nExample Test\n");

    if (input.begin()) {
        Serial.println("Input initialized successfully.");
    } else {
        Serial.println("Failed to initialize input");
        exit(0);
    }
}

void loop() {
    if (input.getData(var1)) {
        Serial.printf(s, var1);
    } else {
        Serial.println("Failed to get input data.");
    }

    delay(1000);
}
