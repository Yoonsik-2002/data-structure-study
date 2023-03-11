/* call-by-reference 는 함수 호출 시, 참조할 수 있는 값의 주소값을 전달하는 형태의 함수 호출을 의미한다. 참조 할 값의 주소값을 전달해주는 경우엔 값이 복사되는 경우와는 달리, 
그 값 자체를 지칭하는 주소값이 전달되는 것이기 때문에 call-by-reference 형태의 함수에서는 함수 외부에 선언된 변수에 접근이 가능하다.*/

#include <stdio.h>
void swap(int * n1, int * n2) {
	int temp = *n1;
	*n1  = *n2;
	*n2 = temp;
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2 : %d %d\n", num1, num2);
	
	swap(&num1, &num2);
	
	printf("num1 num2 : %d %d\n", num1, num2);
}