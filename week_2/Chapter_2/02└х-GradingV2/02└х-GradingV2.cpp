#include <stdio.h>
void main(void)
{
	int score;
	char grade;
	printf("������ �Է��ϼ���: ");
	scanf("%d", &score);

	switch (score / 10) {
	case 10:					// 100�� �̰ų�
	case 9:	grade = 'A'; break;		// 90�� �̻��̸� A 
	case 8:	grade = 'B'; break;		// 80�� �̻��̸� B 
	case 7:	grade = 'C'; break;		// 70�� �̻��̸� C 
	case 6:	grade = 'D'; break;		// 60�� �̻��̸� D 
	default:grade = 'F'; break;		// 60�� �̸��̸� F
	}
	printf(" ������ %c�Դϴ�.\n", grade);
}