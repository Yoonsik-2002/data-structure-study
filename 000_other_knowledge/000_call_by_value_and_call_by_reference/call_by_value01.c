#include <stdio.h>

void exfunc(int n) {
	printf("매개변수 n에 저장된 값 : %d\n", n);
	printf("매개변수 n의 주소값 : %p\n", &n);
}

int main()
{
	int n = 10;
	printf("변수 n에 저장된 값 : %d\n", n);
	printf("변수 n의 주소값 : %p\n", &n);
	puts("");
	
	exfunc(n);
}