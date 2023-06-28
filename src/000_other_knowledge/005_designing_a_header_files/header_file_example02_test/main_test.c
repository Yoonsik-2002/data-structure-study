#include <stdio.h>
#include "basicArith_copy0.h"

int main(void)
{
	double num = Add(1.5, 2.3); // undefined reference to `Add' - 해당 함수가 헤더파일에 선언은 되어 있으나, 소스파일에는 선언이 되어있지 않을 경우 일어남
	
	printf("%g", num);
	
	return 0;
}