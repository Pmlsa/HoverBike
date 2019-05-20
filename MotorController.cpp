#include <Arduino.h>
#include "MotorController.h" 

#define OK 0
#define ERROR 1

const int freq = 5000;
const int channel = 0;
const int resolution = 8;

MotorController::MotorController() {}

void MotorController::start(int OUTPUT_PIN) {
    ledcSetup(channel, freq, resolution);
	ledcAttachPin(OUTPUT_PIN, channel);
}

int MotorController::setPercentSpeed(float percent) {
    percent += (1.23 / 3.3);
    int dutyCycle = (int)(percent * 255);
    
    setDutyCycle(dutyCycle);

    return OK;
}

int MotorController::setDutyCycle(int dutyCycle) {
    ledcWrite(channel, dutyCycle);

    return OK;
}

