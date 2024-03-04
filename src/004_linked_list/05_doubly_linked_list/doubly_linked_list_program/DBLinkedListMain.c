#include <stdio.h>
#include <stdlib.h>

#include "DBLinkedList.h"

void main() {
	Data data;
	List list; // 양방향 연결 리스트 생성
	
	/* 양방향 연결 리스트의 초기화 */
	ListInit(&list);
	
	/* 데이터 8개 저장(8개의 노드 삽입)*/
	// LInsert(&list, 1); LInsert(&list, 2);
	// LInsert(&list, 3); LInsert(&list, 4);
	// LInsert(&list, 5); LInsert(&list, 6);
	// LInsert(&list, 7); LInsert(&list, 8);
	for(int i = 1; i <= 8; i++) {
		LInsert(&list, i);
	}
	
	/* 데이터 탐색 및 출력 */
	if(LFirst(&list, &data)) {
		print(data);
		
		/* 데이터를 정방향으로 탐색 및 출력 */
		while(LNext(&list, &data)) {
			print(data);
		}
		
		/* 데이터를 역방향으로 탐색 및 출력 */
		while(LPrev(&list, &data)) {
			print(data);
		}
	}
}