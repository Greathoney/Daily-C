# 2018.12.12 오늘을 챙겨요

오늘은 <string.h>에 있는 strcmp에 대해서 알아볼 것입니다.

strcmp(&<문자열1>, &<문자열2>) 이렇게 쓰고, 출력값은 <문자열1>이 더 크면 -1을 출력하고 <문자열2>가 더 크면 1을 출력하고, 같다면 0을 출력합니다. 이때 크고 작음을 비교할때는 첫 글자부터 아스키 코드의 값을 비교하여 대소관계를 판정합니다.

다음과 같이 작성하여 예제를 봅시다.

```C
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j;

	char *arr[4] = { "apple", "applemango", "pineapple", "pineapples" };

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", strcmp(arr[i], arr[j]));
		}
		printf("\n");
	}



	return 0;
}
```

**실행결과**

0 -1 -1 -1
1 0 -1 -1
1 1 0 -1
1 1 1 0



다음과 같이 잘 실행됨을 볼 수 있습니다.