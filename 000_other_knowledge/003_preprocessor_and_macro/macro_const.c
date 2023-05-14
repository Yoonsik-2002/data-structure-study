#include <stdio.h>

#define NAME "ChoYoonsik"
#define AGE 22
#define PRINT_ADDR puts("주소 : 인천광역시 서구 당하동\n");

void main()
{
	printf("이름 : %s\n", NAME);
	printf("나이 : %d\n", AGE);
	PRINT_ADDR;
}