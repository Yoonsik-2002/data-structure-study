#ifndef __AB_Stack_h__
#define __AB_Stack_h__

#define TRUE	1
#define FALSE 	0

#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pStack);
void SIsEmpty(Stack * pStack);

void SPush(Stack * pStack, Data data);
Data SPop(Stack * pStack);
Data SPeek(Stack * pStack);

#endIf