# 2018.12.19 오늘을 챙겨요

오늘은 함수 포인터를 사용하는 법에 대해서 알아볼 것입니다.



```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}


int main(void)
{
	int (*function)(int, int) = NULL;

	int pick = 0;
	printf("더할 것이면 1을 입력하고 뺄 것이면 2를 입력하세요. : ");
	scanf("%d", &pick);

	int num1 = 0, num2 = 0, result = 0;
	printf("두 수를 입력하세요. : ");
	scanf("%d%d", &num1, &num2);

	if (pick == 1)
		function = add;

	else
		function = sub;

	if (pick == 1)
		printf("두 수의 합은 %d입니다.\n", function(num1, num2));
	else
		printf("두 수의 차는 %d입니다.\n", function(num1, num2));

	return 0;
}
```

**실행결과**

더할 것이면 1을 입력하고 뺄 것이면 2를 입력하세요. : **2**

두 수를 입력하세요. : **10** **7**

두 수의 차는 3입니다.



---

함수형 포인터는 <함수 자료형> (*<포인터 이름>)(<함수 매개변수들...>) = NULL 이라고 입력하면 되고 <포인터 이름> = <가져올 함수 이름> 이렇게 하면 <포인터 이름>에 <가져올 함수>를 그대로 사용할 수 있게 됩니다. 이거 나중에 요긴하게 사용할 수 있을 것 같은데요??