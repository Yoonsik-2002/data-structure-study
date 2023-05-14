#include <stdio.h>

#define SQUARE(X) X*X

void main()
{
	int num = 7;
	
	// 정상적인 출력
	printf("square of num : %d\n", SQUARE(num));
	printf("square of 20 : %d\n", SQUARE(20));
	printf("square of -5 : %d\n", SQUARE(-5));
	
	// 비정상적인 출력
	printf("square of 3+5 : %d\n", SQUARE(3+5));
}