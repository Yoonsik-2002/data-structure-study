#include <stdio.h>
#include "areaArith/areaArith.h"
#include "roundArith/roundArith.h"

void main()
{
	printf("Area of the Triangle(base 4, height 2): %g\n", 
		  TriangleArea(4, 2));
	
	printf("Area of the Circle(rad 3): %g\n",
		  CircleArea(3));
	
	printf("Circumference of the Rectangle(base 2.5, height 5.2): %g\n", 
		  RectangleRound(2.5, 5.2));
	
	printf("Circumference of the Square(side 3): %g\n",
		  SquareRound(3));
}