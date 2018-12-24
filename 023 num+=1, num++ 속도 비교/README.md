 # 2018.12.24 오늘을 챙겨요

오늘은 num += 1, num++, num = num + 1 에 대한 속도 차이에 대해서 알아보겠습니다. 다음과 실행시켜보고 결과를 보겠습니다.

```C
#include <stdio.h>
#include <time.h>

int main(void)
{
	int i, j;

	int num;
	clock_t clock(void);
	int time[10][4] = { 0, };

	printf("++      +=1      ='+1\n");
	for (i = 0; i < 10; i++)
	{
		time[i][0] = clock();
		for (j = 0, num = 0; j < 2000000000; j++)
			num++;

		time[i][1] = clock();
		for (j = 0, num = 0; j < 2000000000; j++)
			num += 1;

		time[i][2] = clock();
		for (j = 0, num = 0; j < 2000000000; j++)
			num = num + 1;

		time[i][3] = clock();
		for (j = 0; j < 3; j++)
			printf("%d    ", time[i][j + 1] - time[i][j]);

		printf("\n");
	}

	printf("\n평균\n");

	int sum;
	for (j = 0; j < 3; j++)
	{
		for (i = 0, sum = 0; i < 10; i++)
		{
			sum += time[i][j+1] - time[i][j];
		}
		printf("%d    ", sum / 10);
	}
	return 0;
}
```

**실행결과**

++      +=1      ='+1

3764    3738    3741

3764    3727    3766

3672    3653    3655

3660    3756    3738

3769    3681    3658

3755    3767    3753

3753    3769    3763

3765    3747    3754

3755    3731    3756

3726    3743    3735



평균

3738    3731    3731



비교해 본 결과 완전히 똑같다고 해도 무방합니다. 따라서 이 부분에서는 최적화 코딩보다는 사람들에게 잘 보일 수 있게 하는 코딩을 하는 것을 추천합니다.