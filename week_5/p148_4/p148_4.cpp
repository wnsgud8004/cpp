#include "minesweeper.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// 상수 정의
const char MINE = '*';   // 지뢰 표시
const char HIDDEN = '.'; // 아직 열리지 않은 칸 표시
const char FLAG = 'P';   // 사용자가 깃발을 꽂은 칸 표시

// 사용자 입력값 저장
int width, height, mineCount;

// 게임 맵과 마스크 맵
char map[MAX_HEIGHT][MAX_WIDTH];     // 실제 지뢰가 들어 있는 맵
char mask[MAX_HEIGHT][MAX_WIDTH];    // 사용자가 보는 맵 (마스크 처리)

// 방향 벡터 (상하좌우 + 대각선 8방향)
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 게임 맵과 마스크 초기화
void initMaps() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = '0';       // 지뢰가 없음을 의미
            mask[i][j] = HIDDEN;   // 초기에는 모든 칸이 숨겨짐
        }
    }
}

// 맵 범위 체크 함수
bool inBounds(int y, int x) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

// 지뢰 무작위 배치 함수 (첫 선택 위치는 피함)
void placeMines(int startY, int startX) {
    int placed = 0;
    srand(time(0)); // 난수 시드 설정

    while (placed < mineCount) {
        int y = rand() % height;
        int x = rand() % width;

        // 시작 위치나 이미 지뢰가 있는 곳은 제외
        if ((y == startY && x == startX) || map[y][x] == MINE) continue;

        map[y][x] = MINE; // 지뢰 설치
        placed++;

        // 지뢰 주변 숫자 증가
        for (int d = 0; d < 8; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (inBounds(ny, nx) && map[ny][nx] != MINE) {
                map[ny][nx]++; // 문자 '0'에 숫자 더하기
            }
        }
    }
}

// 현재 마스크 맵 출력
void printMap() {
    cout << "    ";
    for (int j = 0; j < width; j++) {
        cout << setw(2) << j; // 열 번호 출력
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        cout << setw(3) << i << "|"; // 행 번호 출력
        for (int j = 0; j < width; j++) {
            cout << setw(2) << mask[i][j]; // 마스크된 값 출력
        }
        cout << endl;
    }
}

// 0인 칸 자동으로 재귀적으로 펼치기
void reveal(int y, int x) {
    if (!inBounds(y, x) || mask[y][x] != HIDDEN) return;

    mask[y][x] = map[y][x]; // 실제 맵 숫자 보여주기

    if (map[y][x] == '0') { // 0이면 주변 칸도 재귀적으로 오픈
        for (int d = 0; d < 8; d++) {
            reveal(y + dy[d], x + dx[d]);
        }
    }
}

// 승리 조건 체크
bool checkWin() {
    int hidden = 0, flags = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (mask[i][j] == HIDDEN) hidden++;
            if (mask[i][j] == FLAG) flags++;
        }
    }

    return hidden + flags == mineCount;
}

// 메인 함수
int main() {
    cout << "지뢰찾기 게임을 시작합니다!" << endl;
    cout << "맵의 가로 크기 입력 (최대 80): ";
    cin >> width;
    cout << "맵의 세로 크기 입력 (최대 40): ";
    cin >> height;
    cout << "지뢰 개수 입력: ";
    cin >> mineCount;

    initMaps(); // 초기 맵 설정
    bool firstMove = true;
    bool gameOver = false;

    while (!gameOver) {
        printMap(); // 현재 상태 출력

        int x, y;
        char action;
        cout << "열 번호, 행 번호, 동작(P 또는 D)을 입력하세요 (예: 3 5 D): ";
        cin >> x >> y >> action;

        if (!inBounds(y, x)) {
            cout << "잘못된 위치입니다." << endl;
            continue;
        }

        if (firstMove) {
            placeMines(y, x); // 첫 번째 클릭에는 지뢰 없음
            firstMove = false;
        }

        if (action == 'P') { // 깃발 표시
            if (mask[y][x] == HIDDEN)
                mask[y][x] = FLAG;
        } else if (action == 'D') { // 땅 파기
            if (map[y][x] == MINE) {
                cout << "지뢰를 밟았습니다! 게임 오버!" << endl;
                gameOver = true;
                mask[y][x] = MINE;
            } else {
                reveal(y, x); // 안전하면 퍼지기
                if (checkWin()) {
                    cout << "모든 지뢰를 찾았습니다! 승리!" << endl;
                    gameOver = true;
                }
            }
        } else {
            cout << "잘못된 동작입니다. P 또는 D만 입력 가능합니다." << endl;
        }
    }

    // 최종 전체 맵 보여주기 (디버깅용)
    cout << "최종 맵:" << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
