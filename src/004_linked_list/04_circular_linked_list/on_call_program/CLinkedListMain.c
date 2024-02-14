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



