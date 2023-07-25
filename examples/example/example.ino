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
    float temperature, humidity;
    iwa.getData(temperature, humidity);
    Serial.printf("Temperature: %.2f ºC, Humidity: %.2f %%RH\n", temperature, humidity);

    delay(1000);
}
