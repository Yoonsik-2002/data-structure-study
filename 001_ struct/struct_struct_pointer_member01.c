#include <stdio.h>

typedef struct{
	int xpos;
	int ypos;
}spot;

typedef struct{
	spot * cen;
	double radius;
}circle;

int main()
{
	spot pos1 = {10, 17};
	double rad = 5.5;
	
	circle center = {&pos1, rad}; // circle 타입의 구조체 변수 center를 선언. 첫 번째 멤버인 spot 타입의 구조체 포인터 변수 cen에는 위에서 선언한 spot 타입의 구조체 변수 pos1이 대입된다. spot * cen = &pos1 
	
	printf("원의 반지름 : %g\n", center.radius);
	printf("원의 중심점의 좌표 : [%d, %d]\n", (center.cen)->xpos, (center.cen)->ypos); // center 라는 구조체 변수의 멤버인 spot 타입의 구조체 포인터 변수 cen이 가리키고 있는 구조체 변수 pos1의 멤버 xpos의 값 , ypos의 값 
}
