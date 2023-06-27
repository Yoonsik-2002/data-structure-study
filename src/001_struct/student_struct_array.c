#include <stdio.h>

// 구조체 선언
typedef struct {
	int stdID;
	char name[20];
	float score;
}stdData;

// --함수 선언--
void over40(stdData *a, int n);
stdData findMax(stdData *a, int n);

int main()
{
	stdData exmember[30], stdInfo; // 구조체 타입의 구조체 배열 exmember
	int stdNum, i;
	
	// 구조체에 학생 데이터 입력
	// 1) 전체 학생 수 입력
	printf("Input number of student : ");
	scanf("%d", &stdNum);
	
	// 2) 구조체 배열 exmember에 전체 학생 수 만큼 반복하여 학생 데이터 입력 
	for(i = 0; i < stdNum; i++){
		printf("Input student data (student ID, name, score) : ");
		scanf("%d %[^\n]s %f", &exmember[i].stdID, exmember[i].name, &exmember[i].score); // 서식 지정자 %[^\n] : 공백까지 포함하여 문자열을 입력받음 
	}
	
	// --함수 호출-
	over40(exmember, stdNum);
	
	stdInfo = findMax(exmember, stdNum);
	printf("--Congratulation! Information of highest scored student--\n Student ID : %d \n Name : %s \n Score : %.2f\n", stdInfo.stdID, stdInfo.name, stdInfo.score);
	printf("---------------------------------------------------------\n");
}

// --함수 정의--
void over40(stdData exmember[], int stdNum) {
	printf("--Over 4.0 scored student--\n");
	
	for(int i = 0; i < stdNum; i++) {
		if(exmember[i].score > 4.0)
			printf("%s -- %.2f\n", exmember[i].name, exmember[i].score);
	}
	
	printf("---------------------------\n");
	puts("");
}

stdData findMax(stdData exmember[], int stdNum) {
	int maxIndex = 0;
	for (int i = 1; i < stdNum; i++) {
		if(exmember[i].score > exmember[maxIndex].score)
			maxIndex = i;
	}
	
	return exmember[maxIndex];
}

