// call-by-reference 형태의 함수 호출을 이용하여 x, y좌표값을 원점대칭 이동시키는 프로그램 
#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}point;

void exchange_coordinate(point * pptr) { // 구조체 포인터 변수 형태로 선언된 매개 변수 pptr. 이를 통해 call-by-reference 형태의 함수호출이 가능해지고, 함수 내에서 함수 밖에 선언된 변수에 접근이 가능하게 된다. 
	printf("pos1의 x,y 좌표의 원점 대칭 이동 수행중 ...\n");
	pptr->xpos = (pptr->xpos) * -1; // (*pptr.xpos) * -1 과 같은 의미
	pptr->ypos = (pptr->ypos) * -1; // (*pptr.ypos) * -1 과 같은 의미
	printf("수행 완료 !\n");
	puts("");
}

void restoration(point pos1) {
	printf("좌표의 이동을 다시 원상 복구하겠습니다.\n");
	exchange_coordinate(&pos1);
	printf("원상 복구된 pos1의 x, y 좌표 : [%d, %d]\n", pos1.xpos, pos1.ypos);
}

int main()
{
	point pos1 = {-7, 5};
	printf("pos1의 x, y 좌표 : [%d, %d]\n", pos1.xpos, pos1.ypos);
	puts("");
	exchange_coordinate(&pos1);
	printf("원점 대칭이동 된 pos1의 x, y 좌표 : [%d, %d]\n", pos1.xpos, pos1.ypos);
	puts("");
	restoration(pos1);
}