# 2018.12.07 오늘을 챙겨요

오늘은 일찍 챙길 겁니다...히힣 시험공부를 위해서죠.



어제 append에 대해서 깔끔히 마무리 했으니, 한 단계 발전시킨 insert함수 만들기에 도전합시다!!!



## 그 전에!!

어제 작성한 코드에서 조금 더 최적화를 할 수 있을 것 같습니다!!

```C
#include <stdio.h>
#include <stdlib.h>

int * append(int * arr, int append_num, int * len)
{
	int *tmp_arr;
	tmp_arr = (int *)malloc(sizeof(int)*(*len + 1));

	for (int i = 0; i < *len; i++)	tmp_arr[i] = arr[i];
	tmp_arr[*len] = append_num;

	*len += 1;

	free(arr);

	return tmp_arr;
}

int main(void)
{
	int arr_len1 = 3;
	int * arr1;
	arr1 = (int *)malloc(sizeof(int) * arr_len1);
	for (int i = 0; i < arr_len1; i++)		arr1[i] = i + 1;
	// arr1[3] = { 1,2,3 }

	int arr_len2 = 7;
	int * arr2;
	arr2 = (int *)malloc(sizeof(int) * arr_len2);
	for (int i = 0; i < arr_len2; i++)		arr2[i] = 2 * i + 1;
	// arr2[7] = { 1,3,5,7,9,11,13 }

	printf("input to append num1 ");
	int append_num1 = 0;
	scanf_s("%d", &append_num1);

	printf("input to append num2 ");
	int append_num2 = 0;
	scanf_s("%d", &append_num2);

	arr1 = append(arr1, append_num1, &arr_len1);
	arr2 = append(arr2, append_num2, &arr_len2);

	printf("input to append num1 ");
	scanf_s("%d", &append_num1);
	arr1 = append(arr1, append_num1, &arr_len1);

	for (int i = 0; i < arr_len1; i++)	printf("%d ", arr1[i]);
	printf("\n");
	for (int i = 0; i < arr_len2; i++)	printf("%d ", arr2[i]);

	free(arr1);
	free(arr2);


	return 0;
}
```

어제와의 차이는 delete_arr를 사용하지 않았다는 것이고, delete_arr를 사용할 필요가 없다고 느껴서 지웠습니다.

그 이유는 main함수에서 arr1이 append으로부터 받는 return값은 tmp_arr의 주소이므로 append함수 안에 있는 arr은 return tmp_arr를 한다면 그저 필요없는 것이므로 그 자리에서 free(arr)를 취해주는 겁니다. 저렇게 작성한다면 더 효율적으로 작성된 것이라고 생각합니다.



## 그럼 원래 목적으로 들어가볼까요?

### Python에서의 insert란...

리스트의 메소드로, insert 명령어 인자로 값, 인덱스가 옵니다.

<리스트>.insert(<값>, <인덱스>) 다음과 같이 쓰는 데요.

```Python
a = [1,3,4]
a.insert(2,1)
print(a)
```

하면 실행결과 값이 [1,2,3,4]가 나오게 할 수 있습니다.



### C로 어떻게 표현할까?

어제 만든 내용을 기반으로 다음과 같이 작성할 수 있을 것이라고 생각했습니다. 여기 코드에서는 insert와 append 두개 모두 올렸습니다.

