#include <stdio.h>

int Fibo(int num) 
{
	if (num == 1) 
		return 0;
	else if(num == 2)
		return 1;
	else
		return Fibo(num - 1) + Fibo(num - 2);
}

void main()
{
	int n, i;
	printf("Enter the length of the sequence\n");
	scanf("%d", &n);
	
	printf("-----Fibonacci Sequence!-----\n");
	for(i = 1; i <= n; i++){
		printf("%d ", Fibo(i));
	}
	puts("");
}