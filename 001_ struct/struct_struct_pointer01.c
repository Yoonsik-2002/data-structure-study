#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}spot;

int main()
{
	spot pos1 = {10, 11};
	spot pos2 = {100, 101};
	
	spot * pptr = &pos1;
	(*pptr).xpos += 5;
	(*pptr).ypos += 5;
	printf("[%d, %d]\n", pptr->xpos, pptr->ypos);
	
	pptr = &pos2;
	pptr->xpos += 5;
	pptr->ypos += 5;
	printf("[%d, %d]\n", (*pptr).xpos, (*pptr).ypos);
}