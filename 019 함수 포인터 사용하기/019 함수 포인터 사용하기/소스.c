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
	printf("���� ���̸� 1�� �Է��ϰ� �� ���̸� 2�� �Է��ϼ���. : ");
	scanf("%d", &pick);

	int num1 = 0, num2 = 0, result = 0;
	printf("�� ���� �Է��ϼ���. : ");
	scanf("%d%d", &num1, &num2);

	if (pick == 1)
		function = add;

	else
		function = sub;

	if (pick == 1)
		printf("�� ���� ���� %d�Դϴ�.\n", function(num1, num2));
	else
		printf("�� ���� ���� %d�Դϴ�.\n", function(num1, num2));

	return 0;
}