#include <stdio.h>
#include "myFunctions.h"
void main()
{
	printf("���� %5.1f�� = ȭ�� %5.1f��\n", 27.0, Celcius2Fahrenheit(27.0));
	printf("ȭ�� %5.1f�� = ���� %5.1f��\n", 95.0, Fahrenheit2Celcius(95.0));
	printNumPyramid(5);
	printf("���� ���� = %d\n", playUpAndDown(35, 0, 99));
}

