#include <stdio.h>
#include <stdbool.h> // bool, true, false가 정의된 헤더파일

#define ADD true
#define MIN false

void main()
{
	int num1, num2;
	printf("두 개의 정수를 입력 : ");
	scanf("%d %d", &num1, &num2);
	
	#if ADD // ADD가 참이라면 두 지시어 사이의 소스코드 삽입
		printf("%d + %d = %d", num1, num2, num1 + num2);
	#endif 
	
	#if MIN // MIN이 참이라면 두 지시어 사이의 소스코드 삽입
		printf("%d - %d = %d", num1, num2, num1 - num2);
	#endif
}