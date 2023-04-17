#include <stdio.h>

struct car {
	char manufacturer[10];
	char name[10];
	int price;
};

int main()
{
	struct car car1 = {"BMW", "5 series", 67600000};
	struct car car2 = {"KIA", "K 7", 39690000};
	struct car car3 = {"Mclaren", "675lt", 440000000};
	
	printf("--Information of %s--\n Manufacturer : %s \n Name : %s \n Price : %d\n", car3.name, car3.manufacturer, car3.name, car3.price);
	printf("------------------------\n");
}