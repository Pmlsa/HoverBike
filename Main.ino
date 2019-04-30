#include "HallSensor.h"
#include "Interpolate.h"

HallSensor sensor = HallSensor(25);

void IRAM_ATTR ISR() {
    sensor.update();
}

void setup() {
    Serial.begin(9600);
    attachInterrupt(sensor.getPin(), ISR, FALLING);
}

void loop() {
    Interpolate.signalMotor( sensor.getRPMs() ); // Doing this to help bind to interpolation
}
