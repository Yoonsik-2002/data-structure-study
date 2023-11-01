#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "ArrayList.h"

int main(void) 
{
	List list;  // list 구조체 변수 생성
	Point compPos;
	Point * ppos; // Point 타입의 구조체를 가리키는 구조체 포인터 변수 ppos
	
	ListInit(&list); // list 구조체의 멤버들의 값을 초기값으로 초기화
	
	// 1) 4개의 데이터 저장
	ppos = (Point*)malloc(sizeof(Point)); 
	/* 
	Point 구조체 만큼의 크기를 가진 메모리 공간을 자유 메모리(Heap)에 할당. 
	해당 메모리 공간을 이루는 첫 번째 바이트의 주소값을 반환하여 Point * 타입의 구조체 포인터 변수
	ppos에 저장
	*/
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
	
	if(LFirst(&list, &ppos)) // arr에 첫 번째 인덱스에 존재하는 구조체의 주소값을 탐색하여 구조체 포인터 변수 ppos가 가리키게 함.(이때 curPositonr값은 0)
	{
		if(PointComp(ppos, &compPos) == 1) // ppos가 가리키고 있는 구조체의 멤버xpos의 값이 2인 경우 LRemove함수와 free함수를 통해 해당 구조체를 삭제
		{
			ppos = LRemove(&list); 
			/*
			LRemove를 통해, arr에서 ppos가 저장하고 있는 주소값을 삭제, 삭제가 이루어지기 전,
			해당 함수의 지역변수 rdata에 해당 주소값이 저장되고, ppos는 rdata값을 리턴받아, 해당
			값을 가지고, free함수를 호출하여 Heap메모리에서까지 완전히 삭제
			
			arr에서 탐색한 구조체 데이터(구조체의 주소값)을 삭제해준 뒤, Heap영역에서도 해당 구조체 주소값에
			해당하는 구조체 메모리를 해제해 주어야한다.
			
			해당 작업을 위해, LRemove 함수는 삭제한 구조체 데이터(구조체의 주소값)을 지역변수 rdata에 저장시켜
			해당 rdata값을 구조체 포인터변수 ppos에 리턴해준다.
			*/
			
			free(ppos); // ppos가 주소값을 저장하고 있는 구조체를 Heap영역에서까지 완전히 삭제
			
			/*
			LFirst 함수에서 탐색해낸 list -> arr[0] 에 저장되어 있는 구조체 주소값에 해당되는 구조체의 멤버 xpos가
			2를 저장하고 있는 경우, 해당 구조체를 삭제하는 과정인 것이다!
			*/
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