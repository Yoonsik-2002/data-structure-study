#include <stdio.h>
#include <stdlib.h>

#include "ListBaseStack.h"

/* Stack의 초기화 - StackInit */
void StackInit(Stack * pStack) {
	pStack -> head = NULL;
	pStack -> numOfData = 0;
}

/* Stack이 비어있는지 확인 - SIsEmpty */
int SIsEmpty(Stack * pStack) {
	if(pStack -> head == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/* Stack의 head에 데이터를 저장 - SPush */
void SPush(Stack * pStack, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;
	
	newNode -> next = pStack -> head;
	pStack -> head = newNode;
	
	(pStack -> numOfData)++;
}

/* Stack에 가장 마지막에 들어온 요소를 삭제 및 반환 - SPop */
Data SPop(Stack * pStack) {
	Node * rNode = pStack -> head;
	Data rData = rNode -> data;
	
	pStack -> head = pStack -> head -> next;
	free(rNode);
	
	(pStack -> numOfData)--;
	
	return rData;
}

/* Stack에 가장 마지막에 들어온 요소를 반환 - SPeek */
Data SPeek(Stack * pStack) {
	return pStack -> head -> data;
}