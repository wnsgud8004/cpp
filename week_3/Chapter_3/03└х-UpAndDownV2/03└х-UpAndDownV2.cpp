#include "myFunctions.h"	// ���α׷� 3.7 ����
#include <stdio.h>
#include <time.h>

void main()
{
	clock_t t1 = clock();
	int score = playUpAndDown(43, 0, 99);
	clock_t t2 = clock();
	double  duration = (double)(t2 - t1) / CLOCKS_PER_SEC;

	printf(" ���� ����: %d��\n", score);
	printf(" �ɸ� �ð�: %lf��\n", duration);
}