# 2018.12.08 오늘을 챙겨요

오늘도 파이썬과 관련한 기능을 구현하는 것을 만들어 볼 것입니다.

C와 관련된 명령어를 알아보는 것은 시험 끝나고나 가능하겠네요 히힣.



## 	배열에서의 index를 사용하기

python에서

<리스트>.index(<원소>)라고 입력을하면 그 원소의 index값을 반환합니다.

만일 2개 이상 있으면 작은 값을 반환하고, 값이 없으면 에러를 반환합니다.

```python
a = [4,3,2,1]
print(a.index[2])
print(a.index[4])
print(a.index[0])
```

**실행결과**

2

0

ValueError: 0 is not in list





그러면 C언어에서도 동일하게 할 수 있을지 한번 만들어봅시다!!

여기서는 값이 없을때 에러 대신에 -1을 반환하는 것으로 합니다.



```C
#include <stdio.h>
#include <stdlib.h>

int index(int * arr, int arr1_len, int index_num);

int main(void)
{
	int i;

	int * arr1, arr1_len = 5; // arr1[5] = { 1, 2, 3, 4, 5 }
	arr1 = (int *)malloc(sizeof(int)*arr1_len);
	for (i = 0; i < arr1_len; i++)
        arr1[i] = i + 1;

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
```

**실행결과 1**

input to index arr1 : **2**
1

**실행결과 2**

input to index arr1 : **0**
-1



 main함수에서 arr1[5] = { 1, 2, 3, 4, 5 } 이렇게 설정하였고, 찾을 값을 입력받고, index함수를 통해 원하는 값을 받아서 그를 출력하게 설계했습니다.

index함수에서는 입력값이 arr와 arr의 길이, 찾을 값 이렇게 3개를 입력받고, arr의 원소와 찾을 값이 일치할때까지 반복문을 돌립니다. 그래서 일치하면 그 인덱스값을 리턴하고, 반복문을 다 돌아서 한번이라도 같은 부분이 없다면 -1을 출력하게 하면 됩니다.

