#include <stdio.h>

int Fibo(int n) 
{
	if (n == 1) 
		return 0;
	else if(n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

void main()
{
	int length, i;
	printf("Enter the length of the sequence\n");
	scanf("%d", &length);
	
	printf("-----Fibonacci Sequence!-----\n");
	for(i = 1; i <= length; i++){
		printf("%d ", Fibo(i));
	}
	puts("");
}