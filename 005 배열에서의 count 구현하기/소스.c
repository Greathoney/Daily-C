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
	printf("�迭�� ���̸� �Է��ϼ���. ");
	scanf_s("%d", &len);

	int *arr;

	arr = (int *)malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)	scanf_s("%d", arr + i);

	int find = 0, ans = 0;
	printf("ã�� ���� �Է��ϼ���. ");
	scanf_s("%d", &find);
	ans = count(arr, find, len);

	printf("%d�� ������ %d�� �Դϴ�.\n", find, ans);

	free(arr);
}



int main(void)
{
	function();
	printf("\n");
	function();

	return 0;
}