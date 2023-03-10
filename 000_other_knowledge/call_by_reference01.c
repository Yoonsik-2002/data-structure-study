#include <stdio.h>

void ex_func(int * ptrInt) {
	printf("--ex_func 함수 실행--\n");
	puts("");
	printf("ex_func 함수의 매개변수 ptrInt에 전달된 값 : %p\n", ptrInt);
	printf("ptrInt에 전달된 주소값을 가진 함수 외부에 선언된 변수 num에 저장된 값 : %d\n", *ptrInt);
	printf("*ptrInt의 값을 20으로 변경\n");
	puts("");
	printf("--ex_func 함수 종료--\n");
	*ptrInt = 20;
}

int main()
{
	int num = 10;

	printf("변수 num의 주소값 : %p\n", &num);
	printf("변수 num에 저장된 값 : %d\n", num);
	puts("");
	
	ex_func(&num);
	puts("");
	printf("변경된 num의 값 : %d\n", num);
}