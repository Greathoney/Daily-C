#include <stdio.h>
#include <stdlib.h>

int index(int * arr, int arr1_len, int index_num);

int main(void)
{
	int i;

	int * arr1, arr1_len = 5; // arr1[5] = { 1, 2, 3, 4, 5 }
	arr1 = (int *)malloc(sizeof(int)*arr1_len);
	for (i = 0; i < arr1_len; i++)		arr1[i] = i + 1;

	int input;
	printf("input to index arr1 : ");
	scanf_s("%d", &input);

	int answer;
	answer = index(arr1, arr1_len, input);

	printf("%d", answer);

	free(arr1);

	return 0;
}

int index(int * arr, int arr_len, int index_num)
{
	int i;


	for (i = 0; i < arr_len; i++)
	{
		if (arr[i] == index_num)
		{
			return i;
		}
	}
	return -1;

}