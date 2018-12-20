#include <stdio.h>
#include <stdlib.h>

int Double(int num)
{
	return num + num;
}

int Square(int num)
{
	return num * num;
}

int * map(int(*function)(int), int *arr, int len_arr)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		arr[i] = function(arr[i]);
	}

	return arr;
}



int main(void)
{
	int i;

	int *arr1, len_arr1 = 4;
	arr1 = (int *)malloc(sizeof(int) * len_arr1);
	for (i = 0; i < 4; i++)
		arr1[i] = 2 + 2 * i;

	arr1 = map(Double, arr1, len_arr1);

	for (i = 0; i < 4; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n\n");

	int *arr2, len_arr2 = 4;
	arr2 = (int *)malloc(sizeof(int) * len_arr2);
	for (i = 0; i < 4; i++)
		arr2[i] = 2 + 2 * i;

	arr2 = map(Square, arr2, len_arr2);

	for (i = 0; i < 4; i++)
	{
		printf("%d ", arr2[i]);
	}


	return 0;
}