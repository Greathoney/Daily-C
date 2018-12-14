# 2018.12.14 오늘을 챙겨요

오늘은 재귀함수를 이용한 팩토리얼을 구현해보도록 하겠습니다.



```C
#include <stdio.h>

int factorial(int input)
{
	if (input == 1)
		return 1;
	return input * factorial(input - 1);
}

int main(void)
{
	int input, answer;
	scanf_s("%d", &input);
	answer = factorial(input);
	printf("%d", answer);

	return 0;
}
```

**실행 결과**

**4**

24



~~~
	return input * factorial(input - 1);
~~~

아마 이 부분이 가장 난감하다고 생각되는데요, 쉽게 생각해보면 input * factorial(input - 1)은 input * (input - 1) * factorial(input -2) 와 같고, input * (input - 1) * (input - 2) * factorial(input -3)... 이렇게 나아간다는 것을 쉽게 알 수가 있습니다.