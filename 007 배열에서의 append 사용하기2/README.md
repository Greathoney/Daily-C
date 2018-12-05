# 2018.12.05 오늘을 챙겨요.

이전에 했던 source.c를 보니 글자가 다 깨져있더군요,,, 나중에 손을 봐야겠습니다.



어제 미쳐 하지 못했던 부분을 해 보겠습니다.

```C
#include <stdio.h>
#include <stdlib.h>

int * append(int * arr, int append_num, int * len)
{
	int *tmp_arr;
	tmp_arr = (int *)malloc(sizeof(int)*(*len + 1));

	for (int i = 0; i < *len; i++)	tmp_arr[i] = arr[i];
	tmp_arr[*len] = append_num;

	*len += 1;

	return tmp_arr;
}

int main(void)
{
	int append_num1 = 0, append_num2 = 0;
    
	int arr_len1 = 3;
	int * arr1;
	arr1 = (int *)malloc(sizeof(int) * arr_len1);
	for (int i = 0; i < arr_len1; i++)		arr1[i] = i + 1;
	// arr1[3] = { 1,2,3 }

	int arr_len2 = 7;
	int * arr2;
	arr2 = (int *)malloc(sizeof(int) * arr_len2);
	for (int i = 0; i < arr_len2; i++)		arr2[i] = 2*i + 1;
	// arr2[7] = { 1,3,5,7,9,11,13 }
	
	printf("input to append num1 ");
	scanf_s("%d", &append_num1);
	arr1 = append(arr1, append_num1, &arr_len1);

	printf("input to append num2 ");
	scanf_s("%d", &append_num2);
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

**실행 결과**

input to append num1 **10**
input to append num2 **9**
input to append num1 **8**
1 2 3 10 8
1 3 5 7 9 11 13 9



제가 만든 코드는 arr1, arr2를 동적 할당을 해서 배열을 만들고 거기에 원소를 집어넣습니다. 그리고 나서 append 

함수를 통해 arr1에는 원소를 2개 집어넣게 하고, arr2에는 원소를 1개 집어넣게 하여 그것을 출력하게 만들어 보았습니다.



제가 생각해낸 방법은 append 함수에서 새로 malloc 명령어를 사용한 뒤에, append할 함수에 할당된 원소를 배열의 길이만큼 넣은 다음에, 마지막 원소에는 추가할 겂을 넣는 것입니다. 주소값을 반환하게 할 생각으로 코드를 작성하였습니다.



다만 지금 malloc()명령어 만큼 free()명령어 만큼 입력하지 않아서  메모리 누수에 대한 부분을 재대로 처리했는지는 아직 의문이며, 이 부분에 대해서는 나중에 다시 알아볼 필요가 있다고 생각됩니다.