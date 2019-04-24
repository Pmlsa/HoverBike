#include <Arduino.h>
#include "HallSensor.h" 

#define OK 0
#define ERROR 1

HallSensor::HallSensor(int INPUT_PIN) {
    input_pin = INPUT_PIN;
    current_time = millis();

    pinMode(input_pin, INPUT_PULLUP);
}

int HallSensor::update() {
    float delta;
    int prev_time = current_time;

    current_time = millis();
    delta = (float)current_time - (float)prev_time;

    rpm = 60.0 / (delta / 1000.0);

    return OK;
}

float HallSensor::getRPM() {
    return rpm;
}

int HallSensor::getPin() {
    return input_pin;
}

int HallSensor::getState() {
    return state;
}