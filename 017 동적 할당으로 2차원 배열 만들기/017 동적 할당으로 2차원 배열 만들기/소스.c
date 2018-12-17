#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j;

	int arr_height = 5, arr_width = 3;
	int **arr;
	arr = (int **)malloc(sizeof(int*) * arr_height);
	for (int i = 0; i < arr_height; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * arr_width);
	}

	for (i = 0; i < arr_height; i++)
	{
		for (j = 0; j < arr_width; j++)
		{
			arr[i][j] = i * 10 + j;
		}
	}

	for (i = 0; i < arr_height; i++)
	{
		for (j = 0; j < arr_width; j++)
		{
			printf("%d\n", arr[i][j]);
		}
	}

	for (i = 0; i < arr_height; i++)
	{
		free(arr[i]);
	}

	free(arr);

	return 0;
}