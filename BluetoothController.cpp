#include <Arduino.h>
#include "BluetoothController.h" 
#include <BluetoothSerial.h>

#define OK 0
#define ERROR 1

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothController::BluetoothController() {}

void BluetoothController::start(char * device) {
    BLE.begin(device);
}

char * BluetoothController::receiveData() {
    memset(buffer, 0, sizeof(buffer));
    int i = 0;

    while (BLE.available()) {
        delay(10);

        char received = BLE.read();
        buffer[i] = received; 
        i++;
    }

    return buffer;
}

