#include "Altino.h"

#define Max 80
#define Min 20
#define Crush 150
#define Speed 600

int bpm = 115; int oct;
void s(char sy[3],int len);

void backsound()
{
	s("E .", 8); s("D#.", 8); s("E .", 8); s("D#.", 8); s("E .", 8); s("B", 8); s("D .", 8); s("C .", 8); s("A", 4); s("", 8);
	/*s("C", 8); s("E", 8); s("A", 8); s("B", 4); s("", 8); s("E", 8); s("G#", 8); s("B", 8); s("C .", 4); s("", 8); s("E", 8);
	s("E .", 8); s("D#.", 8); s("E .", 8); s("D#.", 8); s("E .", 8); s("B", 8); s("D .", 8); s("C .", 8); s("A", 4); s("", 8);
	s("C", 8); s("E", 8); s("A", 8); s("B", 4); s("", 8); s("E", 8); s("C .", 8); s("B", 8); s("A", 4); s("", 8);
	s("B", 8); s("C .", 8); s("D .", 8); s("E .", 4); s("", 8); s("G", 8); s("F .", 8); s("E .", 8); s("D .", 4); s("", 8);
	s("F", 8); s("E .", 8); s("D .", 8); s("C .", 4); s("", 8); s("E", 8); s("D .", 8); s("C .", 8); s("B", 4); s("", 8);*/
    Sound(0);
}

void s(char sy[3], int len)
{
	int mel = 0;
	switch (sy[0])
		{case 'C': {mel = 1;} break;
		case 'D': {mel = 3;} break;
		case 'E': {mel = 5;} break;
		case 'F': {mel = 6;} break;
		case 'G': {mel = 8;} break;
		case 'A': {mel = 10;} break;
		case 'B': {mel = 12;} break;
		}

	switch (sy[1])
		{case '#': {mel += 1;} break;
		case 'b': {mel -= 1;} break;
		}

	switch(sy[2])
		{case '.': {oct = 5;} break;
		default: {oct = 4;} break;
		}
	mel += (oct - 1) * 12;

	Sound(mel);
	delay(120000/len/bpm);
}

void print_IR_value(int ir)
{
    printf("%d ", ir);
}

void retreat() {
    Steering(2);
	Go(-Speed, -Speed);
	delay(500);
	Steering(3);
	//backsound();
	Go(Speed, Speed);
	delay(500);
}

void dongidea()
{
    SensorData sens;
    int ir0, ir1, ir2, ir3, ir4, ir5;

     while(1)
    {
        sens = Sensor(10);
        ir0 = sens.IRSensor[0];
        ir1 = sens.IRSensor[1];
        ir2 = sens.IRSensor[2];
        ir3 = sens.IRSensor[3];
        ir4 = sens.IRSensor[4];
        ir5 = sens.IRSensor[5];
        print_IR_value(ir0);
        print_IR_value(ir4);
        printf("\n");

        if (ir1 >= Crush)
        {
            retreat();
        }
        else
        {
            if(ir0 >= Crush)
            {
                retreat();
            }
            else if(ir0 > Min)
            {
                if (ir4 > Max) Steering(3);
                else if (ir4 > Min) Steering(2);
                else Steering(1);
            }
            else
            {
                if (ir4 > Min) Steering(2);
                else Steering(1);
            }
        }

    }
}

int main()
{
    Open(szPort);

    Go(Speed,Speed);
    dongidea();

    return 0;
}
