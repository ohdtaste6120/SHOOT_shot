# define _CRT_SECURE_NO_WARNINGS

# include <stdio.h>
# include <stdlib.h>
# include <windows.h>

void coffeePic()
{
	printf("      *         \n"); // 6
	printf("      |         \n");
	printf("      |         \n\n");
	printf("   ����       \n");
	printf("  ��    ��--    \n");
	printf("  |����|  |   \n");
	printf("  |      |--    \n");
	printf("   ------       \n\n");
}

int main()
{
	system("mode con cols=40 lines=25");

	printf("[SHOOT shot]\n");

	coffeePic();

	int comnum; // ���� ���� : �� ���ڿ� ����� ��
	srand(time(0)); // ���α׷� ���ึ�� �ٸ� ���� ���
	comnum = rand() % 30;
	printf("sŰ�� ���� '%d'�ʿ� ���� ���� ��������\n", comnum);

	// ������
	const char bar = '='; 
	const char blank = ' ';

	const int LEN = 20;
	const int MAX = 1000;
	const int SPEED = 60;

	int i;
	float score; // 0.n�ʱ��� ����� �� -> �ʹ� ������ int�� ��ȯ�ص� ��
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
		percent = (float)count / MAX * 100; // ��
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
		printf("] %0.2f%��", percent);
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