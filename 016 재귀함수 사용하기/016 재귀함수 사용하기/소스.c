#include <stdio.h>

int fact(int input)
{
	if (input == 1)
		return 1;
	return input * fact(input - 1);
}

int main(void)
{
	int input, answer;
	scanf_s("%d", &input);
	answer = fact(input);
	printf("%d", answer);

	return 0;
}