#include <stdio.h>
#include <stdlib.h>

#include "DBDLinkedList.h"

void main() {
	Data data;
	List list;
	
	/* 리스트의 초기화 */
	ListInit(&list);
	
	/* 리스트에 데이터 삽입 */
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);
	
	/* 리스트에 저장된 데이터 출력 - 정방향, 역방향 */
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		/* 정방향으로 데이터 출력 */
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
		
		/* 역방향으로 데이터 출력 */
		while(LPrev(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	/* 짝수 데이터를 지닌 노드를 연결 리스트에서 삭제 */
	if(LFirst(&list, &data)) {
		if(data % 2 == 0) 
			LRemove(&list);
		
		while(LNext(&list, &data)) {
			if(data % 2 == 0) 
				LRemove(&list);
		}
	}
	
	/* 데이터 삭제 후, 리스트의 남아있는 데이터를 출력 */
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
}