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