#include <stdio.h>
void main()
{
	float f;
	long int i;
	long double d;

	printf("<�ڷ����� ũ�� [bytes]>\n");
	printf("   char �� = %d\n", sizeof(char));
	printf("  short �� = %d\n", sizeof(short));
	printf("    int �� = %d\n", sizeof(int));
	printf("   long �� = %d\n", sizeof(long));
	printf("  float �� = %d\n", sizeof(float));
	printf(" double �� = %d\n", sizeof(double));

	printf("\n<������ ũ�� [bytes]>\n");
	printf("   long int ���� = %d\n", sizeof(i));
	printf("      float ���� = %d\n", sizeof(f));
	printf("long double ���� = %d\n", sizeof(d));

	printf("\n<����� ���� ���>\n");
	printf("  '3'�� �ڷ��� = %d\n", sizeof('3'));
	printf("   3 �� �ڷ��� = %d\n", sizeof(3));
	printf(" 3.0 �� �ڷ��� = %d\n", sizeof(3.0));
	printf("3.0f �� �ڷ��� = %d\n", sizeof(3.0f));
	printf(" 3+4 �� �ڷ��� = %d\n", sizeof(3 + 4));
	printf("3.0+4�� �ڷ��� = %d\n", sizeof(3.0 + 4));
}