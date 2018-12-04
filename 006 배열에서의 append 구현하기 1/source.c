#include <stdio.h>
#include <stdlib.h>

int append(int *arr, int arr_len, int num);

int main(void)
{
	//arr1[3] = { 1, 2, 3 }
	int *arr1;
	int arr_len1 = 3;
	arr1 = (int *)malloc(sizeof(int) * arr_len1);

	for (int i = 0; i < arr_len1; i++)		arr1[i] = i + 1; 

	//arr1에 새로 넣을 수를 입력받기
	int num;
	printf("input to append ");
	scanf_s("%d", &num);
	arr_len1 = append(arr1, arr_len1, num);

	//새로 넣은 수 출력하기
	for (int i = 0; i < arr_len1; i++)	printf("%d\n", arr1[i]);
	free(arr1);
	return 0;
}

int append(int *arr, int arr_len, int num)
{
	int *arr_tmp;
	arr_tmp = arr;
	arr = (int *)malloc(sizeof(int));
	arr = arr_tmp;
	arr[arr_len] = num;
	arr_len += 1;
	return arr_len;
}
