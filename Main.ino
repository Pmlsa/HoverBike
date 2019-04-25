#include "HallSensor.h"
#include "Interpolate.h"

HallSensor sensor = HallSensor(25);

int adjustSpeed = 0;
    
float PreviousRPM = 0.0;
float CurrentRPM = 0.0;

void IRAM_ATTR ISR() {
    sensor.update();
}

void setup() {
    Serial.begin(9600);
    attachInterrupt(sensor.getPin(), ISR, FALLING);
}

void loop() {
    Interpolate.signalMotor( sensor.defineRPMs() ); // Doing this to help bind to interpolation
}
