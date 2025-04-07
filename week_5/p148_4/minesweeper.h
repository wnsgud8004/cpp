
#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

// 맵 최대 크기 상수 정의
#define MAX_WIDTH 80     // 최대 가로 길이
#define MAX_HEIGHT 40    // 최대 세로 길이

// 지뢰찾기 게임을 위한 구조체 정의
struct Game {
    int width;      // 실제 사용하는 맵의 가로 크기
    int height;     // 실제 사용하는 맵의 세로 크기
    int totalMines; // 지뢰의 총 개수

    // 지뢰 맵: -1이면 지뢰, 0 이상이면 주변 지뢰 수
    int mineMap[MAX_HEIGHT][MAX_WIDTH];

    // 마스크 맵:
    // 0: 닫힘 (숨김)
    // 1: 열림 (파낸 상태)
    // 2: 깃발 (지뢰로 추정하여 표시)
    int maskMap[MAX_HEIGHT][MAX_WIDTH];
};

// 함수 선언 (정의는 cpp 파일에서 구현)

// 게임 초기화: 맵 크기와 지뢰 수 설정 및 배열 초기화
void initGame(Game &game, int width, int height, int mineCount);

// 지뢰 무작위 배치: 첫 선택한 위치에는 지뢰가 없도록 보장
void placeMines(Game &game, int firstX, int firstY);

// 현재 게임 상태 출력: 마스크 맵 기준으로 출력
void printMap(const Game &game);

// 좌표가 맵의 범위 내에 있는지 확인
bool isInBounds(const Game &game, int y, int x);

// 특정 위치 주변 8칸의 지뢰 개수 세기
int countAdjacentMines(const Game &game, int y, int x);

// 특정 위치 열기 (재귀적으로 연결된 0도 함께 오픈)
void reveal(Game &game, int y, int x);

// 승리 조건 확인: 모든 지뢰를 정확히 찾았는지 확인
bool checkWin(const Game &game);

// 게임 루프 실행 함수
void playGame(Game &game);

#endif // MINESWEEPER_H

