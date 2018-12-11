# 2018.12.11 오늘을 챙겨요

오늘은 학교에서 C언어 기말고사입니다. 문제와 그에 대한 풀이에 대해서 알아봅시다.



### 문제

두 수를 입력받습니다. (하나는 양의 홀수, 하나는 자연수)

첫번째 수는 모래시계의 사이즈를 결정하고, 두번째 수는 모래시계의 개수를 의미합니다.

이를테면 7 2 의 두 수를 입력받으면 다음과 같은 모양과 2개의 모래시계가 그려집니다.

```
******* *******
 *****   *****
  ***     ***
   *       *
  ***     ***
 *****   *****
******* *******
```

5 5라고 입력받으면 다음과 같이 출력되게 합니다.

~~~
***** ***** ***** ***** *****
 ***   ***   ***   ***   ***
  *     *     *     *     *
 ***   ***   ***   ***   ***
***** ***** ***** ***** *****
~~~



### 해결법

이 문제는 전형적인 별 찍기 문제이므로 반복문을 적절히 이용하여 문제를 해결해나가야 합니다.

```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j, k;
	int num1, num2;
	int pick_blank, pick_star;

	scanf("%d", &num1);
	if (num1 % 2 == 0)
	{
		printf("잘못 입력하였습니다.");
		return 0;
	}
	scanf("%d", &num2);

	for (i = 0; i < num1; i++)
	{
		if (i <= num1 / 2)
		{
			pick_blank = i;
			pick_star = num1 - 2 * i;
		}
		else
		{
			pick_blank = num1 - i - 1;
			pick_star = 2 * i - num1 + 2;
		}

		for (j = 0; j < num2; j++)
		{

			for (k = 0; k < pick_blank; k++)
			{
				printf(" ");
			}
			for (k = 0; k < pick_star; k++)
			{
				printf("*");
			}
			for (k = 0; k < pick_blank + 1; k++)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
```

저는 다음과 같이 코드를 짰는데요, 어떻게 해결했는지 봅시다.



```C
	int i, j, k;
	int num1, num2;
	int pick_blank, pick_star;

	scanf("%d", &num1);
	if (num1 % 2 == 0)
	{
		printf("잘못 입력하였습니다.");
		return 0;
	}
	scanf("%d", &num2);
```

여기 부분은 num1, num2를 입력 받게 합니다. i, j, k은 반복문을 돌릴 수 있는 인덱스를 의미하고, pick_blank, pick_star은 한 줄에서 얼마나 많은 blank를 만들어야 할지, 얼마나 많은 star을 만들어야 할지 정하는 변수로 만들었습니다.

```C
	for (i = 0; i < num1; i++)
	{
		if (i <= num1 / 2)
		{
			pick_blank = i;
			pick_star = num1 - 2 * i;
		}
		else
		{
			pick_blank = num1 - i - 1;
			pick_star = 2 * i - num1 + 2;
		}

		for (j = 0; j < num2; j++)
		{
            //...
```

정상적인 모래시계 그림을 출력하기 위해서는 줄바꿈이 몇 번 입력되어야하는지 보아야 하는데요, 모래시계를 보면 알겠지만, num1만큼 줄바꿈이 된다는 것을 알고 있습니다. 그래서 i < num1을 쓰게 된 것입니다. j 반복문 안에서는 num2 만큼 반복하게 되는데요, 이는 모래시계를 각각 출력하는데 반복하는 것을 말합니다. 그렇게 하고 나서, 모래시계 모양을 보면 위쪽 부분과 아래쪽 부분으로 나눌 수 있으므로 num1 / 2 값을 이용해서 pick_blank와 pick_star값을 결정하게 합니다.  pick_blank와 pick_star의 값은 다음 설명을 통해 알아봅시다.

```C
		for (j = 0; j < num2; j++)
		{

			for (k = 0; k < pick_blank; k++)
			{
				printf(" ");
			}
			for (k = 0; k < pick_star; k++)
			{
				printf("*");
			}
			for (k = 0; k < pick_blank + 1; k++)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
```



보면 pick_blank번 반복, pick_star번 반복, pick_blank+1번 반복 이렇게 적혀있는 모습을 확인할 수 있는데, 이는 모래시계의 대칭성을 보면 왼쪽의 빈칸만큼, 오른쪽의 빈칸이 되어야 한다는 것입니다. 오른쪽의 +1은 한칸 공백을 준 것입니다.

모래시계가 위쪽 방향일때 pick_blank = i 값 만큼 되는 것이고 pick_blank = num1 - i - 1; 값이라는 것을 규칙을 잘 세면 단번에 알 수 있는 것입니다.

마찬가지로 모래시계가 아래쪽 방향일때 위쪽 방향의 맨 아래 부분과 겹치므로 한칸 빼줍니다. 이는 pick_blank = num1 - (i + 1); 이고 pick_star =  2 * (i + 1) - num1 이렇게 쓸 수 있음은 크게 생각 하지 않고도 금방 알 수 있는 부분이었습니다.