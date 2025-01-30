#ifndef HRM_H
#define HRM_H
#include "Arduino.h"
#include <ArduinoJson.h>
#include <BLEDevice.h>
#include <BLEClient.h>
#include <BLEScan.h>
#include <BLEUtils.h>


class HRM {
   public:
    HRM();
    bool begin();
    bool getData(uint8_t &hrm);
    bool getJSON(JsonDocument &doc);

   private:
    void connectToHeartRateMonitor();
    bool _deviceFound = false;
    BLEScan *_pBLEScan;
    BLEClient *_pClient;
    uint8_t _heartrate;
};

#endif  // HRM_H