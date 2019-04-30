#include <Arduino.h>
#include "HallSensor.h" 

#define OK 0
#define ERROR 1

HallSensor::HallSensor(int INPUT_PIN) {
    inputPin = INPUT_PIN;
    currentTime = millis();

    pinMode(inputPin, INPUT_PULLUP);
}

int HallSensor::update() {
    float delta;

    prevTime = currentTime;
    prevRPM = currentRPM;
    currentTime = millis();

    delta = (float)currentTime - (float)prevTime;

    currentRPM = 60000.0 / delta ;

    return OK;
}

float HallSensor::getRPMs() {
    float definedRPMs[2] = {currentRPM, prevRPM}
    return definedRPMs;
}

int HallSensor::getPin() {
    return inputPin;
}
