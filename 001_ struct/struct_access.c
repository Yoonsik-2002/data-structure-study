#include <stdio.h>
#include <string.h>

typedef struct{
	int ID;
	char name[20];
	int age;
	float height;
	float weight;
}personal_info;

int main()
{
	personal_info my_info; // 구조체 변수 my_info 선언
	
	my_info.ID = 202343432;
	strcpy(my_info.name, "조윤식");
	my_info.age = 22;
	my_info.height = 172.6;
	my_info.weight = 63.4;
	
	printf("Information of %s\n ID : %d \n Name : %s \n Age : %d \n Height : %f \n Weight : %f\n", my_info.ID, 
		   my_info.name, my_info.age, my_info.height, my_info.weight);
}