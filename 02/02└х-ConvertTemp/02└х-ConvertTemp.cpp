#include <stdio.h>
void main()
{
	int 	choice;
	double	F, C;

	printf("�µ� ��ȯ���� ����.\n");
	printf(" 1: C->F, 2: F->C ==> ");
	scanf("%d", &choice);

	if (choice == 1) {	// ���� -> ȭ��
		printf(" �����µ� �Է�: ");
		scanf("%lf", &C);
		F = C * 9.0 / 5 + 32.;
		printf(" ȭ���µ� ���: %6.1f\n", F);
	}

	if (choice == 2) {	// ȭ�� -> ����
		printf(" ȭ���µ� �Է�: ");
		scanf("%lf", &F);
		C = (F - 32) * (5.0 / 9.0);
		printf(" �����µ� ���: %6.1f\n", C);
	}
}