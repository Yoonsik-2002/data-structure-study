// 구조체 배열의 선언과 초기화 - 구조체 배열의 선언과 동시에 초기화 하는 방법

#include <stdio.h>

typedef struct {
	char name[20];
	int age;
	float height;
	float weight;
}person;

int main()
{
	person student[4] = {
		{"조윤식", 22, 172.6, 63.4},
		{"김한올", 23, 162.3, 56.2},
		{"김성우", 21, 180.2, 75.3},
		{"김민지", 24, 158.3, 52.1}
	};
	
	int i;
	
	printf("--Information of student--\n");
	for(i = 0; i < 4; i++) {
		printf("\n Name : %s \n Age : %d \n Height : %.1f \n Weight : %.1f \n", student[i].name, student[i].age, student[i].height, student[i].weight);
		puts("");
	}
	printf("--------------------------\n");
}