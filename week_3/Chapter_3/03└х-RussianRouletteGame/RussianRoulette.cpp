#include "RussianRoulette.h"
int playRussianRoulette(int nTurns, int nBullets)
{
	int start = rand() % nTurns;
	printf("\n���� ���Ƚ��ϴ�. %d������ �����մϴ�.\n", start + 1);
	while (true) {
		int pos = rand() % 6;
		printf("[%d��]\tźâ�� �������� ���Ƚ��ϴ�.\n", start + 1);
		printf("\t���͸� ������ �ݹߵ˴ϴ�...");
		getchar();
		if (pos < nBullets) break;
		printf("\t��~~~ ��ҽ��ϴ�!!!\n");
		start = (start + 1) % nTurns;
	}
	printf("\t��~~~~~~~~~!!!\n");
	return start + 1;
}