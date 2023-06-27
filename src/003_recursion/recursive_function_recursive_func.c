#include <stdio.h>

void Recursive(int num) {
	if(num <= 0)
		return; // 재귀의 탈출조건
	printf("Recursive Call! %d\n", num);
	Recursive(num - 1);
}

int main() {
	Recursive(3);
}