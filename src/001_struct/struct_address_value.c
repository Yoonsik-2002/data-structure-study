#include <stdio.h>

typedef struct {
	int ID;
	char Pass_Word[20];
}member;

int main()
{
	member example_member = {20211059, "asdfe1203"};
	member * pptr = &example_member;
	
	printf("구조체 변수 example_member의 주소값 : %p\n", pptr); // 구조체 포인터 변수 pptr이 가리키고 있는 구조체 변수 example_member의 주소값
	printf("구조체 변수 example_member의 첫 번째  멤버의 주소값 : %p\n", &pptr->ID); // 구조체 포인터 변수 pptr이 가리키고 있는 구조체 변수 example_member의 첫 번째 멤버 ID의 주소값
}