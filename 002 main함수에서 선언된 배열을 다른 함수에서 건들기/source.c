#include <stdio.h>

void swap(int arr[10]);

int main(void)
{
	int i;

	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	swap(arr1);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");

	int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, };
	swap(arr2);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	
	printf("\npress enter to exit.");
	scanf("%c");
	return 0;
}


void swap(int arr[10])
{
	int i = 0, tmp = 0;
	for (i = 0; i < 10; i += 2)
	{
		tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
	}

}
