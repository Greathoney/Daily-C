#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}


int main(void)
{
	int (*function)(int, int) = NULL;

	int pick = 0;
	printf("더할 것이면 1을 입력하고 뺄 것이면 2를 입력하세요. : ");
	scanf("%d", &pick);

	int num1 = 0, num2 = 0, result = 0;
	printf("두 수를 입력하세요. : ");
	scanf("%d%d", &num1, &num2);

	if (pick == 1)
		function = add;

	else
		function = sub;

	if (pick == 1)
		printf("두 수의 합은 %d입니다.\n", function(num1, num2));
	else
		printf("두 수의 차는 %d입니다.\n", function(num1, num2));

	return 0;
}