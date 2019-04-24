#include "HallSensor.h"

HallSensor sensor = HallSensor(25);

void IRAM_ATTR ISR() {
    Serial.println("FJDHSFLDJSFKJDSLFJDSLFJSDLKFJSLFJSDKFDSKFL");
}

void setup() {
    Serial.begin(9600);
    attachInterrupt(sensor.getPin(), ISR, FALLING);
}

void loop() {
    Serial.println(sensor.getRPM());
}