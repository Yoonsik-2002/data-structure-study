#include <stdio.h>
#include <stdlib.h>

#include "DLinkedList.h"

/* 으로 노드를 삽입하여 정렬하게 하는 함수 - WhoIsPrecede */
int WhoIsPrecede(LData d1, LData d2) {
	if(d1 > d2) 
		return 0;
	else 
		return 1;
}

void main()
{
	List list;
	LData data;
	
	
	/* 리스트의 생성 및 초기화 */
	ListInit(&list);
	
	/* 연결 리스트의 정렬 기준을 나타내는 함수를 등록 */
	SetSortRule(&list, WhoIsPrecede); // C언어에서 함수의 이름은 배열의 이름과 마찬가지로 함수의 시작주소를 나타내는 포인터 상수로 간주된다.
	
	/* 5개의 데이터를 저장 */
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);
	
	
	/* 저장된 데이터의 전체 출력 */
	printf("[full output of stored data]\n");
	printf("----------------------------\n");
	printf("number of data : %d\n", LCount(&list));
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");
	
	
	/* 숫자 22를 탐색하여 모두 삭제 */
	printf("[explore the number 22 to delete all]\n");
	printf("-------------------------------------\n");
	
	if(LFirst(&list, &data)) {
		if(data == 22) {
			LRemove(&list, &data);
			printf("deletion complelted : %d\n", data);
		}
		
		while(LNext(&list, &data)) {
			if(data == 22) {
				LRemove(&list, &data);
				printf("deletion complelted : %d\n", data);
			}
		}
	}
	printf("\n\n");
	
	
	/* 삭제 후 남은 데이터 전체 출력 */
	printf("[full output data remaining after deletion]\n");
	printf("-------------------------------------------\n");
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");
}