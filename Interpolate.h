#ifndef Interpolate_h
#define Interpolate_h
#include <Arduino.h>

class Interpolate {
    
    public:
    
        void signalMotor(float RPMList);
        float speedFunction(float inputSpeed);
    
        float getStepper();
        void setStepper(float definedRPMs);
    
        bool hasInterpolationStarted();
        void setStartInterpolation(bool inputBool);
    
        void setIterator(int inputInt);
        int getIteration();

    private:

        float outputPercent;
        int stepper;
        bool startInterpolation;
        int Iteration;
};

#endif
