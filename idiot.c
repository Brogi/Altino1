#include "Altino.h"
#include <math.h>
#include <gl/glut.h>
#include <windows.h>

#define Max 80
#define Min 20
#define Crush 150
#define Speed 400
#define angle 2

double point[5000][2] = { 0 };
int i = 0, a = 90, cnt = 1;

int bpm = 115; int oct;
void s(char sy[3], int len);

int stop(int n)
{
	if (n <= 150)
	{
		return 1;
	}
	else return 0;
}

void display()
{
	int j;

	glPointSize(5.0f);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0, 0);
	for (j = 0; j < i; j++)
	{
		glVertex2f(point[j][0]/100, point[j][1]/100);
	}

	glEnd();
	glFlush();
}
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
	{
	case 'C': {mel = 1; } break;
	case 'D': {mel = 3; } break;
	case 'E': {mel = 5; } break;
	case 'F': {mel = 6; } break;
	case 'G': {mel = 8; } break;
	case 'A': {mel = 10; } break;
	case 'B': {mel = 12; } break;
	}

	switch (sy[1])
	{
	case '#': {mel += 1; } break;
	case 'b': {mel -= 1; } break;
	}

	switch (sy[2])
	{
	case '.': {oct = 5; } break;
	default: {oct = 4; } break;
	}
	mel += (oct - 1) * 12;

	Sound(mel);
	delay(120000 / len / bpm);
}

void print_IR_value(int ir)
{
	printf("%d ", ir);
}

void retreat() {
	Steering(1);
	//a += angle;
	Go(-Speed - 100, -Speed - 100);
	delay(200);
	//point[i][0] = point[i - 1][0] - cos(a*3.14 / 180)/100;
	//point[i][1] = point[i - 1][0] - sin(a*3.14 / 180)/100;
	//i++;
	//backsound();
	Steering(2);
	Go(Speed, Speed);
}

void wonidea()
{
	SensorData sens;
	int ir0, ir1, ir2, ir3, ir4, ir5, jodo;

	while (1)
	{
		sens = Sensor(10);
		ir0 = sens.IRSensor[0];
		ir1 = sens.IRSensor[1];
		ir2 = sens.IRSensor[2];
		ir3 = sens.IRSensor[3];
		ir4 = sens.IRSensor[4];
		ir5 = sens.IRSensor[5];
		jodo = sens.CDSSensor;

		print_IR_value(ir0);
		print_IR_value(ir1);
		print_IR_value(ir2);
		print_IR_value(ir3);
		print_IR_value(ir4);
		print_IR_value(ir5);
		printf("\n");

		if (stop(jodo) == 1)
		{
			break;
		}

		if (ir1 < 10) // 5
		{
			if (ir0 > 10) // ¿ø·¡´Â 5
			{
				Steering(2);
			}
			else
			{
				Steering(1);
				a += angle;
			}
		}
		else if (ir0 > 0 && ir1 >= 10) // 5
		{
			Steering(3);
			a -= angle;
			if (ir0 > 250 || ir1 > 250)
			{
				retreat();
				continue;
			}
		}
		if (i == 0)
		{
			point[i][0] = cos(a*3.14 / 180);
			point[i][1] = sin(a*3.14 / 180);
		}
		else
		{
			point[i][0] = point[i - 1][0] + cos(a*3.14 / 180);
			point[i][1] = point[i - 1][1] + sin(a*3.14 / 180);
		}

		printf("***%lf***\n",a*3.14 / 180);
			i++;
	}

}

int main()
{
	Open(szPort);

	Go(Speed, Speed);
	wonidea();
	Go(0, 0);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("opengl project");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
