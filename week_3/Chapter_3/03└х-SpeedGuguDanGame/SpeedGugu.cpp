#include "SpeedGugu.h"

static int NumGames = 0;	// ��ü �õ� Ƚ��
static int NumWins = 0;	// ���� Ƚ��
static double Score = 0;	// ����
double tElapsed = 0; 		// ���� �ҿ�ð�

static bool playGuguOnce()
{
	int	a = rand() % 8 + 2;
	int	b = rand() % 8 + 2;
	int	result;

	NumGames++;
	printf("[����%2d]: %2d x %2d = ", NumGames, a, b);
	scanf("%d", &result);
	if (result == a*b) NumWins++;
	return (result == a*b);
}
double playSpeedGugu(int nPlay)
{
	clock_t	t0 = clock();
	for (int i = 0; i<nPlay; i++) {
		if (playGuguOnce() == false)
			printf("\tƲ�Ƚ��ϴ�.\n");
	}
	clock_t	t1 = clock();
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;
	Score = (NumGames > NumWins) ? 0.0
		: 100 * (5.0*NumGames - tElapsed) / (5.0*NumGames);
	return Score;
}