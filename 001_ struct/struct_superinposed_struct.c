#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}point;

typedef struct {
	point cen; // circle 구조체 안에 해당 구조체의 멤버로 point 구조체 변수가 선언 되었다. 이렇게 구조체 안에 구조체 변수가 멤버로 존재하는 경우를 구조체의 중첩이라고 한다.
	float rad;
}circle;

void show_circle_info(circle * ptr) { 
	printf("[%d, %d]\n", (ptr->cen).xpos, (ptr->cen).ypos);
	printf("%.2f\n", ptr->rad);
}

int main()
{
	circle c1 = {{10, 20}, 4.5};
	circle c2 = {20, 40, 3.9};
	
	show_circle_info(&c1);
	puts("");
	show_circle_info(&c2);
}