# 2018.12.04 오늘을 챙겨요

오늘은  파이썬의 리스트에 쓰이는 명령어중 하나인 <리스트>.append(<원소>)에 대해서 알아볼 것입니다.

파이썬을 잠깐 언급하자면, 리스트에 [1,2,3] 이 들어있는데 마지막 위치에 4를 추가할 것입니다. 이를 코드로 표현하자면,

```python
arr = [1,2,3]
arr.append(4)
print(arr)
```

이렇게 되고, 실행결과는 arr = [1,2,3,4]가 됩니다.

이를 어떻게 C로 표현할 수 있을까요?

```C
#include <stdio.h>
#include <stdlib.h>

int append(int *arr, int arr_len, int num);

int main(void)
{
	//arr1[3] = { 1, 2, 3 }
	int *arr1;
	int arr_len1 = 3;
	arr1 = (int *)malloc(sizeof(int) * arr_len1);

	for (int i = 0; i < arr_len1; i++)		arr1[i] = i + 1; 

	//arr1에 새로 넣을 수를 입력받기
	int num;
	printf("input to append ");
	scanf_s("%d", &num);
	arr_len1 = append(arr1, arr_len1, num);

	//새로 넣은 수 출력하기
	for (int i = 0; i < arr_len1; i++)	printf("%d\n", arr1[i]);
	free(arr1);
	return 0;
}

int append(int *arr, int arr_len, int num)
{
	int *arr_tmp;
	arr_tmp = arr;
	arr = (int *)malloc(sizeof(int));
	arr = arr_tmp;
	arr[arr_len] = num;
	arr_len += 1;
	return arr_len;
}
```

실행은 그럴법 하게 되었지만, free문이 재대로 처리되지 않았네요... 그 부분에 대해서는 내일 더 고민해 보겠습니다!



일단 필자가 배운 범위 안에서 최대한 할 수 있는 데만큼 해 보았습니다. arr1 = { 1, 2, 3}으로 동적할당을 하고 4번째에 올 수를 입력받습니다.

그렇게 한 뒤에... 다시 고민해보니 많은 변수가 끼어있군요. 내일 다시 봐야겠습니다. 갈아엎어!!어어ㅓㅇ