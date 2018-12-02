#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int len;

	printf("배열의 길이를 입력하세요. ");
	scanf_s("%d", &len);

	int *arrptr;
	arrptr = malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)
	{
		arrptr[i] = i;
	}

	for (int i = 0; i < len; i++)
	{
		printf("%p ", &arrptr[i]);
		printf("%d\n", arrptr[i]);
	}
}
