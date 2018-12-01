#변수에서의 malloc 사용하기
malloc()는 rvalue에 쓰는 것이고 ()안에 들어있는 자연수 크기만큼 메모리를 할당해 주고
그래서 malloc(4) 또는 malloc(sizeof(int))은 int형 정수 크기 만큼 메모리를 할당합니다.

그리고 malloc()의 lvalue로서는 포인터값을 입력합니다.

그리고 이제 필요가 없다고 생각되면 free(numptr)을 하여, 메모리 누수가 일어나지 않게 합니다.


```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int * numptr;
	numptr = malloc(sizeof(int));

	* numptr = 10;

	printf("%d", * numptr);

	free(numptr);

	return 0;
}
```

다음과 같이 입력하면,
numptr에는 주소값(0x......)이 들어갑니다.
그리고 주소를 가리키는 변수에는 임의의 수가 들어갑니다.

그렇게 하여 numptr가 가르키는 곳(* numptr)에 10을 넣어주게 됩니다.
그리고 free로 끝냅니다.

만일 * numptr를 하지 않으면 임의의 정수형을 출력하게 됩니다.

```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int * numptr1;
	numptr1 = malloc(sizeof(int));
	int * numptr2;
	numptr2 = malloc(sizeof(int));

	* numptr1 = 10;
	* numptr2 = 20;

	printf("%p, %d\n", numptr1, * numptr1);
	printf("%p, %d", numptr2, * numptr2);

	free(numptr1);
	free(numptr2);

	return 0;
}
```
실행결과
000001FD9FBC4990, 10
000001FD9FBC49D0, 20

잘 되는 모습을 볼 수 있습니다.
