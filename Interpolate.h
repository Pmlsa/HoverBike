#ifndef Interpolate_h
#define Interpolate_h
#include <Arduino.h>

class Interpolate {
    
    public:
    
        void GetInterpolation(float RPM);
        int checkSpeedDifference(float RPM);

    private:

        float outputSpeed;
        int speedBool;
};

#endif