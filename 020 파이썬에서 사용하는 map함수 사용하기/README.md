# 2018.12.20 오늘을 챙겨요

오늘은 파이썬에서 사용하는 map함수를 C언어에서 구현해 봅시다.



여기서 map함수란 어떻게 쓰이는 것이라면, 기본적인 명령문 구조는 다음과 같습니다.

~~~Python
map(<함수>, <리스트1>, <리스트2>, ...)
~~~



이때, 리스트가 1개면 함수의 입력값은 1개, 출력값은 1개가 나오게 설계해야하고, 리스트가 2개면 함수의 입력값은 2개, 출력값은 1개가 나오게 해야 합니다.



```C
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

	for (i = 0; i < len_arr; i++)
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
    // arr1[3] = { 2, 4, 6, 8 }

	arr1 = map(Double, arr1, len_arr1);
    // arr1[3] = { 4, 8, 12, 16}

	for (i = 0; i < len_arr1; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n\n");

	int *arr2, len_arr2 = 4;
	arr2 = (int *)malloc(sizeof(int) * len_arr2);
	for (i = 0; i < 4; i++)
		arr2[i] = 2 + 2 * i;
    // arr2[3] = { 2, 4, 6, 8 }

	arr2 = map(Square, arr2, len_arr2);

	for (i = 0; i < len_arr1; i++)
	{
		printf("%d ", arr2[i]);
	}
    //arr2[3] = { 4, 16, 36, 64 }

	return 0;
}
```

**실행 결과**

4 8 12 16

4 16 36 64



---



어제 함수형 포인터를 배웠었는데, 이를 잘 이용하면 쉽게 작성할 수 있을거라 생각합니다.  그리고 며칠 전에 했었던 "배열에서의 append 사용하기"를 잘 사용하면 금방 할 수 있을 겁니다.



```C
arr1 = map(Double, arr1, len_arr1);
```

map이라는 함수를 만들었고, 거기에 <함수 주소>, <배열1 주소>, <배열1에 대한 길이값> 를 넣었습니다. 이는...

```C
int * map(int(*function)(int), int *arr, int len_arr)
```

int (*function)(int) = Double

*arr = arr1

len_arr = len_arr1

이렇게 하나씩 잘 매칭됨을 볼 수 있습니다.

```C
int * map(int(*function)(int), int *arr, int len_arr)
{
	int i;

	for (i = 0; i < len_arr; i++)
	{
		arr[i] = function(arr[i]);
	}

	return arr;
}
```

그렇게 하여 배열의 길이만큼 arr의 각 원소값을 function함수를 통해 수정수정합니다.

그런 뒤에 수정된 값이 들어있는 arr주소를 반환하게 합니다.

그럼 원래식으로 돌아와 arr1이 그 주소를 받겠죠???



이렇게 쓰면 될 것입니다.