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
	pemp = whosNightDuty(&list, "Sumin", 15);
	showEmployeeInfo(pemp);
	
	/* 7일 뒤, 당직 사원 */
	pemp = whosNightDuty(&list, "Yoonsik", 7);
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
	Data * ret; 
	
	/* 매개변수로 전달받은 사원 탐색 */
	LFirst(&list, &ret);
	
	if(strcmp(rat -> name, name) != 0) {
		for(i = 0; i < LCount(&list)-1; i++) {
			LNext(&list, &ret);
			
			if(strcmp(ret -> name, name) == 0)
				break;
		}
		// if(ret == NULL) {
		// 	return NULL;
		// }
		
		if(i >= LCount(&list)-1) {
			return NULL;
		}
	}
	
	/* 탐색한 사원으로 부터, day일 후, 당직 근무에 투입되는 사원을 탐색 */
	for(i = 0; i < day; i++) {
		LNext(&list, &ret);
	}
	
	return ret;
}

void showEmployeeInfo(Employee * pemp) {
	print(pemp -> name);
	print(pemp -> eNum);
}

