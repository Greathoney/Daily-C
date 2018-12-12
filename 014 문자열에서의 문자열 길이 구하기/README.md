# 2018.12.12 오늘을 챙겨요

오늘은 C언어의 문자열에 대해서 알아보려고 합니다. 그중 <string.h> 헤더 파일에 있는 strlen이라는 명령어를 사용해볼 것입니다.



```C
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
```

**실행결과**

5

10



s1은 포인터로 지정하여 hello 전부를 받을 수 있게끔 하였고, s2는 15바이트만큼 공간을 할당하여서 applemango라는 값을 입력하였습니다. 그리고 strlen(<문자열 주소>)를 이용하여 각 문자열의 크기를 받습니다. s1 같은 경우에는 hello 5글자만큼 하였기 때문에 5가 출력되었고, s2 같은 경우 applemango 10글자만큼 있기 때문에 10을 출력하게 되는 것입니다. 이때 s2이 받을수 있는 최대 크기인 15를 막론하고 applemango 유효한 값만 들어가 있다는 것을 알 수 있습니다.