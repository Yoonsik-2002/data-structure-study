// 구조체 변수와 구조체 배열을 활용한 연락처 저장 프로그램

#include <stdio.h>

typedef struct {
	char name[20];
	int num;
}contact_number;

int main()
{
	contact_number person, phone_book[30];
	int i, pnum;
	
	printf("Input number of person : ");
	scanf("%d\n", &pnum);
	
	for (i = 0; i < pnum; i++) {
		printf("Input person name and number : ");
		scanf("%s %d\n", phone_book[i].name, &phone_book[i].num);
	}
	
	printf("--Your contact number list--");
	puts("");
	for (i = 0; i < pnum; i++) {
		printf("Name : %s -- Phone number : %d\n", phone_book[i].name, phone_book[i].num);
	}
	puts("");
	printf("-----------------------------\n");
}