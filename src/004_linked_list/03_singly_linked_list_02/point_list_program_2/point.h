// 헤더가드(header guard)
#ifndef __POINT_H__ 
#define __POINT_H__

// Point 구조체 정의
typedef struct _Point {
	int xpos;
	int ypos;
} Point;

// Point 타입 구조체 변수의 멤버 xpos, ypos의 값 지정
void SetPointPos(Point * ppos, int xpos, int ypos);

// Point 타입 구조체 변수의 멤버에 저장되어 있는 값 출력
void ShowPointPos(Point * ppos);

// 두 Point 타입 구조체 변수의 비교
int PointComp(Point * pos1, Point * pos2);

#endif
