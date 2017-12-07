#include <stdio.h>
#include "Altino.h"

main()
{
	int bpm = 115;		// 음악 속도.
	int ptr = 0;		// 전체 악보 중, 진행 상황.
	int step = -1;		// 딜레이 체커.
	int goal = -1;		// 한 음의 딜레이.

	// if (후진 범위 인식 시)
	//	{ptr+=1;

	if (ptr > 0)
		{if (step == 0)
			{switch (ptr)
				{case 1: {Sound(53); goal = 120000 / 8 / 115;} break;		// 미
				case 2: {Sound(52); goal = 120000 / 8 / 115;} break;		// 레#
				case 3: {Sound(53); goal = 120000 / 8 / 115;} break;		// 미
				case 4: {Sound(52); goal = 120000 / 8 / 115;} break;		// 레#
				case 5: {Sound(53); goal = 120000 / 8 / 115;} break;		// 미
				case 6: {Sound(48); goal = 120000 / 8 / 115;} break;		// 시
				case 7: {Sound(51); goal = 120000 / 8 / 115;} break;		// 레
				case 8: {Sound(49); goal = 120000 / 8 / 115;} break;		// 도
				case 9: {Sound(46); goal = 120000 / 4 / 115;} break;		// 라
				case 10: {Sound(0); ptr = 0; goal = -1;} break;			// END
				}
			}
		if (step == goal) { ptr += 1; goal = 0; }	// 딜레이에 도달하면, 초기화.
		step += 1;					// 딜레이 1 추가;
		}

	//	}
}
