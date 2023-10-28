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
void PointComp(Point * pos1, Point * pos2);

#endif


/*
#ifndef, #define - header guard

#if(#ifndef, #ifdef)문 뒤에는 반드시 #endif문이 등장해야 하며, 이 두 지시자 사이에 존재하는 코드는 
조건에 따라 삽입 및 삭제가 된다.

#ifndef ... #endif(정의되지 않았다면)의 경우, 조건이 되는 매크로가 정의되어있느냐, 아니냐에 따라서
두 지시자 사이에 있는 코드를 삽입 혹은 삭제 한다.
(조건이 되는 매크로가 정의되어 있지 않은 경우 삽입, 정의되어 있는 경우엔 삭제)

해당 헤더파일 의 경우, 조건이 되는 매크로 __POINT_H__가 정의되어 있지 않은 경우 #ifndef ... #endif
두 지시자 사이의 코드를 삽입하고, 정의 되어 있는 경우에는 삭제하여, 헤더파일의 중복을 방지한다.

이러한 헤더파일의 중복을 방지하는 지시자 #ifndef, #define을 두고, header guard라고도 한다.
*/

/* 헤더파일 작성 시, 주의할 점 

"만들고자 하는 헤더파일의 이름과 해당 헤더파일과 대응되는 소스파일 (헤더파일에 선언된 함수들을 정의 해놓은 소스파일)의 이름이 같아야 한다."
헤더파일과 그 헤더파일과 대응되는 소스파일의 이름이 같아야 컴파일러가 인식할 수 있기 때문이다.

해당 헤더파일의 경우, 해당 헤더파일에 선언해 둔 함수들(SetPointPos, ShowPointPos, PointComp)을 정의해놓은 소스파일 Point.c와 이름이
같도록 Point(.h)로 이름을 정해 주었다. 
*/

