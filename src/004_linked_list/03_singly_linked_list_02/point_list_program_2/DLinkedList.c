#include <stdio.h>
#include <stdlib.h>

#include "DLinkedList.h"
#include "point.h"


/* 생성할 리스트의 초기화 */
void ListInit(List * plist) {
	plist -> head = (Node *)malloc(sizeof(Node)); // 유효한 데이터를 저장하고 있지 않는 Dummy Node를 생성
	plist -> head -> next = NULL;
	plist -> comp = NULL;
	plist -> numOfData = 0; // Dummy Node는 유효한 데이터를 저장하고 있지 않기 때문에, 데이터로 치지 않음 
}


/* 리스트에 노드 삽입(데이터 저장) */
void FInsert(List * plist , LData data) {
	Node * newNode = (Node *)malloc(sizeof(Node)); // 유효한 데이터를 저장하는 노드 생성
	newNode -> data = data; // 해당 노드에 데이터를 저장
	
	/* 노드의 삽입(정렬) 기준이 정해지지 않은 경우 새롭게 생성된 노드를 연결 리스트의 head(DummyNode)에 추가한다. */
	
	newNode -> next = plist -> head -> next; // 새롭게 생성된 노드가 DummyNode 바로 다음 노드를 가리키게 함. 
	plist -> head -> next = newNode; // DummyNode가 새롭게 생성된 노드를 가리키게 함.
	
	(plist -> numOfData)++;
}

void SInsert(List * plist, LData data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	Node * pred = plist -> head; // 먼저, pred는 기본적으로 dummy node부터 가리킴. 새 노드의 삽입은 pred가 가리키고 있는 노드 기준 오른쪽에 추가됨
	newNode -> data = data;
	
	while(pred -> next != NULL && plist -> comp(data, pred -> next -> data) != 0) {
		pred = pred -> next;
	}
	
	newNode -> next = pred -> next;
	pred -> next = newNode;
	
	(plist -> numOfData)++;
}

void LInsert(List * plist, LData data) {
	if(plist -> comp == NULL) { // 노드의 삽입(정렬) 기준이 정해지지 않은 경우
		FInsert(plist, data);
	}
	else {
		SInsert(plist, data);
	}
}


/* 리스트에 저장된 데이터의 탐색 및 조회 */
int LFirst(List * plist, LData * pdata) {
	if(plist -> head -> next == NULL) // 연결 리스트에 유효한 데이터를 저장하고 있는 첫 번째 노드가 존재하지 않는 경우(DummyNode 바로 다음 노드를 첫 번째 노드라 표현하겠음.)
		return FALSE;
	
	plist -> before = plist -> head; // 첫 번째 노드를 탐색하는데 있어, 구조체 포인터 before는 DummyNode를 가리킴
	plist -> cur = plist -> before -> next; // before를 통해, 현재 탐색한 노드를 가리키는 구조체 포인터 cur는 첫 번째 노드를 가리킴
	
	*pdata = plist -> cur -> data; // 탐색한 노드의 데이터를 반환
	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	if(plist -> cur -> next == NULL) // 연결 리스트의 노드를 순차적으로 탐색해내는데 있어, 현재 노드를 가리키는 cur의 다음 노드가 존재하지 않는 경우, 즉, 마지막 노드인 경우 
		return FALSE; 
	
	plist -> before = plist -> cur; // 첫 번째 노드 이후의 노드를 탐색하는데 있어, 구조체 포인터 before는 현재 cur이 가리키고 있는 노드를 가리킴
	plist -> cur = plist -> before -> next; // before를 통해, 기존 cur이 가리키던 노드의 다음 노드를 cur이 가리키게 됨
	
	*pdata = plist -> cur -> data;
	return TRUE;
}


/* 리스트에 저장되어 있는 데이터의 삭제 */ 
LData LRemove(List * plist, LData * pdata) {
	// 삭제하고자 하는 노드의 주소값과 데이터를 미리 저장
	Node * rpos = plist -> cur;
	LData rdata = rpos -> data;
	
	plist -> before -> next = plist -> cur -> next; 
	/* 삭제하고자 하는 노드(cur)의 이전 노드(before)가 삭제하고자 하는 노드(cur)의 다음 노드로 연결됨.
	cur의 이전 노드(before)가 cur을 건너뛰고 연결되기 때문에, cur이 자연스럽게 연결 리스트에서 연결이 끊기게 됨.*/
	
	plist -> cur = plist -> before; 
	/* 노드 삭제 후, cur이 before다음 노드를 가리키면 아직 탐색(참조)되지 않은 노드를 탐색해버린 꼴이
	되어버림. 때문에, 왼쪽으로 한칸 이동하여 before와 같은 노드를 가리킴*/ 
	
	free(rpos); // 노드(데이터)를 heap 메모리에서 완전히 소멸 시킴
	(plist -> numOfData)--; // 노드(데이터)를 삭제하였으니, 연결 리스트에 저장되어 있는 노드의 개수에서도 -1
    *pdata = rdata; // 삭제한 데이터값을 리턴
}


/* 리스트에 저장되어 있는 데이터의 개수를 반환 */
int LCount(List * plist) {
	return plist -> numOfData;
}

/* 연결 리스트의 정렬 기준이되는 함수를 연결 리스트 구조체에 등록 */
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2)) {
	plist -> comp = comp;
}

