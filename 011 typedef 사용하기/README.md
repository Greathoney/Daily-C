# 2018.12.09 오늘을 챙겨요

이렇게 추운날 또 C언어를 조금씩 알아봅시다.



## typedef 사용해보기

tpyedef은 struct를 새로 선언할 때 앞에 붙여서, main이나 다른 함수 안에서 새로운 struct를 선언할 때 조금 더 간단하게 해 주는 기능을 가지고 있습니다.



```C
#include <stdio.h>

typedef struct CAST_score{
	int Korean;
	int Math;
	int English;
} Student_CAST_score;

int main(void)
{
	Student_CAST_score KDH, YDH;

	KDH.Korean = 100;
	KDH.Math = 100;
	KDH.English = 100;

	YDH.Korean = 70;
	YDH.Math = 85;
	YDH.English = 65;

	printf("김도훈의 수능 평균 점수 : %.2f\n",
		(float)(KDH.Korean + KDH.Math + KDH.English) / 3);
	printf("윤대헌의 수능 평균 점수 : %.2f\n",
		(float)(YDH.Korean + YDH.Math + YDH.English) / 3);

	return 0;
}
```

**실행결과**

김도훈의 수능 평균 점수 : 100.00

윤대헌의 수능 평균 점수 : 73.33



```C
typedef struct CAST_score{
	int Korean;
	int Math;
	int English;
} Student_CAST_score;
```



이 부분에서 이 struct의 이름은 CAST_score이고 typedef를 이용했으니 밑에 Student_CAST_score이라고 하여 main함수나 다른 함수에서 부르기 쉽게 하였습니다.



```C
Student_CAST_score KDH, YDH;

	KDH.Korean = 100;
	KDH.Math = 100;
	KDH.English = 100;

	YDH.Korean = 70;
	YDH.Math = 85;
	YDH.English = 65;
```

main 함수 안 입니다. 첫 줄은 typedef를 사용하여 간결히 나타낼 수 있음을 볼 수 있고, 밑의 줄은 struct처럼 사용하면 됨을 볼 수 있었습니다.