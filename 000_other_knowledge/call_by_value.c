/* call-by-value 는 함수 호출 시, 단순히 값을 전달하는 형태의 함수 호출을 의미한다. 단순한 일반 값을 함수의 인자로서 매개변수에 전달 할 경우, 
값이 복사되어 전달되기 때문에 call by value 형태의 함수에서는 함수 외부에 선언된 변수에 접근이 불가능 하다.*/

#include <stdio.h>

void swap(int n1, int n2){
	int temp = n1;
	n1 = n2;
	n2 = temp;
	
	printf("n1 n2 : %d %d\n", n1, n2);
}

void main()
{
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2 : %d %d\n", num1, num2);
	
	swap(num1, num2);
	
	printf("num1 num2 : %d %d\n", num1, num2);
}