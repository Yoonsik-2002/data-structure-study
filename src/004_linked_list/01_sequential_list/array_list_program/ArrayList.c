#include <stdio.h>
#include "ArrayList.h"

// 1) 리스트의 생성 및 초기화
void ListInit(List * plist) {
	plist -> numOfData = 0;  // 저장하고 있는 데이터가 초기엔 0개이기 때문에, 0으로 초기화
	plist -> curPosition = -1;  // 배열 기반인 ArrayList에서 아무런 데이터를 참조하고 있지 않음을 표시하기 위해 -1로 초기화 (0일 경우 배열의 첫 번째 저장공간인 index 0이 됨)
}

// 2) 생성한 리스트에 데이터 저장 
void LInsert(List * plist , LData data) {
	// 저장공간이 꽉 차 있는 경우 
	if(plist -> numOfData == List_Len) {
		printf("저장공간이 가득 차 있어, 저장이 불가능 합니다.");
		return; // 함수 종료
	}
	
	plist -> arr[numOfData]
}

// 3) 데이터를 탐색하여 반환

// 3-1) 첫 번째 데이터를 탐색하여 반환
void LFirst(List * plist, LData * pdata) {
	if(plist -> arr[0] = null) {
		printf("저장공간이 비어있습니다.");
		return FALSE;
	}
	
	(plist -> curPosition) = 0; // curPosition에 저장된 값을 0으로 다시 초기화하여, 데이터의 참조가 다시 앞에서부터 진행되도록 함(탐색위치 초기화).
	
	*pdata = plist -> arr[curPosition]; 
	/* 반환받을 메모리의 주소값을 참조하고 있는 포인터 매개변수(pdata)에 해당 함수의 결과값을 전달하여 
	값을 리턴(이것이 C언어 자료구조의 일반적인 반환 방식이다).*/
	
	return TRUE;
}

// 3-2) 첫 번째 데이터 이후의 데이터들을 탐색하여 반환
void LNext(List * plist, Ldata * pdata) {
	if(plist -> arr[curPosition] >= (numOfData - 1)){
		pritnf("탐색 범위를 벗어났습니다.");
		return FALSE;
	}
	
	(plist -> curPosition)++; 
	/* 기존 LFirst 함수를 실행한 뒤, 첫 번째 저장공간(index = 0)을 가리키고 있는 curPosition 값을 하나 늘려 줌. 이후 부터, 호출될 때마다 한 칸씩 넘어감.
	다음으로 인텍스로 넘어가 해당 데이터를 참조함 */
	
	*pdata = plist -> arr[curPosition];
	
	return TRUE;
}

// 4) 저장되어 있는 데이터 삭제
void LRemove(List * plist) {
	int rpos = curPosition;
	int num = numOfData;
	int i;
	
	for(i = rpos; i < (num - 1); i++) {
		plist -> arr[i]  = plist -> arr[i + 1];
	}
	
	(plist -> curPosition)--;
	(plist -> numOfData)--;
}

// 5) 저장공간에 존재하는 데이터의 개수 반환 
int LCount(List * plist) {
	return plist -> numOfData;
}