#include <stdio.h>
void main()
{
	// ������ ���α׷���
	int i = 1;
	int dan = 3;
	printf("[������ ���α׷���]\n");
	printf("[������ %d ��]\n", dan);
loop:
	printf("%2d x %2d = %2d\n", dan, i, dan*i);
	i++;
	if (i <= 9) goto loop;
}