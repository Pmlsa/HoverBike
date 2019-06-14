#include <Arduino.h>
#include "Interpolate.h"
#include "BluetoothController.h"
#include "HallSensor.h"

#define DEVICE "HoverBike"
#define HALL_SENSOR_PIN 12
#define MOTOR_CONTROL_PIN 33

Interpolate IN;
BluetoothController BT;
HS = HallSensor(HALL_SENSOR_PIN);

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
		if (data[0] == '1') { // 0 is for "Off Motor", 1 is for "On Motor"
			IN.signalMotor(HS.getRPMS());
		}
	}
}
