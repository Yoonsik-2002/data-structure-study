#ifndef __ARRAYLIST_H__  // 헤더 구분자의 명명 규칙 - 헤더파일의 파일명의 모든 영문자는 대문자로 바꾸고, '.' 은 '_' 로 바꾼다. 파일 이름의 앞, 뒤에 두개의 언더바 '__'를 붙인다. 
#define __ARRAYLIST_H__ 
#include "Point.h"

/* 헤더파일의 중복삽입 문제를 방지해주는 header gaurd.
#if(#ifndef, #ifdef)문 뒤에는 만드시 #endif문이 등장해야 하며, 이 두 지시자 사이에 존재하는 코드는
조건(조건이 되는 매크로가 정의되어 있느냐 아니냐)에 따라 삽입 및 삭제가 이루어진다.*/

#define TRUE	1  // 참을 표현하기 위한 메크로 정의
#define FALSE	0  // 거짓을 표현하기 위한 메크로 정의

#define LIST_LEN	100  // 구현하고자 하는 배열기반의 리스트의 배열의 크기
typedef Point * LData;  // LData에 대한 typedef 선언 - 구조체 Point 타입으로 지정

typedef struct __ArrayList {
	LData arr[LIST_LEN];  // 리스트의 저장소인 배열
	int numOfData;	// 저장된 데이터의 수
	int curPosition;  // 데이터의 참조위치를 기록
} ArrayList;

typedef ArrayList List;  // ArrayList에 List라는 별도의 이름을 부여 - main 함수를 변경하지 않고도 main함수 내에서 사용하는 리스트를 다른 것으로 변경이 가능함.

void ListInit(List * plist);  // 리스트의 생성 및 초기화
void LInsert(List * plist, LData data);  // 생성된 리스트에 데이터 저장

int LFirst(List * plist, LData * pdata);  // 첫 데이터 참조
int LNext(List * plist, LData * pdata);  // 두 번째 데이터 참조

LData LRemove(List * plist);  // 참조한 데이터 삭제
int LCount(List * plist);  // 저장된 데이터의 개수 반환

#endif  // #if(ifndef, ifdef)문 뒤에는 반드시 #endif문이 등장해야 하며, 이 두 지시자 사이에 존재하는 코드는 조건에 따라 삽입 및 삭제가 가능하다. 



