# 2018.12.06 오늘을 챙겨요

오늘은 마지막으로 파이썬의 리스트에 사용되는 명렁어인 append를 C언어에서 구현해볼 것입니다.

어제까지만 해도 free문을 재대로 처리하지 않았는데, 새로운 방법이 떠올라서 이를 해결할 수 있을것 같습니다!!!



```C
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
```

실행결과

input to append num1 **6**
input to append num2 **5**
input to append num1 **4**
1 2 3 6 4
1 3 5 7 9 11 13 5



방법은 delete_arr를 만들어서 이제는 쓰지 않는 배열을 가리키게 한 뒤에, free(delete_arr)를 취하여 그 배열을 없애 메모리 누수를 방지하게 할 수 있습니다!!!



이로써 c언어의 append 사용에 대해서 알아보았습니다.