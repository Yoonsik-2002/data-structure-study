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
int LNext(List * pList, Data * pData) {
	if(pList -> tail == NULL) {
		return FALSE;
	}
	
	pList -> before = pList -> cur;
	pList -> cur = pList -> before -> next;
	
	*pData = pList -> cur -> data;
	
	return TRUE;
}

/* 원형 연결 리스트의 노드 삭제 - LRemove */
Data LRemove(List * pList) {
	Node * rpos = pList -> cur;
	Data rdata = rpos -> data;
	
	if(pList -> tail == rpos) {
		if(pList -> tail -> next = pList-> tail) {
			pList -> tail = NULL;
		}
		
		else {
			pList -> tail = pList -> before;
		}
	}
	
	pList -> before -> next = pList -> cur -> next;
	pList -> cur = pList -> before;
	
	free(rpos);
	(pList -> numOfData)--;
	return rdata;
}

/* 원형 연결 리스트의 데이터 개수를 반환 - LCount */
int LCount(List * pList) {
	return pList -> numOfData;
}