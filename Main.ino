#include "HallSensor.h"
#include "Interpolate.h"

HallSensor sensor = HallSensor(25);

float PreviousRPM = 0.0
float CurrentRPM = 0.0


void IRAM_ATTR ISR() {
    sensor.update();
}

void setup() {
    Serial.begin(9600);
    attachInterrupt(sensor.getPin(), ISR, FALLING);
}

void loop() {
    ThirdRPM = PreviousRPM;
    PreviousRPM = CurrentRPM;
    CurrentRPM = sensor.getRPM();
    interpolate.signalMotor( ThirdRPM, PreviousRPM, CurrentRPM ); // Doing this to help bind to interpolation
}
