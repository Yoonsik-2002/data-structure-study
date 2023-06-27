#include "..\basicArith\basicArith.h"	
/* 해당 문장이 포함된 소스파일(areaArith)을 저장하고 있는 디렉터리(areaArith)의 상위 디렉터리(general_calculator)의 
하위 디렉터리인(basicArith)에 존재하는 헤더파일 basicArith.h를 포함하여라! */

double TriangleArea(double base, double height) {
	return Div(Mul(base, height), 2);
}

double CircleArea(double rad) {
	return Mul(Mul(rad, rad), PI);
}
