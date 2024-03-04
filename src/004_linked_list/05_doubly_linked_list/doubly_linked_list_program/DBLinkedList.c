#include <stdio.h>
#include <stdlib.h>

#include "DBLinkedList.h"

/* 양방향 연결 리스트의 초기화 - ListInit */
void ListInit(List * pList) {
	pList -> head = NULL;
	pList -> numOfData = 0;
}

/* 노드 삽입 - LInsert */
void LInsert(List * pList, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;
	
	if(pList -> head != NULL) {
		pList -> head -> prev = newNode;
	}
	
	newNode -> next = pList -> head;
	newNode -> prev = NULL;
	pList -> head = newNode;
	
	(pList -> numOfData)++;
}

/* 첫 번째 노드를 탐색 - LFirst */
int LFirst(List * pList, Data * pData) {
	if(pList -> head == NULL) {
		return FALSE;
	}
	
	pList -> cur = pList -> head;
	*pData = pList -> cur -> data;
	
	return TRUE;
}

/* 첫 번 노드 이후 노드를 탐색 - LNext */
int LNext(List * pList, Data * pData) {
	if(pList -> cur -> next == NULL) {
		return FALSE;
	}
	
	pList -> cur = pList -> cur -> next;
	*pData = pList -> cur -> data;
	
	return TRUE;
}

/* LNext의 역방향으로 노드를 탐색 - LPrev */
int LPrev(List * pList, Data * pData) {
	if(pList -> cur -> prev == NULL) {
		return FALSE;
	}
	
	pList -> cur = pList -> cur -> prev;
	*pData = pList -> cur -> data;
	
	return TRUE;
}
