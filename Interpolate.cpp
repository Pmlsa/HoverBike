#include <math.h>
#include <Arduino.h>
#include "HallSensor.h" 

#define OK 0
#define ERROR 1

HallSensor sensor = HallSensor(25);

float Interpolate::GetInterpolation (float definedRPMs) {
    float targetRPM = definedRPMs[0], prevRPM = definedRPMs[0];
    float rateOfChange = (speedFunction(TargetRPM) - speedFunction(currentRPM))/(TargetRPM - currentRPM);
    return rateOfChange;
}

float Interpolate::signalMotor (float definedRPMs) {
    float targetRPM = definedRPMs[0], prevRPM = definedRPMs[0];

    if hasInterpolationStarted() == false {
        setStepper(GetInterpolation, definedRPMS);
        setIterator(5);
        setStartInterpolation(true);
    }

    MotorController.write(speedFunction+((5-Iterator)*stepper*GetInterpolation(definedRPMs));
    setIterator(getIterator() - 1);

    if getIteration() == 0 {
        setStartInterpolation(false);
    }

}

float Interpolate::speedFunction( float inputSpeed) {
    float outputVoltage = 10 * tanh( inputSpeed ) + 10;
    return outputVoltage;
}

int Interpolate::getStepper() {
    return stepper;
}

void Interpolate::setStepper(float rateOfChange, float definedRPMs) {
    float RPMDifference = float(definedRPMs[0]) - float(definedRPMs[0]);
    float stepper = RPMDifference*rateOfChange/5;
    return stepper;
}

bool Interpolate::hasInterpolationStarted() {
    return startInterpolation;
}
void Interpolate::setStartInterpolation(bool inputBool) {
    startInterpolation = inputBool;
}

int Interpolate::getIteration() {
    return Iteration;
}
void Interpolate::setIterator(int inputInt) {
    Iteration = inputInt;
}
