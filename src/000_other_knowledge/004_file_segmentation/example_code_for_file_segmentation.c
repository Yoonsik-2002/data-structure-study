#include <stdio.h>

int num = 0;

void increment(void){
	num ++;
}

int get_num(void){
	return num;
}

int main()
{
	printf("Num : %d\n", get_num());
	increment();
	printf("Num : %d\n", get_num());
	increment();
	printf("Num : %d\n", get_num());
	increment();
}