# 2018.11.29 오늘을 챙겨요.

저는 포인터, 주소에 관련하여 공부를 많이 해야하기 때문에 그 부분에 대해서 많이 알아봅시다.
main함수에서 선언된 변수를 재설정할때, main밖의 함수에서 하는 법에 대해 생각해보겠습니다.

### 왜 필요하느냐?
C언어에서 제공하는 함수는 return값이 2개 이상으로 반환을 하지 못하기 때문에 이에 대한 대책이 필요합니다.

여러가지 있겠지만, 저는 그 부분에 대해서 살펴보려고 합니다.
<br>

## 포인터를 이용한다.

포인터를 이용하는 방법입니다.
방법은 값은 그대로고 주소를 꼬는 방법입니다.
```C
#include <stdio.h>

void swap(int * x, int * y)
{
	int tmp = 0;

	tmp = * x;
	* x = * y;
	* y = tmp;
}



int main(void)
{
	int * ptrnum1 = 0, * ptrnum2 = 0, * ptrnum3 = 0, * ptrnum4 = 0;
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;

	ptrnum1 = &num1;
	ptrnum2 = &num2;
	ptrnum3 = &num3;
	ptrnum4 = &num4;


	printf("스왑할 수를 입력하세요. ");
	scanf_s("%d %d", ptrnum1, ptrnum2);
	swap(ptrnum1, ptrnum2);
	printf("스왑한 수는 %d, %d 입니다.\n\n", num1, num2);

	printf("스왑할 수를 입력하세요. ");
	scanf_s("%d %d", ptrnum3, ptrnum4);
	swap(ptrnum3, ptrnum4);
	printf("스왑한 수는 %d, %d 입니다.", num3, num4);

	return 0;
}
```
다음과 같이 작성한다면, main함수에 있는 변수들을 마치 전역변수처럼 사용할 수 있게 됩니다. 포인터는 변수를 저장하는게 아니라 주소 자체를 바꾸기에 가능한 것이라고 보면 되겠습니다.
