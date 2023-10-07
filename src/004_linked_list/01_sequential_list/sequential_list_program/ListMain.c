#include <stdio.h>
#include "ArrayList.h"

int main(void) 
{
	// ArrayList의 생성 및 초기화
	List list;  // 리스트의 생성
	int data;
	ListInit(&list);  // 리스트의 초기화 - 그저 데이터만 담기는 것이 아니라, 해당 데이터를 효율적으로 저장 및 참조하는데 쓰이는 데이터까지 초기환
	
	// 5개의 데이터를 저장
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);
	
	// 저장된 데이터의 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));
	
	if(LFirst(&list, &data))  // 첫 번째 데이터 조회
	{
		printf("%d", data);
		
		while(LNext(&list, &data))  // 두 번째 이후의 데이터 조회
			printf("%d ", data);
	}
	printf("\n\n");
	
	// 숫자 22를 탐색하여 모두 삭제
	if(LFirst(&list, &data))
	{ 
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22) 
				LRemove(&list);
		}
	}
	
	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터 수 : %d \n", Lcount(&list));
	
	if(LFirst(&list, data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d", data);
	}
	printf("\n\n");
	return 0;
}