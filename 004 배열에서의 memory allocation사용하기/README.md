# 2018.12.02 오늘을 챙겨요
이번에는 배열에서의 memory allocation을 사용해 봅시다.

### 왜 사용하느냐?
visual studio에서는 배열을 선언할 때, 그 배열의 길이를 변수만큼 받지를 못합니다.
그러나 malloc를 사용하게 된다면, 동적 할당을 통해 내가 원하는 길이만큼 받을 수 있게 되는 것이죠.

malloc()를 이용하여, 배열의 길이를 입력받고, 배열에 0부터 1씩 증가하는 원소를 넣은 뒤에 출력을 해 보겠습니다.

---
```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int len;

	printf("배열의 길이를 입력하세요. ");
	scanf_s("%d", &len);

	int * arr;
	arr = malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)
	{
		arrptr[i] = i;
	}

	for (int i = 0; i < len; i++)
	{
		printf("%p ", &arr[i]);
		printf("%d\n", arr[i]);
	}
}
```
**실행결과**
배열의 길이를 입력하세요. **5**
001B5230 0
001B5234 1
001B5238 2
001B523C 3
001B5240 4

---

여기서 * arr은 malloc를 통하여 4바이트 * 5 = 20바이트를 동적 할당 받았으며, arr의 값은 원소[0]의 주소(&arr[0])가 되겠습니다. 그리고 arr은 정수형이므로 다음 원소는 4바이트 뒤에 있음을 알 수 있습니다.
