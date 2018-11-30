# 2018.11.30 오늘을 챙겨요
포인터, 주소 등등... 열심히 공부해 봅시다! 이번에는 변수가 아닌 포인터를 건드려 봅시다.


이번에는 main함수에서 배열을 선언한 후에, swap함수에서 그 배열을 선언한 값을 바꾸어 보도록 하겠습니다.
함수에서 arr1을 조작한 배열을 return하도록 만들어보았습니다.
```C
#include <stdio.h>

int swap(int arr[10]);

int main(void)
{
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	arr1 = swap(arr1);

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr1[i]);
	}
}

int swap(int arr[10])
{
	int i = 0, tmp = 0;
	for (i = 0; i < 10; i+=2)
	{
		tmp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = tmp;
	}

	return arr;
}
```
<br><br>
그러나 잘 작동되지 않은 모습을 보입니다. 처음에는 배열이 제 포인터의 역할을 못한다고 생각했고 다음과 같이 코드를 수정해보았습니다.

```C
#include <stdio.h>

int swap(int arr[10]);

int main(void)
{
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int * arrptr1;

	arrptr1 = &arr1;

	arrptr1 = swap(arrptr1);

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
}

int swap(int arr[10])
{
	int i = 0, tmp = 0;
	for (i = 0; i < 10; i += 2)
	{
		tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
	}

	return arr;
}
```
<br><br>
역시 실행이 잘 되지 않은 모습을 볼 수 있었습니다.

그래서 어떻게 해야할 지 몰아서 곰곰히 생각해 본 결과, 어저피 포인터를 건들기 때문에 함수에서의 반환값은 필요없다고 생각하였고, 배열 자체가 포인터값을 가리키고 있기 때문에 다음과 같이 수정하기로 마음먹었습니다.
```C
#include <stdio.h>

void swap(int arr[10]);

int main(void)
{
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	swap(arr1);

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}

	return 0;
}

void swap(int arr[10])
{
	int i = 0, tmp = 0;
	for (i = 0; i < 10; i += 2)
	{
		tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
	}

}
```
실행 결과 잘 실행됨을 볼 수 있었습니다. int arr[10] = arr1 이렇게 들어가기에, arr1의 주소가 int arr[10]에 들어가게 되므로 결국 arr1의 주소가 들어가는 모습을 볼 수 있었고, 이렇게 사용하면 되는 것을 알게 되었습니다.
