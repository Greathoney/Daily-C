#include <stdio.h>
#include <time.h>

int main(void)
{
	int i, j;

	int num;
	clock_t clock(void);
	int time[10][4] = { 0, };

	printf("++      +=1      ='+1\n");
	for (i = 0; i < 10; i++)
	{
		time[i][0] = clock();
		for (j = 0, num = 0; j < 2000000000; j++)
			num++;

		time[i][1] = clock();
		for (j = 0, num = 0; j < 2000000000; j++)
			num += 1;

		time[i][2] = clock();
		for (j = 0, num = 0; j < 2000000000; j++)
			num = num + 1;

		time[i][3] = clock();
		for (j = 0; j < 3; j++)
			printf("%d    ", time[i][j + 1] - time[i][j]);

		printf("\n");
	}

	printf("\nÆò±Õ\n");

	int sum;
	for (j = 0; j < 3; j++)
	{
		for (i = 0, sum = 0; i < 10; i++)
		{
			sum += time[i][j+1] - time[i][j];
		}
		printf("%d    ", sum / 10);
	}
	return 0;
}