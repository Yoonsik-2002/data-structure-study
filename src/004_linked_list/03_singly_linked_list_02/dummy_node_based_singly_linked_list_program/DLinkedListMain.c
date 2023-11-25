#include <stdio.h>
#include <stdlib.h>

#include "DLinkedList.h"

void main()
{
	List list;
	LData data;
	
	
	/* 리스트의 생성 및 초기화 */
	ListInit(&list);
	
	
	/* 5개의 데이터를 저장 */
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);
	
	
	/* 저장된 데이터의 전체 출력 */
	printf("[full output of stored data]\n");
	printf("---------------------------\n");
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