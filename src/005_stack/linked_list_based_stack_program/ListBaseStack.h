#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE 	1;
#define FALSE 	0;

typedef int Data;

typedef struct _node {
	Data data;
	struct _node * next;
} Node;

typedef struct _StackList {
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
} StackList;

typedef StackList Stack;

void StackInit(Stack * pStack);
int SIsEmpty(Stack * pStack);

void SPush(Stack * pStack, Data data);
Data SPop(Stack * pStack);
Data SPeek(Stack * pStack);

#endif