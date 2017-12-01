#include <stdio.h>
#include "Altino.h"

int bpm = 115; int oct;
void s(char sy[3],int len);

void backsound()
{
	s("E .", 8); s("D#.", 8); s("E .", 8); s("D#.", 8); s("E .", 8); s("B", 8); s("D .", 8); s("C .", 8); s("A", 4); s("", 8);
	s("C", 8); s("E", 8); s("A", 8); s("B", 4); s("", 8); s("E", 8); s("G#", 8); s("B", 8); s("C .", 4); s("", 8); s("E", 8);
	s("E .", 8); s("D#.", 8); s("E .", 8); s("D#.", 8); s("E .", 8); s("B", 8); s("D .", 8); s("C .", 8); s("A", 4); s("", 8);
	s("C", 8); s("E", 8); s("A", 8); s("B", 4); s("", 8); s("E", 8); s("C .", 8); s("B", 8); s("A", 4); s("", 8);
	s("B", 8); s("C .", 8); s("D .", 8); s("E .", 4); s("", 8); s("G", 8); s("F .", 8); s("E .", 8); s("D .", 4); s("", 8);
	s("F", 8); s("E .", 8); s("D .", 8); s("C .", 4); s("", 8); s("E", 8); s("D .", 8); s("C .", 8); s("B", 4); s("", 8);
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
	delay(2400000/len/bpm);
}
