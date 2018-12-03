# 2018.12.03 오늘을 챙겨요.
오늘은 파이썬에서 이용되는 기능인 <리스트>.count(<원소>)의 기능을 C에서도 그대로 사용해 볼 수 있도록 해보겠습니다.

```C
#include <stdio.h>
#include <stdlib.h>

int count(int *arr, int find, int len)
{
	int ans = 0;

	for (int i = 0; i < len; i++)
	{
		if (arr[i] == find) ans++;
	}

	return ans;
}

void function(void)
{
	int len = 0;
	printf("배열의 길이를 입력하세요. ");
	scanf_s("%d", &len);

	int * arr;

	arr = (int * )malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)	scanf_s("%d", arr + i);

	int find = 0, ans = 0;
	printf("찾을 수를 입력하세요. ");
	scanf_s("%d", &find);
	ans = count(arr, find, len);

	printf("%d의 개수는 %d개 입니다.\n", find, ans);

	free(arr);
}

int main(void)
{
	function();
	printf("\n");
	function();

	return 0;
}

```
**실행 결과**
배열의 길이를 입력하세요. **10
1 2 2 3 3 3 4 4 4 4**
찾을 수를 입력하세요. **3**
3의 개수는 3개 입니다.

배열의 길이를 입력하세요. **7
3 5 5 3 1 2 2**
찾을 수를 입력하세요. **3**
3의 개수는 2개 입니다.

이전에 배웠던 malloc 명령어를 이용하여 원하는 길이의 배열 arr를 선언합니다. 그리고 arr에 각 원소의 개수를 넣어줍니다.

다음으로 찾을 값을 입력받고, 정수형 count함수를 통해 ans를 반환하도록 합니다.

그 과정에서는, 모든 원소를 비교하여 일치하는 값이 있으면 ans++을 합니다.

그러면 파이썬에서 쓰는 명령어와 같이 실행됨을 볼 수 있습니다.
