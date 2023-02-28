#include <stdio.h>

typedef struct {
	char serialNum[20];
	char name[20];
	int degree;
}soldier;

int main()
{
	soldier s1 = {"23-76004321", "Cho Yoonsik", 3};
	soldier s2 = {"22-76001234", "Kin Daeyeon", 1};
	soldier s3 = {"22-76001111", "Sung Minjae", 2};
	
	printf("--Serial Number of %s--\n %s\n", s1.name, s1.serialNum );
	printf("--------------------------------\n");
}