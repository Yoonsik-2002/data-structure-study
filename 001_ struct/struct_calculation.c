#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}spot;

int main()
{
	spot pos1 = {10, 12};
	// 구조체 변수의 대입 연산
	spot pos2 = pos1;
	
	printf("구조체 변수 pos1의 크기 : %ld\n", sizeof(pos1)); // 구조체 변수의 크기를 반환하는 sizeof 연산
	printf("[%d, %d]\n", pos1.xpos, pos1.ypos);
	puts("");
	printf("구조체 변수 pos2의 크기 : %ld\n", sizeof(pos2));
	printf("[%d, %d]\n", pos2.xpos, pos2.ypos);
}