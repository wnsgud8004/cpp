#include <stdio.h>
#include <math.h>					// pow()�� ����ϱ� ���� ����
double myPow(double x, int y) {	// ����� ���� �Լ�
	double result = 1.0;
	for (int i = 0; i<y; i++)
		result = result * x;
	return result;
}
void main()
{
	printf("���̺귯�� pow(2.0, 5) = %lf\n", pow(2.0, 5));
	printf("�������� myPow(2.0, 5) = %lf\n", myPow(2.0, 5));
}