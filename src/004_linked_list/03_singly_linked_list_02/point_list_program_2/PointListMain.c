#include <stdio.h>
#include <stdlib.h>

#include "point.h"
#include "DLinkedList.h"

int main(void) 
{
	List list;  // list 구조체 변수 생성
	Point compPos;
	LData ppos; // Point 타입의 구조체를 가리키는 구조체 포인터 변수 ppos
	
	ListInit(&list); // 연결 리스트를 나타내는 구조체 List의 변수, list의 멤버들을 기본초기값으로 초기화
	
	// 1) 4개의 데이터 저장
	ppos = (Point*)malloc(sizeof(Point)); 
	SetPointPos(ppos, 2, 1); // heap에 생성된 첫 번째 구조체의 멤버 xpos, ypos를 각각 2, 1로 초기화
	LInsert(&list, ppos); // 해당 구조체의 주소값(ppos)을 list의 Point * 타입(typedef Point * LData) 배열형태의 저장공간 arr에 저장.
	
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
		
		while(LNext(&list, &ppos)) 
			ShowPointPos(ppos); // 두 번째로 저장되어 있는 데이터를 하나하나씩 넘어가면서 출력해줌 탐색 -> 반환(*pdata(ppos) = plist -> arr[plist -> curPosittion])
	}
	printf("\n");
	
	// 3) xpos값이 2인 모든 데이터 삭제 
	compPos.xpos = 2;
	compPos.ypos = 0; 
	
	if(LFirst(&list, &ppos)) // 연결 리스트의 유효한 데이터를 저장하는 첫 번째 노드를 탐색하여 해당 노드가 저장하고 있는 데이터(Point 구조체 변수).를 매개변수로 전달받은 ppos에 반환 
	{
		if(PointComp(ppos, &compPos) == 1) // ppos가 가리키고 있는 구조체의 멤버xpos의 값이 2인 경우 LRemove함수와 free함수를 통해 해당 구조체를 삭제
		{
			ppos = LRemove(&list); 
			free(ppos);
		}
		
		while(LNext(&list, &ppos)) 
		{
			if(PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}
	
	// 4) 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));
	
	if(LFirst(&list, &ppos)) 
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	printf("\n");
	
	return 0;
	
}