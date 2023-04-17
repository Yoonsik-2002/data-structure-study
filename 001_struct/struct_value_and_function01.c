#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}spot;

spot current_coordinate(void) {
	spot cen;
	printf("Input coordinate of spot : ");
	scanf("%d %d", &cen.xpos, &cen.ypos);
	return cen; // spot 타입의 구조체 변수 cen에 값 저장 후, 반환(return)
}

void show_coordinate(spot pos) {
	printf("[%d, %d]\n", pos.xpos, pos.ypos);
}

int main()
{
	spot cur_spot = current_coordinate(); // current_coordinate 함수 실행 후, 리턴되는 구조체 변수 cen에 저장되어 있는 값이 cur_spot에 나란히 복사되어 저장된다. 
	show_coordinate(cur_spot); // spot 타입의 구조체 변수 cur_spot가 show_coordinate 함수에 인자로 전달된다. 이때, cur_spot 에 저장되어 있는 값이 나란히 복사되어 매개변수 pos 에 저장된다. 
}