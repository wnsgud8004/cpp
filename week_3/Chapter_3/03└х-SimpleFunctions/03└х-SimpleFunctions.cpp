#include <stdio.h>
int factorial(int);		// factorial()�Լ��� ���� ����
int add(int, int);		// add()�Լ��� ���� ����
void main()
{
	int x = 3, y = 4, z;
	z = add(x, y);
	printf("x + y  = %d\n", z);
	printf("x + 10 = %d\n", add(x, 10));	// ������ ��� ����
	printf("5 + 10 = %d\n", add(5, 10)); 	// �� ��� ����

	z = factorial(x);					// 3!�� ����� z�� ����
	printf("%d! = %d\n", x, z);			// z�� ȭ�鿡 ���
	printf("5! = %d\n", factorial(5));	// 5!�� ����� ȭ������ ���
}
// ���α׷� 3.2�� ��� �ڵ� �߰�

int add(int a, int b) 		// �� int���� ���� ��ȯ�ϴ� �Լ�
{
	int sum;					// ��� ���� ������ ���� ����
	sum = a + b;				// a �� b�� ���� sum�� ������
	return sum;				// ��� ���� sum�� ��ȯ
}
int factorial(int n)			// n!�� ���ϴ� �Լ�
{
	int result = 1;			// ��� ���� ������ ���� ���� �� �ʱ�ȭ
	for (int i = 1; i <= n; i++)// i�� 1���� n���� 1�� �����ϸ鼭 �ݺ��� ����
		result *= i;			// result�� i�� ����
	return result;			// ��� ���� result�� ��ȯ
}