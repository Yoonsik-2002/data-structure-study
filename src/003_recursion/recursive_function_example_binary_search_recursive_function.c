#include <stdio.h>

int BSearchRecur(int ex_arr[], int first, int last, int target)
{
	int mid = (first + last) / 2;
	
	if(first > last)
		return -1;
	
	if(target == ex_arr[mid])
		return mid;
	else if(target < ex_arr[mid])
		return BSearchRecur(ex_arr, first, mid - 1, target);
	else
		return BSearchRecur(ex_arr, mid + 1, last, target);
}

void main()
{
	int ex_arr[] = {1, 3, 5, 7, 9};
	int result, target;
	
	printf("Enter the target : ");
	scanf("%d", &target);
	
	result = BSearchRecur(ex_arr, 0, sizeof(ex_arr)/sizeof(int)-1, target);
	
	if(result == -1)
		printf("값을 찾지 못하였음\n");
	else
		printf("target을 저장하고 있는 index : %d\n", result);
}