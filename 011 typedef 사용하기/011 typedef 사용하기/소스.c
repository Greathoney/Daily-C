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

	printf("±èµµÈÆÀÇ ¼ö´É Æò±Õ Á¡¼ö : %.2f\n",
		(float)(KDH.Korean + KDH.Math + KDH.English) / 3);
	printf("À±´ëÇåÀÇ ¼ö´É Æò±Õ Á¡¼ö : %.2f\n",
		(float)(YDH.Korean + YDH.Math + YDH.English) / 3);

	return 0;
}