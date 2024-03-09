#include <stdio.h>
#include "ArrayBasedStack.h"

void main() {
	Stack stack;
	
	/* stack의 초기화 */
	StackInit(&stack);
	
	/* 1~5까지의 데이터 저장 */
	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);
	
	
	/* 데이터 삭제 및 조회 */
	while(stack.topIndex >= 0) {
		Data rdata = SPop(&stack);
		printf("%d ", rdata);
	}
	printf("\n");
}