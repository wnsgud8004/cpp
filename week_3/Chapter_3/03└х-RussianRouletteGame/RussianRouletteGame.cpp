#include "RussianRoulette.h"
void main()
{
	int nTurn, nBullets;
	srand((unsigned)time(NULL));

	printf("���� �ο� (��:2) ==> ");
	scanf("%d", &nTurn);
	printf("�Ѿ� ���� (6�̸�) ==> ");
	scanf("%d", &nBullets);
	getchar();

	int bang = playRussianRoulette(nTurn, nBullets);
	printf("\n -----> %d�� �����ڰ� �ѿ� �¾ҽ��ϴ�.\n", bang);
}