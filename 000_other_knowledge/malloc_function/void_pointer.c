#include <stdio.h>

void simpleFunc(void)
{
	printf("simple function");
}

void main()
{
	void * ptr; // void 형 포인터 선언
	
	int num = 20;
	float score = 4.5;
	char mark = 'A';
	
	ptr = &num;
	printf("%p \n", ptr);
	ptr = &score;
	printf("%p \n", ptr);
	ptr = &mark;
	printf("%p \n", ptr);
	
	ptr = simpleFunc;
	printf("%p \n", ptr);
}