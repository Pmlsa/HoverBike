#ifndef HallSensor_h
#define HallSensor_h

#include <Arduino.h>

class HallSensor {
    
    public:
        HallSensor(int INPUT_PIN);

        int update();
        int getPin();
        int getState();
        float getRPM();
        void attachCallback(void (*callback_function)());

    private:
        float rpm;
        int state;
        int input_pin;
        int current_time;
        float motorSignal;
};

#endif
