#include "SpeedGuguGame.h"
void main()
{
	srand((unsigned)time(NULL));

	int nPlay = 10;
	printf("[���ǵ� ������ ����]\n\n");
	printf(" ����� ������ �Ƿ��� �׽�Ʈ�ϼ���.!!!\n");
	printf(" %d�� �׽�Ʈ �ϰڽ��ϴ�.\n", nPlay);
	printf(" ũ�� ��ȣ���� �Ͻð�...\n �غ�Ǹ� ���͸� ��������...");
	getchar();
	system("cls");

	SpeedGuguGame	game;
	double score = game.play(nPlay);
	printf("\n���� = %4.1f��(�� %4.1f��)\n", score, game.tElapsed);
}
