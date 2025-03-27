#include <stdio.h>
double calcTax(int income)
{
	const int NumSteps = 5;
	int amount[NumSteps] = { 0, 1200, 4600, 8800, 15000 };
	double tax = 0, rate[NumSteps] = { 0.06, 0.15, 0.24, 0.35, 0.38 };

	for (int i = NumSteps - 1; i>0; i--) {
		if (income > amount[i]) {
			tax += rate[i] * (income - amount[i]);
			income = amount[i];
		}
	}
	tax += income*rate[0];
	return tax;
}

void main()
{
	int income;
	double tax;
	printf("������ �Է��ϼ��� ==> ");
	scanf("%d", &income);
	tax = calcTax(income);
	printf(" ��ü������ %7.1f�����Դϴ�.\n", tax);
	printf(" �����ҵ��� %7.1f�����Դϴ�.\n", income - tax);
}