```C
#include <stdio.h>
#include <stdlib.h>

int * insert(int * arr, int insert_num, int insert_num_index, int * len);
int * append(int * arr, int append_num, int * len);

int main(void)
{
	int i;

	int insert_num1, insert_num1_index, append_num1;

	// arr1[3] = { 1,2,3 }
	int arr_len1 = 3;
	int * arr1;
	arr1 = (int *)malloc(sizeof(int) * arr_len1);
	for (int i = 0; i < arr_len1; i++)		arr1[i] = i + 1;

	printf("Before inserting.\n");
	for (i = 0; i < arr_len1; i++)		printf("%d ", arr1[i]);

	//insert를 실행하는 부분입니다.
	printf("\ninput to insert number ");
	scanf_s("%d", &insert_num1);

	printf("input to insert number's index ");
	scanf_s("%d", &insert_num1_index);

	arr1 = insert(arr1, insert_num1, insert_num1_index, &arr_len1);


	printf("\nAfter inserting.\n");
	for (i = 0; i < arr_len1; i++)		printf("%d ", arr1[i]);


	//append를 실행하는 부분입니다.
	printf("\n\ninput to inset number ");
	scanf_s("%d", &append_num1);

	arr1 = append(arr1, append_num1, &arr_len1);
	printf("After appending.\n");
	for (i = 0; i < arr_len1; i++)		printf("%d ", arr1[i]);

	free(arr1);

	return 0;
}

int * append(int * arr, int append_num, int * len)
{
	int *tmp_arr;
	tmp_arr = (int *)malloc(sizeof(int)*(*len + 1));

	for (int i = 0; i < *len; i++)	tmp_arr[i] = arr[i];
	tmp_arr[*len] = append_num;

	*len += 1;

	free(arr);

	return tmp_arr;
}

int * insert(int * arr, int insert_num, int insert_num_index, int * len)
{
	int i;

	int *tmp_arr;
	tmp_arr = (int *)malloc(sizeof(int)*((*len)++ + 1));

	for (i = 0; i != insert_num_index; i++)		tmp_arr[i] = arr[i];

	tmp_arr[i++] = insert_num;

	for (; i < *len; i++)	tmp_arr[i] = arr[i - 1];

	free(arr);

	return tmp_arr;
}
```

**실행결과**

Before inserting.

1 2 3

input to insert number **0**

input to insert number's index **0**

After inserting.

0 1 2 3

input to inset number **4**

After appending.

0 1 2 3 4



아주 잘 실행되는 모습을 볼 수 있고, malloc명령어를 쓴 만큼 free명령어로 동적할당도 잘 풀었음을 볼 수 있습니다.



### 코드풀이

int * insert() 함수를 봅시다.

첫 번째로 return 값은 정수형의 포인터값입니다. 실제로 동적할당을 한 배열의 주소가 return 값이기에 저렇게 쓰면 된다고 보면 됩니다. 왜 return 값이 insert()함수 내에서 사용하는 이유는 main함수 내에서 arr1이 주소를 새로 받으려고 하기 때문입니다.

```C
	int *tmp_arr;
	tmp_arr = (int *)malloc(sizeof(int)*(*len + 1));
```

새로운 tmp_arr 배열을 만들고 이를 insert하고자 하는 배열보다 한칸 더 길게 받습니다.

```C
for (i = 0; i != insert_num_index; i++)
    tmp_arr[i] = arr[i];

tmp_arr[i++] = insert_num; //명령어를 실행시킨 후 i에 1 추가

for (; i < *len; i++)
    tmp_arr[i] = arr[i - 1];
```

여기는 insert_num_index를 만나기 전까지 tmp_arr을 arr값을 그대로 복사합니다.

만난다면, 준비한 insert_num값을 넣고

그 뒤에는 arr이 한칸씩 밀린 값을 넣어주어 완성합니다.

```C
	free(arr);

	return tmp_arr;
```

이제는 더이상 쓰지 않을 arr에 동적 할당되어있는 데이터를 free를 통해서 풀어주고,

내가 원하고자 하는 배열인 tmp_arr의 주소를 반환합니다.

그 반환한 값은 main함수의 arr1이 받게 되며, arr1에 새로운(내가 원하는) 배열이 성공적으로 들어가고, 자동적으로 arr_len1 값도 주소를 할당받아 수를 변경할 수 있기에 1 증가한 모습을 보여줍니다.



이렇게 insert도 쉽게 끝냈습니다.
