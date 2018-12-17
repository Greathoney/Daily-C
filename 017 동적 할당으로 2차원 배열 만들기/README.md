# 2018.12.17 오늘을 챙겨요

오랜만에 daily-c를 하는것 같군요.

오늘은 malloc를 이용하여 2차원 배열을 만들어 볼 것입니다.



~~~C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j;

	int arr_height = 5, arr_width = 3;
	int **arr;
	arr = (int **)malloc(sizeof(int*) * arr_height);
	for (int i = 0; i < arr_height; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * arr_width);
	}

	for (i = 0; i < arr_height; i++)
	{
		for (j = 0; j < arr_width; j++)
		{
			arr[i][j] = i * 10 + j;
		}
	}

	for (i = 0; i < arr_height; i++)
	{
		for (j = 0; j < arr_width; j++)
		{
			printf("%d\n", arr[i][j]);
		}
	}

	for (i = 0; i < arr_height; i++)
	{
		free(arr[i]);
	}

	free(arr);

	return 0;
}
~~~

**실행결과**

0

1

2

10

11

12

20

21

22

30

31

32

40

41

42



만드는 방법은 간단합니다.

~~~C
	int arr_height = 5, arr_width = 3;
	int **arr;
	arr = (int **)malloc(sizeof(int *) * arr_height);
	for (int i = 0; i < arr_height; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * arr_width);
	}
~~~

arr을 2중 포인터로 하여 여러개의 주소를 가르킬 하나의 주소를 가져옵니다. arr은 주소에 대한 정보를 담는 공간을 만들게 되고, 거기에 1차원적인 배열에 대한 주소를 가리키게 됩니다. 그렇게 한 뒤, 각각의 배열은 실제 값을 가리키게 되는 것이고 쉽게 만들 수 있겠습니다.