#include <stdio.h>

int linear_search(int target, int array_length, int ex_arr[]) {
	int i;
	
	for(i = 0; i < array_length; i++){
		if(ex_arr[i] == target)
			return i; // 값을 찾은 배열의 인덱스 값을 반환하고 함수 종료
	}
	return -1; // 배열의 처음부터 끝까지 비교하였지만 값을 찾지 못한 경우. 값을 찾지 못하였음을 의미하는 값(-1) 을 반환하고 함수 종료
}

int main()
{
	int ex_arr[] = {1, 3, 5, 7, 9, 12, 13};
	int target_index;
	
	target_index = linear_search(7, sizeof(ex_arr) / sizeof(int), ex_arr);
	if(target_index == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n저장된 값 : %d\n", target_index, ex_arr[target_index]);
	
	puts("");
	
	target_index = linear_search(100, sizeof(ex_arr) / sizeof(int), ex_arr);
	if(target_index == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n 저장된 값 : %d\n", target_index, ex_arr[target_index]);
}