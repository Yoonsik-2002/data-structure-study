#include <stdio.h>

struct spot{
	int xpos;
	int ypos;
	struct spot * pptr;
};

int main()
{
	struct spot pos1 = {1, 1};
	struct spot pos2 = {2, 2};
	struct spot pos3 = {3, 1};
	
	// pos1과 pos2 연결
	pos1.pptr = &pos2;
	
	// pos2와 pos3 연결
	pos2.pptr = &pos3;
	
	// pos3와 pos1 연결
	pos3.pptr = &pos1;
	
	printf("--연결 관계--");
	puts("");
	printf("[%d, %d] 와 [%d, %d] 연결\n", pos1.xpos, pos1.ypos, pos1.pptr->xpos, pos1.pptr->ypos);
	printf("[%d, %d] 와 [%d, %d] 연결\n", pos2.xpos, pos2.ypos, pos2.pptr->xpos, pos2.pptr->ypos);
	printf("[%d, %d] 와 [%d, %d] 연결\n", pos3.xpos, pos3.ypos, pos3.pptr->xpos, pos3.pptr->ypos);
}