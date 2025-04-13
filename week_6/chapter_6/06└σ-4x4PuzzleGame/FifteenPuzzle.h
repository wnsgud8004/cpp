#include "RankingBoard.h"	// ���α׷� 6.3�� ��ŷ ó�� Ŭ���� ����
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define DIM  4
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
const int DirKey[4] = { Left, Right, Up, Down };

class FifteenPuzzle {
	int	map[DIM][DIM];
	int	x, y;
	int	nMove;
	clock_t	tStart;
	RankingBoard	ranking;

	void init() { 			// init()�� ����
		for (int i = 0; i<DIM*DIM - 1; i++)
			map[i / DIM][i%DIM] = i + 1;
		map[DIM - 1][DIM - 1] = 0;
		x = DIM - 1; y = DIM - 1;

		srand(time(NULL));	// ���� �߻� ���� ����
		tStart = clock();	// ���� �ð� ����
		nMove = 0;		// �̵� Ƚ�� �ʱ�ȭ
	}
	void display() { 			// display()�� ����
		system("cls");
		printf("\tFifteen Puzzle\n\t");
		printf("--------------\n\t");
		for (int r = 0; r<DIM; r++) {
			for (int c = 0; c<DIM; c++) {
				if (map[r][c]>0)
					printf("%3d", map[r][c]);
				else printf("   ");
			}
			printf("\n\t");
		}
		printf("--------------\n\t");
		clock_t	t1 = clock();
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
		printf("\n\t�̵� Ƚ��:%6d\n\t�ҿ� �ð�:%6.1f\n\n", nMove, d);
	}
	bool move(int dir) { 		// move()�� ����
		if (dir == Right && x>0) {		// �� : �� ���� ������ �˻�
			map[y][x] = map[y][x - 1];
			map[y][--x] = 0;
		}
		else if (dir == Left && x<DIM - 1) {	// �� : �� �����ʿ����� �˻�
			map[y][x] = map[y][x + 1];
			map[y][++x] = 0;
		}
		else if (dir == Up && y<DIM - 1) {		// �� : �� �Ʒ������� �˻�
			map[y][x] = map[y + 1][x];
			map[++y][x] = 0;
		}
		else if (dir == Down && y>0) {		// �� : �� �������� �˻�
			map[y][x] = map[y - 1][x];
			map[--y][x] = 0;
		}
		else return false;

		nMove++;
		return true;
	}
	void shuffle(int nShuffle) { 	// shuffle()�� ����
		for (int i = 0; i<nShuffle; i++) {
			int key = DirKey[rand() % 4];
			if (move(key) == false) { i--; continue; }
			display();
			Sleep(50);
		}
	}
	bool isDone() { 			// isDone()�� ����
		for (int r = 0; r<DIM; r++) {
			for (int c = 0; c<DIM; c++) {
				if (map[r][c] != r * DIM + c + 1)
					return (r == DIM - 1) && (c == DIM - 1);
			}
		}
		return true;
	}
	int getDirKey() { 			// getDirKey()�� ����
		return getche() == 224 ? getche() : 0;
	}
public:
	void play(char* filename) {
		ranking.load(filename);	// ������ ���۵Ǹ� ��ŷ�� ���� 
		init();
		display();
		ranking.print();		// ���� ��ŷ�� ���

		// ���α׷� 4.14�� play()�Լ� ���� �߰�
		printf("\n ������ �����ּ���(����)...");
		getche();
		shuffle(100);			// ���� ������ 100�� �̵��� ����
		printf("\n ������ ���۵˴ϴ�...");
		getche();

		nMove = 0;			// �̵� Ƚ�� �ʱ�ȭ
		tStart = clock();		// ���� �ð��� �� ����
		while (!isDone()) {		// ���� ���� �˻�
			move(getDirKey());	// Ű�� �޾� �������� �̵�
			display();		// ���� ���¸� ȭ�鿡 ���
		}
		clock_t	t1 = clock();		// ���� �ð�
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;

		ranking.add(nMove, d);	// ��ŷ�� ���� ��� �߰�
		ranking.store(filename);	// ���� ��ŷ�� ���Ͽ� ����
	}

};
