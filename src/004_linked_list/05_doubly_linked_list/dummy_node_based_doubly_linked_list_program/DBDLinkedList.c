#include <stdio.h>
#include <stdlib.h>

#include "DBDLinkedList.h"

/* Dummy node 기반의 양방향 연결 리스트의 초기화 - ListInit */
void ListInit(List * pList) {
	Node * HDMN = (Node *)malloc(sizeof(Node));
	Node * TDMN = (Node *)malloc(sizeof(Node));
	
	pList -> head = HDMN;
	pList -> tail = TDMN;
	
	pList -> head -> prev = NULL;
	pList -> tail -> next = NULL;
	
	pList -> head -> next = pList -> tail;
	pList -> tail -> prev = pList -> head;
	
	pList -> numOfData = 0;
}

/* 노드 삽입 - LInsert */
void LInsert(List * pList, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;
	
	/* newNode를 pList -> tail이 가리키고 있는 (마지막)노드와 서로 연결 */
	pList -> tail -> prev -> next = newNode;
	newNode -> prev = pList -> tail -> prev;
	
	/* newNode를 pList -> tail과 연결 */
	newNode -> next = pList -> tail;
	pList -> tail -> prev = newNode;
	
	(pList -> numOfData)++;
}

/* cur의 위치를 탐색 전, 초기상태로 초기화 - LFirst */
int LFirst(List * pList, Data * pData) {
	if(pList -> tail -> prev == pList -> head) {
		return FALSE;
	}
	
	pList -> cur = pList -> tail -> prev;
	*pData = pList -> cur -> data;
	
	return TRUE;
}

/* 첫 번째 노드부터 마지막 노드까지 순서대로 탐색 - LNext */
int LNext(List * pList, Data * pData) {
	if(pList -> cur -> next -> next == NULL) {
		return FALSE;
	}
	
	pList -> cur = pList -> cur -> next;
	*pData = pList -> cur -> data;
	
	return TRUE;
}

/* LNext의 역방향으로 노드를 탐색 - LPrev */
int LPrev(List * pList, Data * pData) {
	if(pList -> cur -> prev -> prev == NULL) {
		return FALSE;
	}
	
	pList -> cur = pList -> cur -> prev;
	*pData = pList -> cur -> data;
	
	return TRUE;
}

/* 노드 삭제 - LRemove */
Data LRemove(List * pList) {
	Node * rpos = pList -> cur;
	Data rdata = rpos -> data;
	
	pList -> cur -> next -> prev = pList -> cur -> prev;
	pList -> cur -> prev -> next = pList -> cur -> next;
	
	pList -> cur = pList -> cur -> next;
	
	free(rpos);
	
	(pList -> numOfData)--;
	
	return rdata;
}

/* 노드의 개수 출력 - LCount */
int LCount(List * pList) {
	return pList -> numOfData;
}