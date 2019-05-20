#ifndef MotorController_h
#define MotorController_h

#include <Arduino.h>

class MotorController {
    
    public:
        MotorController();

        void start(int OUTPUT_PIN);
        int setPercentSpeed(float percent);

    private:
        int setDutyCycle(int dutyCycle);
        
};

#endif