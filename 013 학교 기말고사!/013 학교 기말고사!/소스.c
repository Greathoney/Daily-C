#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j, k;
	int num1, num2;
	int pick_blank, pick_star;

	scanf("%d", &num1);
	if (num1 % 2 == 0)
	{
		printf("잘못 입력하였습니다.");
		return 0;
	}
	scanf("%d", &num2);

	for (i = 0; i < num1; i++)
	{
		if (i <= num1 / 2)
		{
			pick_blank = i;
			pick_star = num1 - 2 * i;
		}
		else
		{
			pick_blank = num1 - i - 1;
			pick_star = 2 * i - num1 + 2;
		}

		for (j = 0; j < num2; j++)
		{

			for (k = 0; k < pick_blank; k++)
			{
				printf(" ");
			}
			for (k = 0; k < pick_star; k++)
			{
				printf("*");
			}
			for (k = 0; k < pick_blank + 1; k++)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}