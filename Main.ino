#include <Arduino.h>
#include "MotorController.h"
#include "BluetoothController.h"

#define DEVICE "HoverBike"
#define HALL_SENSOR_PIN 12
#define MOTOR_CONTROL_PIN 33

MotorController Motor;
BluetoothController BT;

void setup()
{
	Serial.begin(9600);
	BT.start(DEVICE);
	Motor.start(MOTOR_CONTROL_PIN);
}

void loop()
{
	char * data = BT.receiveData();

	if (data[0] != NULL) {
		float percent = atof(data);
		if (percent < 0.8) {
			Motor.setPercentSpeed(percent);
		}
	}
}