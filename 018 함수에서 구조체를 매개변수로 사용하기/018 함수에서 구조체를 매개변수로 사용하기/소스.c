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
	printf("������ �̸�: %s\n", P.name);
	printf("���� ������ ��ũ %d%%\n", P.red);
	printf("���� �ʷϻ� ��ũ %d%%\n", P.green);
	printf("���� �Ķ��� ��ũ %d%%\n", P.blue);
	printf("���� ������ ��ũ %d%%\n\n", P.black);
}

int main(void)
{
	struct Printer KDH_P;

	strcpy(KDH_P.name, "�赵���� ������");
	KDH_P.red = 100;
	KDH_P.green = 100;
	KDH_P.blue = 100;
	KDH_P.black = 100;


	struct Printer YDH_P;
	strcpy(YDH_P.name, "�������� ������");
	YDH_P.red = 80;
	YDH_P.green = 70;
	YDH_P.blue = 10;
	YDH_P.black = 50;

	reminder(KDH_P);
	reminder(YDH_P);


	return 0;
}