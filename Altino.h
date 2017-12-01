
typedef struct SensorData1 {
	int IRSensor[6];
	int TorqueSensor[2];
	int TemperatureSensor;
	int CDSSensor;
	int GSensor[3];
	int MSensor[3];
	int GySensor[3];
	int SteeringVar;
	int SteeringTorque;
	int Battery;
}SensorData;

void Go(int left, int right);
void Steering(int steeringvalue);
void Steering2(int value1, int value2);
void Sound(unsigned char buzzer);
void Display(unsigned char ASCII);
void DisplayLine(unsigned char dot0, unsigned char dot1, unsigned char dot2, unsigned char dot3, unsigned char dot4, unsigned char dot5, unsigned char dot6, unsigned char dot7);
void Led(unsigned int led);
SensorData Sensor(int command);

