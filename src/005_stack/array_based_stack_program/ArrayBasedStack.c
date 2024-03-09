#include <stdio.h>
#include <stdlib.h>

#include "ArrayBasedStack.h"

void main() {
	/* Stack의 초기화 - StackInit */
	void StackInit(Stack * pStack) {
		pStack -> topIndex = -1;
	}
	
	/* Stack이 비어있는지 확인 - SIsEmpty */
	int SIsEmpty(Stack * pStack) {
		if (pStack -> topIndex == -1) {
			return TRUE;
		}
		
		else 
			return FALSE;
	}
	
	/* Stack에 데이터 저장 - SPush */
	void SPush(Stack * pStack, Data data) {
		pStack -> topIndex += 1;
		pStack -> stackArr[pStack -> topIndex] = data;
	}
	
	/* Stack에 데이터 반환 및 삭제 - SPop */
	Data SPop(Stack * pStack) {
		int rIdx = pStack -> topIndex;
		
		if(SIsEmpty(pStack)) {
			print("stack memory error!");
			exit(1); // 프로그램 종료
		}
		
		pStack -> topIndex -= 1;
		return pStack -> stackArr[rIdx];
	}
	
	/* Stack에 마지막에 저장된 데이터 조회 - SPeek */
	Data SPeek(Stack * pStack) {
		if(SIsEmpty(pStack)) {
			print("stack memory error!");
			exit(1); // 프로그램 종료
		}
		
		return pStack -> stackArr[pStack -> topIndex];
	}
}