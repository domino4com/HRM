#include "HRM.h"

HRM::HRM() {
}

void HRM::connectToHeartRateMonitor() {
    Serial.println("Scanning for BLE heart rate monitors...");
    BLEScanResults scanResults = _pBLEScan->start(10);  // Scan for 10 seconds

    for (int i = 0; i < scanResults.getCount(); i++) {
        BLEAdvertisedDevice device = scanResults.getDevice(i);

        if (device.isAdvertisingService(BLEUUID("0000180d-0000-1000-8000-00805f9b34fb"))) {
            Serial.print("Found heart rate monitor: ");
            Serial.println(device.getAddress().toString().c_str());

            _pClient = BLEDevice::createClient();
            Serial.println("Client created, connecting...");

            if (_pClient->connect(&device)) {  // Use pointer to BLEAdvertisedDevice
                Serial.println("Connected to heart rate monitor.");
                BLERemoteService *pRemoteService = _pClient->getService(BLEUUID("0000180d-0000-1000-8000-00805f9b34fb"));

                if (pRemoteService != nullptr) {
                    BLERemoteCharacteristic *pRemoteCharacteristic = pRemoteService->getCharacteristic(BLEUUID("00002a37-0000-1000-8000-00805f9b34fb"));

                    if (pRemoteCharacteristic != nullptr) {
                        Serial.println("Heart rate characteristic found.");
                        if (pRemoteCharacteristic->canNotify()) {
                            pRemoteCharacteristic->registerForNotify([this](BLERemoteCharacteristic *pBLERemoteCharacteristic, uint8_t *data, size_t length, bool isNotify) {
                                if (length > 0) {
                                    _heartrate = data[1];  // Assuming 8-bit HR value
                                }
                            });
                        }
                    } else {
                        Serial.println("Heart rate characteristic not found.");
                    }
                } else {
                    Serial.println("Heart rate service not found.");
                }
            } else {
                Serial.println("Failed to connect.");
            }
            _deviceFound = true;
            break;
        }
    }

    if (!_deviceFound) {
        Serial.println("No heart rate monitor found.");
    }
    _pBLEScan->clearResults();
}

bool HRM::begin() {
    BLEDevice::init("");

    // Start BLE scan
    _pBLEScan = BLEDevice::getScan();
    _pBLEScan->setActiveScan(true);
    _pBLEScan->setInterval(100);
    _pBLEScan->setWindow(99);

    connectToHeartRateMonitor();

    if (_deviceFound) {
        return true;
    } else {
        return false;
    }
}

bool HRM::getData(uint8_t &hrm) {
    if (_pClient && _pClient->isConnected()) {
        hrm = _heartrate;
    } else {
        Serial.println("Lost connection. Trying to reconnect...");
        connectToHeartRateMonitor();
    }
    return true;  // Return true for successful read (add error handling if needed)
}

bool HRM::getJSON(JsonDocument &doc) {
    if (_pClient && _pClient->isConnected()) {
        JsonArray dataArray = doc["HRM"].to<JsonArray>();

        JsonObject dataSet = dataArray.add<JsonObject>();  // First data set
        dataSet["name"] = "Heart Rate";
        dataSet["value"] = _heartrate;
        dataSet["unit"] = "bpm";
    } else {
        Serial.println("Lost connection. Trying to reconnect...");
        connectToHeartRateMonitor();
    }
    return true;
}
