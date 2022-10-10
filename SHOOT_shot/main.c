# define _CRT_SECURE_NO_WARNINGS

# include <stdio.h>
# include <stdlib.h>
# include <windows.h>

void coffeePic()
{
	printf("      *         \n"); // 6
	printf("      |         \n");
	printf("      |         \n\n");
	printf("   ■■■       \n");
	printf("  ★    ★--    \n");
	printf("  |■■■|  |   \n");
	printf("  |      |--    \n");
	printf("   ------       \n\n");
}

int main()
{
	system("mode con cols=40 lines=25");

	printf("[SHOOT shot]\n");

	coffeePic();

	int comnum; // 랜덤 숫자 : 이 숫자에 맞춰야 함
	srand(time(0)); // 프로그램 실행마다 다른 난수 출력
	comnum = rand() % 30;
	printf("s키를 눌러 '%d'초에 맞춰 샷을 내리세요\n", comnum);

	// 게이지
	const char bar = '='; 
	const char blank = ' ';

	const int LEN = 20;
	const int MAX = 1000;
	const int SPEED = 60;

	int i;
	float score; // 0.n초까지 맞춰야 함 -> 너무 어려우면 int로 전환해도 됨
	int count = 0;

	float tick = (float)100 / LEN;

	int bar_count;
	float percent;

	while (count <= MAX)
	{
		if (_kbhit())
		{
			if (getch() == 's')
				break;
		}

		printf("\r[");
		percent = (float)count / MAX * 100; // 초
		bar_count = percent / tick;
		for (i = 0; i < LEN; i++)
		{
			if (bar_count > i)
			{
				printf("%c", bar);
			}
			else
			{
				printf("%c", blank);
			}
		}
		printf("] %0.2f%초", percent);
		score=percent;
		count++;
		Sleep(SPEED);
	}
	if (score == comnum)
	{
		printf("\n#_WIN!");
	}
	else
	{
		printf("\n#_LOSE!");
	}
	return 0;

}