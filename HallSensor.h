#ifndef HallSensor_h
#define HallSensor_h

#include <Arduino.h>

class HallSensor {
    
    public:
        HallSensor(int INPUT_PIN); 
        int update();
        int getPin();
        float getRPMs();

    private:
        float prevRPM;
        float currentRPM;
        int inputPin;
        int prevTime;
        int currentTime;
        float motorSignal;
        float definedRPMs[ 2 ];
};

#endif
