# 2018.12.22 오늘을 챙겨요

오늘은 realloc 명령어에 대해서 알아볼 것입니다. realloc는 malloc를 통하여 할당된 메모리의 사이즈를 변경할 때 사용하는 것입니다.

```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;

	int *arr1;
	arr1 = (int *)malloc(sizeof(int) * 4);
	for (i = 0; i < 4; i++)
		arr1[i] = i + 1;

	for (i = 0; i < 4; i++)
		printf("%d ", arr1[i]);
	printf("\n");

	realloc(arr1, sizeof(int) * 10);

	for (i = 4; i < 10; i++)
		arr1[i] = 100 - i;
	
	for (i = 0; i < 10; i++)
		printf("%d ", arr1[i]);
	
	free(arr1);
	return 0;
}
```

relloc(<배열의 주소>, <크기>)라고 입력하면 되는데, 크기에는 sizeof(<자료형>) * 개수 라고 입력하는 것이 편합니다. 이렇게 하면 배열의 길이를 마음대로 조절할 수 있게 되는 것입니다. 그럼 전에 했었던 "배열에서의 append명령어 사용하기"파트에서 더 최적화를 할 수 있겠죠???