#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}coordinate;

int main() 
{
	coordinate spot[3];
	int i;
	
	for (i = 0; i < 3; i++) {
		printf("input coordinate of spot : ");
		scanf("%d %d", &spot[i].xpos, &spot[i].ypos);
	}
	
	for(i = 0; i < 3; i++) {
		printf("[%d, %d]\n", spot[i].xpos, spot[i].ypos);
	}
}