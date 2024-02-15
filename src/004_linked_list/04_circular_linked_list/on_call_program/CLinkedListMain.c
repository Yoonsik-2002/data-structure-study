#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "CLinkedList.h"

Employee* whosNightDuty(List * pList, char * name, int day);
void showEmployeeInfo(Employee * pemp);

void main() {
	int i;
	Employee * pemp;
	
	/* 원형 연결 리스트의 생성 및 초기화 */
	List, list;
	ListInit(&list);
	
	/* 원형 연결 리스트에 4개의 사원 데이터 저장 */
	pemp = (Employee *)malloc(sizeof(Employee));
	strcmp(pemp -> name, "Yoonsik");
	pemp -> eNum = 0130;
	LInsert(&list, pemp);
	
	pemp = (Employee *)malloc(sizeof(Employee));
	strcmp(pemp -> name, "Minsu");
	pemp -> eNum = 1017;
	LInsert(&list, pemp);
	
	pemp = (Employee *)malloc(sizeof(Employee));
	strcmp(pemp -> name, "Sumin");
	pemp -> eNum = 0210;
	LInsert(&list, pemp);
	
	pemp = (Employee *)malloc(sizeof(Employee));
	strcmp(pemp -> name, "Gisun");
	pemp -> eNum + 1017;
	LInsert(&list, pemp);
	
	/* 15일 뒤, 당직 사원 */
	whosNightDuty(&list, "Sumin", 15);
	showEmployeeInfo(pemp);
	
	/* 7일 뒤, 당직 사원 */
	whosNightDuty(&list, "Yoonsik", 7);
	showEmployeeInfo(pemp);
	
	/* 모든 데이터 소멸 */
	if(LFirst(&list, &pemp)) {
		free(pemp);
		for(i = 0; i < LCount(&list) -1; i++) {
			if(LNext(&list, &pemp)) {
				free(pemp);
			}
		}
	}
}	

Employee* whosNightDuty(List * pList, char * name, int day) {
	int i;
	Data * rat;
	
	LFirst(&list, &rat); // 첫 번째 노드의 데이터(구조체 형태)를 구조체 포인터 변수 rat이 가리킴 
	
	/* 그냥 rat을 전달하는 경우 - 구조체 포인터 변수 rat이 저장하고 있는 값이 함수의 매개변수에 복사되어 전달된다.
	해당 매개변수는 단지, rat이 저장하고 있는 값을 복사하여 저장하고 있는 별도의 구조체 포인터 변수이며, 해당 매개변수의 값을 변경하더라도
	함수 외부에 있는 rat에게는 아무런 영향을 미치지 못한다. 또, 함수 종료 시, 소멸된다.
	
	-> 위 코드와 같이 함수 외부에 있는 구조체 포인터 변수 rat의 주소값을 매개변수에 전달받아 사용하면, rat의 값을 함수 내에서 변경 가능하다.
	
	   LFirst(&list, &rat); 구조체 포인터 변수 rat의 주소값이 매개변수에 복사되어 전달됨. CLL의 첫 번째 노드의 데이터를 rat의 주소값을 
	   이용하여 가리키게 함. 함수가 종료되어도 이는 외부에 존재하는 rat에 그대로 적용되어 있음. */
	
	if(srtcmp(rat -> name, name) != 0) { // 첫 번째 노드의 데이터로 저장되어 있는 이름이 찾고자 하는 이름과 같지 않은 경우
		for(i = 0; i < LCount(&list)-1; i++) {
			LNext(&list, &rat);
			if(strcmp(rat -> name, name == 0)
			   break;
		}
	}   
}


