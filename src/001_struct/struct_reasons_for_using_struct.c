#include <stdio.h>

typedef struct {
	char name[20];
	char stdnum[20];
	char major[20];
	int year;
	float score;
}student;

void show_std_info(student * ptr) { // call by reference 형태의 함수호출을 수행하는 함수
	printf("Name : %s\n", ptr->name);
	printf("Student Number : %s\n", ptr->stdnum);
	printf("Major : %s\n", ptr->major);
	printf("Year : %d\n", ptr->year);
	printf("Score : %.2f\n", ptr->score);
}

int main()
{
	student stdarr[30];
	int i, num;
	
	printf("Input num : "); scanf("%d", &num);
	
	// 입력받은 학생 수 만큼 구조체 배열 stdarr에 학생 데이터 입력
	for(i = 0; i < num; i++){
		printf("Name : "); scanf("%s", stdarr[i].name);
		printf("Student Number : "); scanf("%s", stdarr[i].stdnum);
		printf("Major : "); scanf("%s", stdarr[i].major);
		printf("year : "); scanf("%d", &stdarr[i].year);
		printf("Score : "); scanf("%f", &stdarr[i].score);
	}
	
	for(i = 0; i < num; i++){
		show_std_info(&stdarr[i]); // call by reference 형태의 함수 show_std_info에 구조체 배열 stdarr의 0 부터 num 까지의 인덱스에 해당하는 구조체 변수의 주소값을 함수의 인자로서 전달. 
		puts("");
	}
}