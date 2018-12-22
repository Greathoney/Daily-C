#include <stdio.h>
#include <stdlib.h>

int * append(int * arr, int append_num, int * len)
{
	*len += 1;

	realloc(arr, sizeof(int) * (*len));
	arr[*len - 1] = append_num;

	return arr;
}

int main(void)
{
	int i;

	int arr_len1 = 3, append_num1;
	int * arr1;
	arr1 = (int *)malloc(sizeof(int) * arr_len1);
	for (int i = 0; i < arr_len1; i++)
		arr1[i] = i + 1;
	// arr1[3] = { 1,2,3 }

	printf("input to append num1 ");
	scanf_s("%d", &append_num1);

	arr1 = append(arr1, append_num1, &arr_len1);

	for (i = 0; i < arr_len1; i++)
		printf("%d ", arr1[i]);

	free(arr1);


	return 0;
}