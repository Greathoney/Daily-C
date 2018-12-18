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