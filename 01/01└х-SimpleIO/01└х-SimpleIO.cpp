#include <stdio.h>

void main()
{
	int		i;
	double	d;
	char 	str[100];

	printf("���� �Է�: ");
	scanf("%d", &i);
	printf(" - �Էµ� ����: %d\n", i);
	printf(" - ���� ������ �ּ�: %0x\n\n", &i);

	printf("�Ǽ� �Է�: ");
	scanf("%lf", &d);
	printf(" - �Էµ� �Ǽ�: %lf\n", d);
	printf(" - �Ǽ� ������ �ּ�: %0x\n\n", &d);

	printf("���ڿ� �Է�: ");
	scanf("%s", str);
	printf(" - �Էµ� ���ڿ�: %s\n", str);
	printf(" - ���ڿ��� �ּ�: %0x\n", str);
}