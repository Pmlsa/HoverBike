#ifndef BluetoothController_h
#define BluetoothController_h

#include <Arduino.h>
#include <BluetoothSerial.h>

class BluetoothController {
    
    public:
        BluetoothController();

        void start(char * device);
        char * receiveData();

    private:
        BluetoothSerial BLE;
        char buffer[512] = {NULL};
};

#endif