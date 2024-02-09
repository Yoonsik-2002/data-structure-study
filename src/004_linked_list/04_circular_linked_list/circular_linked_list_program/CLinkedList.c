#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

/* 원형 연결 리스트의 초기화 - ListInit */
void ListInit(List * pList) {
	pList -> tail = NULL;
	pList -> cur = NULL;
	pList -> before = NULL;
	pList -> numOfData = 0;
}

/* 원형 연결 리스트의 머리에 새 노드를 삽입 - LInsertFront */ 
void LInsertFront(List * pList, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;
	
	if(pList -> tail == NULL) {
		pList -> tail = newNode;
		newNode -> next = newNode;
	}
	
	else {
		newNode -> next = pList -> tail -> next;
		pList -> tail -> next = newNode;
	}
	
	(pList -> numOfData)++;
}

/* 원형 연결 리스트의 꼬리에 새 노드를 삽입 - LInsert */
void LInsert(List * pList , Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;
	
	if(pList -> tail == NULL) {
		pList -> tail = newNode;
		newNode -> next = newNode;
	}
	
	else {
		newNode -> next = pList -> tail -> next;
		pList -> tail -> next = newNode;
		pList -> tail = newNode;
	}
	
	(pList -> numOfData)++;
}

/* 원형 연결 리스트의 첫 번쨰 노드를 조회 - LFIrst */
int LFirst(List * pList, Data * pData) {
	if(pList -> tail == NULL) {
		return FALSE;
	}
	
	pList -> before = pList -> tail;
	pList -> cur = pList -> tail -> next;
	
	*pData  = pList -> cur -> data;
	
	return TRUE;
}

/* 원형 연결 리스트의 첫 번쨰 이후 노드를 조회 - LNext */
int LNext(List * pList, Dtat * pData) {
	if(pList -> tail == NULL) {
		return FALSE;
	}
	
	pList -> before = pList -> cur;
	pList -> cur = pList -> before -> next;
	
	*pData = pLIst -> cur -> data;
	
	return TRUE;
}




