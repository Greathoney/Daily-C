# 2018.12.18 오늘을 챙겨요

오늘은  함수에서 구조체를 매개변수로 사용하는 방법에 대해서 알아보겠습니다.



이번에 다룰 내용은 김도훈과 윤대헌이 가지고 있는 프린터에 남아있는 빨간색, 초록색, 파란색, 검은색 잉크 잔량에 대해서 정보를 어떻게 처리할 지에 대해서 코드를 작성해볼 것입니다.

```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Printer {
	char name[20];
	int red;
	int green;
	int blue;
	int black;
};

void reminder(struct Printer P)
{
	printf("프린터 이름: %s\n", P.name);
	printf("남은 빨간색 잉크 %d%%\n", P.red);
	printf("남은 초록색 잉크 %d%%\n", P.green);
	printf("남은 파란색 잉크 %d%%\n", P.blue);
	printf("남은 검은색 잉크 %d%%\n\n", P.black);
}

int main(void)
{
	struct Printer KDH_P;

	strcpy(KDH_P.name, "김도훈의 프린터");
	KDH_P.red = 100;
	KDH_P.green = 100;
	KDH_P.blue = 100;
	KDH_P.black = 100;


	struct Printer YDH_P;
	strcpy(YDH_P.name, "윤대헌의 프린터");
	YDH_P.red = 80;
	YDH_P.green = 70;
	YDH_P.blue = 10;
	YDH_P.black = 50;

	reminder(KDH_P);
	reminder(YDH_P);


	return 0;
}
```

**실행 결과**

프린터 이름: 김도훈의 프린터

남은 빨간색 잉크 100%

남은 초록색 잉크 100%

남은 파란색 잉크 100%

남은 검은색 잉크 100%



프린터 이름: 윤대헌의 프린터

남은 빨간색 잉크 80%

남은 초록색 잉크 70%

남은 파란색 잉크 10%

남은 검은색 잉크 50%



---

이 부분만 보도록 하겠습니다.

~~~C
void reminder(struct Printer P)
{
	printf("프린터 이름: %s\n", P.name);
	printf("남은 빨간색 잉크 %d%%\n", P.red);
	printf("남은 초록색 잉크 %d%%\n", P.green);
	printf("남은 파란색 잉크 %d%%\n", P.blue);
	printf("남은 검은색 잉크 %d%%\n\n", P.black);
}
...
    reminder(KDH_P); //main 함수에 들어있는 명령어
~~~

함수에서 struct Printer P라고 하고 있고 이는 main함수에서 미리 선언하고 있는 KDH_P, YDH_P의 구조체를 들고옴을 볼 수 있습니다. 이를 P라고 새로 정의를 하여 P.name, P.red, P.green, P.blue, P.black를 사용할 수 있게 됩니다. 이는 KDH_P가 들어가면 P가 KDH_P로 치환되어 들어감을 볼 수가 있습니다.