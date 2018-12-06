#include <stdio.h>
#include <stdlib.h>

int * insert(int * arr, int insert_num, int insert_num_index, int * len);
int * append(int * arr, int append_num, int * len);

int main(void)
{
	int i;

	int insert_num1, insert_num1_index, append_num1;

	// arr1[3] = { 1,2,3 }
	int arr_len1 = 3;
	int * arr1;
	arr1 = (int *)malloc(sizeof(int) * arr_len1);
	for (int i = 0; i < arr_len1; i++)		arr1[i] = i + 1;

	printf("Before inserting.\n");
	for (i = 0; i < arr_len1; i++)		printf("%d ", arr1[i]);

	//insert를 실행하는 부분입니다.
	printf("\ninput to insert number ");
	scanf_s("%d", &insert_num1);

	printf("input to insert number's index ");
	scanf_s("%d", &insert_num1_index);

	arr1 = insert(arr1, insert_num1, insert_num1_index, &arr_len1);


	printf("\nAfter inserting.\n");
	for (i = 0; i < arr_len1; i++)		printf("%d ", arr1[i]);


	//append를 실행하는 부분입니다.
	printf("\n\ninput to inset number ");
	scanf_s("%d", &append_num1);

	arr1 = append(arr1, append_num1, &arr_len1);
	printf("After appending.\n");
	for (i = 0; i < arr_len1; i++)		printf("%d ", arr1[i]);

	free(arr1);

	return 0;
}

int * append(int * arr, int append_num, int * len)
{
	int *tmp_arr;
	tmp_arr = (int *)malloc(sizeof(int)*(*len + 1));

	for (int i = 0; i < *len; i++)	tmp_arr[i] = arr[i];
	tmp_arr[*len] = append_num;

	*len += 1;

	free(arr);

	return tmp_arr;
}

int * insert(int * arr, int insert_num, int insert_num_index, int * len)
{
	int i;

	int *tmp_arr;
	tmp_arr = (int *)malloc(sizeof(int)*((*len)++ + 1));

	for (i = 0; i != insert_num_index; i++)		tmp_arr[i] = arr[i];

	tmp_arr[i++] = insert_num;

	for (; i < *len; i++)	tmp_arr[i] = arr[i - 1];

	free(arr);

	return tmp_arr;
}