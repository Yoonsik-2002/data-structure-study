#include <stdio.h>
#include <stdlib.h>

#include "DLinkedList.h"

void main()
{
	List list;
	LData data;
	
	
	/* 리스트의 생성 및 초기화 */
	ListInit(&list, &data);
	
	
	/* 5개의 데이터 저장 */
 	LInsert(&list, 11); LInsert(&List, 11);
	LInsert(&list, 22); LInsert(&List, 22);
	LInsert(&list, 33);
	
	/* 저장된 데이터의 전체 출력 */
	printf("Number of data : %d\n", list -> numOfData);
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
	}
	else {
		while(1) {
			LNext(&list, &data);
			printf("%d", data);
		}
	}
	printf("\n\n");
	
	/* 숫자 22를 탐색하여 모두 삭제 */
	printf("[navigating and deleting the number 22]\n");
	printf("---------------------------------------\n");
	
	if(LFirst(&list, &data)) {
		if(data == 22) {
			LRemove(&list, &data);
			printf("delete %d\n", data);
		}
	}
	else {
		while(1) {
			LNext(&list, &data);
			LRemove(&list, &data);
			printf("delete %d\n", data);
		}
	}
	pritnf("\n\n");
	
	
	/* 삭제 후 남은 데이터 전체 출력 */
	printf("[total data remaining after deletion]\n");
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
	}
	else {
		while(1) {
			printf("%d ", data);
		}
	}
}