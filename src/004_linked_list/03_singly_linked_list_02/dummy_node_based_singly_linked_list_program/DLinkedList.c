#include <stdio.h>
#include <stdlib.h>

#include "DLinkedList.h"


/* 생성할 리스트의 초기화 */
void ListInit(List * plist) {
	plist -> head = (*Node)malloc(sizeof(Node)); // 유효한 데이터를 저장하고 있지 않는 Dummy Node를 생성
	plist -> head -> next = Null;
	plist -> comp = NULL;
	plist -> numOfData = 0; // Dummy Node는 유효한 데이터를 저장하고 있지 않기 때문에, 데이터로 치지 않음 
}


/* 리스트에 노드 삽입(데이터 저장) */

void FInsert(List * plist , LData data) {
	Node * newNode = (*Node)malloc(sizeof(Node)); // 유효한 데이터를 저장하는 노드 생성
	newNode -> data = data; // 해당 노드에 데이터를 저장
	
	// 노드의 삽입(정렬) 기준이 정해지지 않은 경우 새롭게 생성된 노드를 연결 리스트의 head(DummyNode)에 추가한다.
	
	newNode -> next = plist -> head -> next; // 새롭게 생성된 노드가 DummyNode 바로 다음 노드를 가리키게 함. 
	plist -> head -> next = newNode; // DummyNode가 새롭게 생성된 노드를 가리키게 함.
}

/* void SInsert(List * plist , Ldata data) {
	// ...
} */ 

void LInsert(List * plist, LData data) {
	if(plist -> comp == NULL) { // 노드의 삽입(정렬) 기준이 정해지지 않은 경우
		FInsert(plist, data);
	}
	else {
		SInsert(plist , data); // 노드의 삽입(정렬) 기준이 정해진 경우
	}
}


/* 리스트에 저장된 데이터의 탐색 및 조회 */
int LFirst(List * plsit, LData * pdata) {
	if(plist -> head -> next == NULL) // 연결 리스트에 유효한 데이터를 저장하고 있는 첫 번째 노드가 존재하지 않는 경우(DummyNode 바로 다음 노드를 첫 번째 노드라 표현하겠음.)
		return FALSE;
	
	plist -> before = plist -> head; // 첫 번째 노드를 탐색하는데 있어, 구조체 포인터 before는 DummyNode를 가리킴
	plist -> cur = plist -> before -> next; // before를 통해, 현재 탐색한 노드를 가리키는 구조체 포인터 cur는 첫 번째 노드를 가리킴
	
	*pdata = plist -> cur -> data; // 탐색한 노드의 데이터를 반환
	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	if(plist -> cur -> next == NULL);
	
}
