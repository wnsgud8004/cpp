#include <stdio.h>
void printGuguDan(int dan)
{
	for (int i = 1; i <= 9; i++)
		printf("%2d x %2d = %2d\n", dan, i, dan*i);
}
void main()
{
	// ������ ���α׷���
	printf("[����ȭ ���α׷���]\n");
	printf("[������ %d ��]\n", 3);
	printGuguDan(3);
}