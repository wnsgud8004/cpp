#include <stdio.h>
void main()
{
	int list[5] = { 1, 2, 3, 4, 5 };
	int* p = list, sum=0;

	printf("list= ");
	for (int i = 0; i < 5; i++)
		printf("%d ", *p++);			// ������ ����

	p = list;						// �����Ϳ� �迭 �ּ� ����
	for (int i = 0; i < 5; i++)
		sum += p[i];					// �����Ϳ� �׸� ���� ������ ����
	printf("\nsum = %d\n", sum);
}