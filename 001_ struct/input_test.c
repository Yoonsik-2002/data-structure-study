#include <stdio.h>

int main()
{
	// 공백까지 포함하여 문자열 배열에 입력받기 
	char name[20];
	
	printf("input name : ");
	scanf("%[^\n]s", name);
	
	printf("%s", name);
}