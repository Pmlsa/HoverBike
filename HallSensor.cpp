/*#include <Arduino.h>
#include "HallSensor.h" 
#include <math.h>

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

void HallSensor::defineRPMs() {
    
    float ThirdRPM = PreviousRPM;
    float PreviousRPM = CurrentRPM;
    float CurrentRPM = sensor.getRPM();
    
    float definedRPMs[ 3 ];
        
    definedRPMs[0] = ThirdRPM;
    definedRPMs[1] = PreviousRPM;
    definedRPMs[2] = CurrentRPM;
        
    if abs(CurrentRPM - PreviousRPM) > 20 {
        int adjustSpeed = 1;
    }
    
    return definedRPMs
}*/

#include <Arduino.h>
#include "HallSensor.h" 
#include <math.h>

#define OK 0
#define ERROR 1

HallSensor::HallSensor(int INPUT_PIN) {
    inputPin = INPUT_PIN;
    currentTime = millis();

    pinMode(inputPin, INPUT_PULLUP);
}

int HallSensor::update() {
    float delta;

    if prevTime != 0 {
        delta = (float)current_time - (float)prev_time;
        prevPRM = 60.0 / (delta / 1000.0);
    }
    prevTime = currentTime;

    current_time = millis();
    delta = (float)current_time - (float)prev_time;

    currentPRM = 60.0 / (delta / 1000.0);

    return OK;
}

float HallSensor::getRPMs() {
    return currentRPM, prevRPM;
}

int HallSensor::getPin() {
    return input_pin;
}

int HallSensor::setInterpolateState( int interpolateArgument) {
    interpolateState = interpolateArgument
}

int HallSensor::getInterpolateState() {
    return interpolateState
}
