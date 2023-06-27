#include <stdio.h>

typedef struct {
	int stdID;
	char name[20];
	float score;
}stdData;

int main()
	stdData exmember[30] = {
		{20211059, "Cho minjin", 4.3},
		{20213423, "Kim Minseo", 3.8},
		{20182343, "Choi Jeongmin", 4.1}
	};
	
	printf("--Score of %s--\n Score : %.2f \n", exmember[0].name, exmember[0].score);
	printf("-----------------------\n");
}