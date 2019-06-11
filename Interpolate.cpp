#include <math.h>
#include <Arduino.h>
#include "HallSensor.h" 

#define OK 0
#define ERROR 1

HallSensor sensor = HallSensor(25);

float Interpolate::signalMotor (float definedRPMs) {
    float targetRPM = definedRPMs[0], prevRPM = definedRPMs[0];
    float rateOfChange = (speedFunction(TargetRPM) - speedFunction(currentRPM))/(TargetRPM - currentRPM);

    if hasInterpolationStarted() == false {
        setStepper(GetInterpolation, definedRPMS);
        setIterator(5);
        setStartInterpolation(true);
    }

    MotorController.write(speedFunction(currentRPM+((5-Iterator)*stepper*rateOfChange));
    setIterator(getIterator() - 1);

    if getIteration() == 0 {
        setStartInterpolation(false);
    }

}

float Interpolate::speedFunction(float inputSpeed) {
    float outputPercent = 450/(4.34+ 50*(e**(-0.0087*(inputSpeed+113.074))));
    return outputPercent;
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
