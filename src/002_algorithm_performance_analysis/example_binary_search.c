#include <stdio.h>

int b_search(int ex_arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	
	while(first <= last) {
		mid = (first + last) / 2;
		if(target == ex_arr[mid])
			return mid; // target 과 중앙값이 같은 경우, 값을 찾은 경우
		else {  // target 과 중앙값이 다른 경우, 값을 찾지 못한 경우 - 두가지 경우로 나뉨 target 이 중앙값보다 작은 경우, target 이 중앙값보다 큰 경우
			if(target < ex_arr[mid])
				last = mid - 1;
			if(target > ex_arr[mid])
				first = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int ex_arr[] = {1, 2, 3, 7, 9, 12, 13, 21, 27};
	int idx;
	
	idx = b_search(ex_arr, sizeof(ex_arr) / sizeof(int), 3);
	if(idx == -1)
		printf("값을 찾지 못하였음\n");
	else
		printf("target 을 저장하고 있는 index : %d\n", idx);
	
	idx = b_search(ex_arr, sizeof(ex_arr) / sizeof(int), 4);
	if(idx == -1)
		printf("값을 찾지 못하였음\n");
	else
		printf("target 을 저장하고 있는 index : %d\n", idx);
}