#include <stdio.h>
void main()
{
	int x = 10;
	int* px = &x;
	int** ppx = &px;
	printf("  ����   x ��   = %d = %d = %d\n", x, *px, **ppx);
	printf("  ����   x �ּ� = 0x%x = 0x%x = 0x%x\n", &x, px, *ppx);
	printf("������  px �ּ� = 0x%x = 0x%x\n", &px, ppx);
	printf("������ ppx �ּ� = 0x%x\n", &ppx);
	*px = 20;
	printf("  ����   x ��   = %d = %d = %d\n", x, *px, **ppx);
}