#include "Altino.h"

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
    printf("%d\n", ir);
}

void retreat() {
	Steering(1);
	Go(-400, -400);
	backsound();
	Steering(2);
	Go(400, 400);
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
        print_IR_value(ir1);

        if (ir1 >= 500)
        {
            retreat();
        }
        else
        {
            if (ir4 > 80)
        {
            Steering(3);
        }
        else if (ir4 <= 80 && ir4 > 10)
        {
            if (ir0 > 100)
            {
                Steering(3);
            }
            else if (ir2 > 100);
            {
                Steering(1);
            }
            Steering(2);
        }

        else
        {
            Steering(1);
        }
        }

    }
}

int main()
{
    Open(szPort);

    Go(400,400);
    dongidea();

    return 0;
}
