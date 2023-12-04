#include <stdio.h>
#include "point.h"

/* Point 구조체 변수의 멤버 xpos, ypos값을 초기화 */
void SetPointPos(Point * ppos, int xpos, int ypos) 
{
	ppos -> xpos = xpos;
	ppos -> ypos = ypos;
}

/* 인자로 전달받은 Point 구조체 변수의 멤버 xpos, ypos값을 출력 */
void ShowPointPos(Point * ppos) 
{
	printf("[%d, %d]\n", ppos -> xpos, ppos -> ypos);
}

/* Point 구조체 변수의 xpos, ypos값을 서로 비교 */
int PointComp(Point * pos1, Point * pos2) 
{
	if(pos1 -> xpos == pos2 -> xpos && pos1 -> ypos == pos2 -> ypos) 
		return 0;
	
	else if(pos1 -> xpos == pos2 -> xpos) 
	{
		return 1;
	}
	
	else if(pos1 -> ypos == pos2 -> ypos) 
	{
		return 2;
	}
	
	else
		return -1;
}