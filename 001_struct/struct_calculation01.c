#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}point;

point add_point(point pos1, point pos2);
point min_point(point pos1, point pos2);

int main()
{
	point pos1 = {10, 20};
	point pos2 = {30, 40};
	
	point result;
	
	result = add_point(pos1, pos2);
	printf("add_point 의 계산 결과 : [%d, %d]\n", result.xpos, result.ypos);
	
	result = min_point(pos1, pos2);
	printf("min_point 의 계산 결과 : [%d, %d]\n", result.xpos, result.ypos);
}

point add_point(point pos1, point pos2){
	point pos = {pos1.xpos + pos2.xpos, pos1.xpos + pos2.ypos};
	return pos;
}

point min_point(point pos1, point pos2){
	point pos = {pos2.xpos - pos1.xpos, pos2.xpos - pos1.ypos};
	return pos;
}