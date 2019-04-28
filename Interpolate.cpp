#include <math.h>
#include <Arduino.h>
#include "HallSensor.h" 

#define OK 0
#define ERROR 1

HallSensor sensor = HallSensor(25);

float Interpolate::GetInterpolation (float definedRPMs) {
    if sensor.getInterpolateState() == 1 {
        
    }
}

int checkSpeedDifference () {
    float currentRPM, prevRPM = sensor.getRPMs()
    if abs(currentRPM - prevRPM) > 20 {
        sensor.setInterpolateState(1)
    }
    else {
        sensor.setInterpolateState(0)
    }
    return adjustSpeed
}