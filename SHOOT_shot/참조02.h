# include <stdio.h>
# include <stdlib.h>
# include <windows.h>

int main()
{
	const char bar = '=';
	const char blank = ' ';

	const int LEN = 20;
	const int MAX = 1000;
	const int SPEED = 40;

	int count = 0;
	int i;

	float tick = (float)100 / LEN;
	printf("0.2F%% 마다 bar 1개 출력 \n \n", tick);

	int bar_count;
	float percent;

	while (count <= MAX)
	{
		printf("\r%d%d[", count, MAX);
		percent = (float)count / MAX * 100;
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
		printf("] %0.2f%%", percent);
		count++;
		Sleep(SPEED);
	}
	printf(" done!\n\n");
	system("pause");

	return 0;
}