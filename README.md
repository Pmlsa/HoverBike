# HoverBike
Firmware for ESP32 E-bike controller

## HallSensor.h
Usage for the HallSensor library: 
```c++
#include "HallSensor.h"

HallSensor sensor = HallSensor(15); // Pin 15

void callback() {
  sensor.update();
}

void setup() {
  attachInterrupt(sensor.getPin(), callback, FALLING);
  sensor.getRPM();
}
```
