#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "ArrayList.h"

int main(void) {
	List list;  // list 구조체 변수 생성
	Point compPos;
	Point * ppos; // Point 타입의 구조체를 가리키는 구조체 포인터 변수 ppos
	
	ListInit(*list); // list 구조체의 멤버들의 값을 초기값으로 초기화
	
	// 1) 4개의 데이터 저장
	ppos = (Point*)malloc(sizeof(Point)); 
	/* 
	Point 구조체 만큼의 크기를 가진 메모리 공간을 자유 메모리(Heap)에 할당. 
	해당 메모리 공간을 이루는 첫 번째 바이트의 주소값을 반환하여 Point타입의 구조체 포인터 변수
	ppos에 저장
	*/
	SetPointPos(ppos, 2, 1); // heap에 생성된 첫 번째 구조체의 멤버 xpos, ypos를 각각 2, 1로 초기화
	LInsert(&list, ppos); // 해당 구조체의 주소값(ppos)을 list의 Point타입(LData) 배열형태의 저장공간 arr에 저장.
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 3);
	LInsert(&list, ppos);
	
	// 2) 저장된 데이터의 출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));
	
	if(LFirst(&list, &ppos)) 
	{
		ShowPointPos(ppos); // 구조체 포인터 변수 ppos가 가리키고 있는 첫 번째 데이터를 출력해줌
		
		while(LNext(&jlist, &ppos)) 
			ShowPointPos(ppos); // 두 번째로 저장되어 있는 데이터를 하나하나씩 넘어가면서 출력해줌 탐색 -> 반환(*pdata(ppos) = plist -> arr[plist -> curPosittion])
	}
	printf("\n");
	
}