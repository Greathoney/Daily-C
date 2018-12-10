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

	printf("±èµµÈÆÀÇ Æò±Õ °úÅ½Á¡¼ö : %.2f\n", (float)(KDH_Science_Score[0].P1 + KDH_Science_Score[1].E2) / 2);
	printf("À±´ëÇåÀÇ Æò±Õ °úÅ½Á¡¼ö : %.2f\n", (float)(YDH_Science_Score[0].P1 + YDH_Science_Score[1].E2) / 2);

	return 0;
}