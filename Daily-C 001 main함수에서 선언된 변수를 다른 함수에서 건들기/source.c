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
