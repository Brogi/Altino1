#include <stdio.h>
#include "Altino.h"

main()
{
	int bpm = 115;		// ���� �ӵ�.
	int ptr = 0;		// ��ü �Ǻ� ��, ���� ��Ȳ.
	int step = -1;		// ������ üĿ.
	int goal = -1;		// �� ���� ������.

	// if (���� ���� �ν� ��)
	//	{ptr+=1;

	if (ptr > 0)
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
				case 10: {Sound(0); ptr = 0; goal = -1;} break;				// END
				}
			}
		if (step == goal) { ptr += 1; goal = 0; }	// �����̿� �����ϸ�, �ʱ�ȭ.
		step += 1;								// ������ 1 �߰�;
		}

	//	}
}