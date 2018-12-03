#include <stdio.h>
#include <stdlib.h>

int count(int *arr, int find, int len)
{
	int ans = 0;

	for (int i = 0; i < len; i++)
	{
		if (arr[i] == find) ans++;
	}

	return ans;
}

void function(void)
{
	int len = 0;
	printf("배열의 길이를 입력하세요. ");
	scanf_s("%d", &len);

	int *arr;

	arr = (int *)malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)	scanf_s("%d", arr + i);

	int find = 0, ans = 0;
	printf("찾을 수를 입력하세요. ");
	scanf_s("%d", &find);
	ans = count(arr, find, len);

	printf("%d의 개수는 %d개 입니다.\n", find, ans);

	free(arr);
}



int main(void)
{
	function();
	printf("\n");
	function();

	return 0;
}