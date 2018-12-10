# 2018.12.10 오늘을 챙겨요

오늘은 공용체에 대해서 알아보겠습니다.



```C
#include <stdio.h>

union CAST_Science_Score {
	int P1, P2;
	int C1, C2;
	int B1, B2;
	int E1, E2;
};


int main(void)
{
	union CAST_Science_Score KDH_Science_Score[2];
	union CAST_Science_Score YDH_Science_Score[2];

	KDH_Science_Score[0].P1 = 50;
	KDH_Science_Score[1].E2 = 50;

	YDH_Science_Score[0].P1 = 32;
	YDH_Science_Score[1].C1 = 28;

	printf("김도훈의 평균 과탐점수 : %.2f\n", (float)(KDH_Science_Score[0].P1 + KDH_Science_Score[1].E2) / 2);
	printf("윤대헌의 평균 과탐점수 : %.2f\n", (float)(YDH_Science_Score[0].P1 + YDH_Science_Score[1].E2) / 2);

	return 0;
}
```

**실행결과**

김도훈의 평균 과탐점수 : 50.00

윤대헌의 평균 과탐점수 : 30.00



언뜻 보면 구조체와 큰 차이는 보이지 않는 것 같습니다. 구조체와 공용체의 차이는 무엇일까요?



공용체는 공용체와 달리 구조체 안에 선언되어있는 변수 중 하나만 가져와서 쓸 수 있습니다.

즉 다른 변수가 선언하게 된다면 원에 있던 변수는 사라지게 되는 것이죠.