#include <stdio.h>
#include "Altino.h"

main()
{
	int bpm = 115;
	int ptr = 0;
	int step = -1;
	int goal = -1;

	if (ptr == 0) {ptr += 1;}
	if (ptr>0)
		{if (step == 0)
			{switch (ptr)
				{case 1: {Sound(53); goal = 120000 / 8 / 115;} break;		// ��
				case 2: {Sound(52); goal = 120000 / 8 / 115;} break;		// ��#
				case 3: {Sound(53); goal = 120000 / 8 / 115;} break;		// ��
				case 4: {Sound(52); goal = 120000 / 8 / 115;} break;		// ��#
				case 5: {Sound(53); goal = 120000 / 8 / 115;} break;		// ��
				case 6: {Sound(48); goal = 120000 / 8 / 115;} break;		// ��
				case 7: {Sound(51); goal = 120000 / 8 / 115;} break;		// ��
				case 8: {Sound(49); goal = 120000 / 8 / 115;} break;		// ��
				case 9: {Sound(46); goal = 120000 / 4 / 115;} break;		// ��
				case 10: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 11: {Sound(37); goal = 120000 / 8 / 115;} break;		// ��
				case 12: {Sound(41); goal = 120000 / 8 / 115;} break;		// ��
				case 13: {Sound(46); goal = 120000 / 8 / 115;} break;		// ��
				case 14: {Sound(48); goal = 120000 / 4 / 115;} break;		// ��
				case 15: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 16: {Sound(41); goal = 120000 / 8 / 115;} break;		// ��
				case 17: {Sound(45); goal = 120000 / 8 / 115;} break;		// ��#
				case 18: {Sound(48); goal = 120000 / 8 / 115;} break;		// ��
				case 19: {Sound(49); goal = 120000 / 4 / 115;} break;		// ��
				case 20: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 21: {Sound(53); goal = 120000 / 8 / 115;} break;		// ��
				case 22: {Sound(52); goal = 120000 / 8 / 115;} break;		// ��#
				case 23: {Sound(53); goal = 120000 / 8 / 115;} break;		// ��
				case 24: {Sound(52); goal = 120000 / 8 / 115;} break;		// ��#
				case 25: {Sound(53); goal = 120000 / 8 / 115;} break;		// ��
				case 26: {Sound(48); goal = 120000 / 8 / 115;} break;		// ��
				case 27: {Sound(51); goal = 120000 / 8 / 115;} break;		// ��
				case 28: {Sound(49); goal = 120000 / 8 / 115;} break;		// ��
				case 29: {Sound(46); goal = 120000 / 4 / 115;} break;		// ��
				case 30: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 31: {Sound(37); goal = 120000 / 8 / 115;} break;		// ��
				case 32: {Sound(41); goal = 120000 / 8 / 115;} break;		// ��
				case 33: {Sound(46); goal = 120000 / 8 / 115;} break;		// ��
				case 34: {Sound(48); goal = 120000 / 4 / 115;} break;		// ��
				case 35: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 36: {Sound(41); goal = 120000 / 8 / 115;} break;		// ��
				case 37: {Sound(49); goal = 120000 / 8 / 115;} break;		// ��
				case 38: {Sound(48); goal = 120000 / 8 / 115;} break;		// ��
				case 39: {Sound(46); goal = 120000 / 4 / 115;} break;		// ��
				case 40: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 41: {Sound(48); goal = 120000 / 8 / 115;} break;		// ��
				case 42: {Sound(49); goal = 120000 / 8 / 115;} break;		// ��
				case 43: {Sound(51); goal = 120000 / 8 / 115;} break;		// ��
				case 44: {Sound(53); goal = 120000 / 4 / 115;} break;		// ��
				case 45: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 46: {Sound(44); goal = 120000 / 8 / 115;} break;		// ��
				case 47: {Sound(54); goal = 120000 / 8 / 115;} break;		// ��
				case 48: {Sound(53); goal = 120000 / 8 / 115;} break;		// ��
				case 49: {Sound(51); goal = 120000 / 4 / 115;} break;		// ��
				case 50: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 61: {Sound(42); goal = 120000 / 8 / 115;} break;		// ��
				case 62: {Sound(53); goal = 120000 / 8 / 115;} break;		// ��
				case 63: {Sound(51); goal = 120000 / 8 / 115;} break;		// ��
				case 64: {Sound(49); goal = 120000 / 4 / 115;} break;		// ��
				case 65: {Sound(0); goal = 120000 / 8 / 115;} break;
				case 66: {Sound(41); goal = 120000 / 8 / 115;} break;		// ��
				case 67: {Sound(51); goal = 120000 / 8 / 115;} break;		// ��
				case 68: {Sound(49); goal = 120000 / 8 / 115;} break;		// ��
				case 69: {Sound(48); goal = 120000 / 4 / 115;} break;		// ��
				case 70: {Sound(0); goal = 120000 / 8 / 115;} break;
				default: {ptr = 0; goal = 0;} break;
				}
		}
		if (step == goal) { ptr += 1; goal = 0; }	// �����̿� �����ϸ�, �ʱ�ȭ.
		step += 1;								// ������ 1 �߰�;
	}