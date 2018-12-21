#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;

	int *arr1;
	arr1 = (int *)malloc(sizeof(int) * 4);
	for (i = 0; i < 4; i++)
		arr1[i] = i + 1;

	for (i = 0; i < 4; i++)
		printf("%d ", arr1[i]);
	printf("\n");

	realloc(arr1, sizeof(int) * 10);

	for (i = 4; i < 10; i++)
		arr1[i] = 100 - i;
	
	for (i = 0; i < 10; i++)
		printf("%d ", arr1[i]);
	
	free(arr1);
	return 0;
}