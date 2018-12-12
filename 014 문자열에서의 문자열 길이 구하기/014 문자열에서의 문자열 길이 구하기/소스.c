#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = "hello";
	int s1_len = strlen(s1);

	char s2[15] = "applemango";
	int s2_len = strlen(s2);


	printf("%s\n", s1);
	printf("%s\n", s2);

	printf("%d\n", s1_len);
	printf("%d\n", s2_len);

	return 0;
}