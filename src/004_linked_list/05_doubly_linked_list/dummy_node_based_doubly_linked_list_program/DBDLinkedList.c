#include <stdio.h>
#include <stdlib.h>

#include "DBDLinkedList.h"

/* Dummy node 기반의 양방향 연결 리스트의 초기화 - ListInit */
void ListInit(List * pList) {
	Node * HDMN = (Node *)malloc(sizeof(Node));
	HDMN -> data = NULL;
	Node * TDMN = (Node *)malloc(sizeof(Node));
	TDMN -> data = NULL;
	
	pList -> head = HDMN;
	pList -> tail = TDMN;
	
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
}

/* cur의 위치를 탐색 전, 초기상태로 초기화 - LFirst */
int LFirst(List * pList) {
	if((pList -> tail -> prev == pList -> head) && (pList -> head -> next == pList -> tail)) {
		return False;
	}
	
	pList -> cur = pList -> tail;
	
	return TRUE;
}

/* 첫 번째 노드 부터, 마지막 노드까지 탐색  - LNext */
int LNext(List * pList, Data * pData) {
	if(pList -> cur -> next -> data == NULL) {
		return FALSE;
	}
	
	pList -> cur = pList -> cur -> next;
	*pData = pList -> cur -> data;
	
	return TRUE;
}