#include <stdio.h>
void main(void)
{
	int score;
	char grade;
	printf("������ �Է��ϼ���: ");
	scanf("%d", &score);

	if (score >= 90) grade = 'A';		// 90 <= score
	else if (score >= 80) grade = 'B';	// 80 <= score < 90
	else if (score >= 70) grade = 'C';	// 70 <= score < 80
	else if (score >= 60) grade = 'D';	// 60 <= score < 70
	else grade = 'F';					//score < 60
	printf(" ������ %c�Դϴ�.\n", grade);
}