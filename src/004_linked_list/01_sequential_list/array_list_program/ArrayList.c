#include <stdio.h>
#include "ArrayList.h"

// 1) 리스트의 생성 및 초기화
void ListInit(List * plist) {
	plist -> numOfData = 0;  // 저장하고 있는 데이터가 초기엔 0개이기 때문에, 0으로 초기화
	plist -> curPosition = -1;  // 배열 기반인 ArrayList에서 아무런 데이터를 참조하고 있지 않음을 표시하기 위해 -1로 초기화 (0일 경우 배열의 첫 번째 저장공간인 index 0이 됨)
}

// 2) 생성한 리스트에 데이터 저장 
void LInsert(List * plist , LData data) [
	// 저장공간이 꽉 차 있는 경우 
	if(plist -> numOfData == List_Len) {
		printf("저장공간이 가득 차 있어, 저장이 불가능 합니다.");
		return; // 함수 종료
	}
	
	plist -> arr[numOfData]
]