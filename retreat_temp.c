#include "Altino.h"

void retreat() {
	Steering(1);
	Go(-400, -400);
	delay(1500);
	Steering(2);
	Go(400, 400);
}

int main() {

	SensorData sens;
	int IR0, IR1, IR2, IR3, IR4, IR5;
	sens = Sensor(10);
	IR0 = sens.IRSensor[0];
	IR1 = sens.IRSensor[1];
	IR2 = sens.IRSensor[2];
	IR3 = sens.IRSensor[3];
	IR4 = sens.IRSensor[4];
	IR5 = sens.IRSensor[5];

	Open(szPort);

	if (IR1 >= 600) {
		retreat();
	}

	Close();


	return 0;
}