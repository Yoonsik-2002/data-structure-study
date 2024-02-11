#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "CLinkedList.h"

Employee* whosNightDuty(List * pList, char * name, int day);
void showEmployeeInfo(Employee * pEmp);

void main() {
	
	
	/* 원형 연결 리스트의 생성 및 초기화 */
	List, list;
	ListInit(&list);
	
	/* 원형 연결 리스트에 4개의 사원 데이터 저장 */
	Employee * pemp = (Employee *)malloc(sizeof(Employee));
	strcmp(pemp -> name, "Yoonsik");
	pemp -> eNum = 0130;
	LInsert(&list, pemp);
	
	Employee * pemp = (Employee *)malloc(sizeof(Employee));
	strcmp(pemp -> name, "Minsu");
	pemp -> eNum = 1017;
	LInsert(&list, pemp);
	
	Employee * pemp = (Employee *)malloc(sizeof(Employee));
	strcmp(pemp -> name, "Sumin");
	pemp -> eNum = 0210;
	LInsert(&list, pemp);
	
	Employee * pemp = (Employee *)malloc(sizeof(Employee));
	strcmp(pemp -> name, "Gisun");
	pemp -> eNum + 1017;
	LInsert(&list, pemp);
}