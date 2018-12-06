#include <stdio.h>
#include <stdlib.h>

int * append(int * arr, int append_num, int * len)
{
	int *tmp_arr, *delete_arr;
	tmp_arr = (int *)malloc(sizeof(int)*(*len + 1));

	for (int i = 0; i < *len; i++)	tmp_arr[i] = arr[i];
	tmp_arr[*len] = append_num;

	*len += 1;

	delete_arr = arr;
	free(arr);

	return tmp_arr;
}

int main(void)
{
	int arr_len1 = 3;
	int * arr1;
	arr1 = (int *)malloc(sizeof(int) * arr_len1);
	for (int i = 0; i < arr_len1; i++)		arr1[i] = i + 1;
	// arr1[3] = { 1,2,3 }

	int arr_len2 = 7;
	int * arr2;
	arr2 = (int *)malloc(sizeof(int) * arr_len2);
	for (int i = 0; i < arr_len2; i++)		arr2[i] = 2 * i + 1;
	// arr2[7] = { 1,3,5,7,9,11,13 }

	printf("input to append num1 ");
	int append_num1 = 0;
	scanf_s("%d", &append_num1);

	printf("input to append num2 ");
	int append_num2 = 0;
	scanf_s("%d", &append_num2);

	arr1 = append(arr1, append_num1, &arr_len1);
	arr2 = append(arr2, append_num2, &arr_len2);

	printf("input to append num1 ");
	scanf_s("%d", &append_num1);
	arr1 = append(arr1, append_num1, &arr_len1);

	for (int i = 0; i < arr_len1; i++)	printf("%d ", arr1[i]);
	printf("\n");
	for (int i = 0; i < arr_len2; i++)	printf("%d ", arr2[i]);

	free(arr1);
	free(arr2);


	return 0;
}