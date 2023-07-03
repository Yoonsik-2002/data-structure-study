#include <stdio.h>

/* 컴파일러는 파일단위로 컴파일을 하기 때문에, 외부 파일에 존재하는 구조체의 선언 및 정의를 참조하여 컴파일을 진행하지 않는다.
때문에, intdiv.c 파일에 정의되어 있는 구조체 Div를 사용하고 싶으면, 해당구조체에 대한 선언을 이 main.c 파일에서도 해 주어야 한다. */

typedef struct def {
	int quotient;	// 몫
	int remainder;  // 나머지
} Div;

extern Div int_div(int num1, int num2);	// extern 키워드 - 해당 함수 혹은 변수가 현재 파일 외부에서 선언 혹은 정의되었다고 컴파일러에게 알려줌. 찾는것은 컴파일러의 몫

void main() 
{
	Div val = int_div(6, 8);
	
	printf("몫 : %d\n", val.quotient);
	printf("나머지 : %d\n", val.remainder);
}