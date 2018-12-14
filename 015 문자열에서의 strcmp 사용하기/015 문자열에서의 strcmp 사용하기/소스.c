#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j;

	char *arr[4] = { "apple", "applemango", "pineapple", "pineapples" };

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", strcmp(arr[i], arr[j]));
		}
		printf("\n");
	}



	return 0;
}