#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 8방향 이동을 위한 방향 벡터
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

// 몬스터 클래스 정의
class Monster {
public:
    int x, y;        // 현재 몬스터의 x, y 좌표
    char shape;      // 몬스터를 표시하는 문자
    int items;       // 먹은 아이템 수
    int nEnergy;     // 현재 에너지

    // 생성자: 몬스터의 초기 위치와 모양을 지정하고, 에너지는 100으로 초기화
    Monster(int startX, int startY, char mShape)
        : x(startX), y(startY), shape(mShape), items(0), nEnergy(100) {}

    // 먹기 행동을 수행하는 함수
    void eat(vector<vector<char>>& map) {
        if (map[y][x] == '*') {  // 현재 칸에 아이템이 있다면
            items++;             // 아이템 수 증가
            nEnergy += 8;         // 에너지는 8 증가
            map[y][x] = '.';      // 아이템을 먹었으니 빈 칸으로 변경
        } else {                  // 아이템이 없는 경우
            nEnergy -= 1;         // 에너지는 1 감소
            if (nEnergy < 0) nEnergy = 0; // 에너지는 최소 0 유지
        }
    }

    // 몬스터의 현재 상태를 출력하는 함수
    void print() const {
        cout << shape << " 몬스터 - 먹은 아이템 수: " << items
             << ", 에너지: " << nEnergy << '\n';
    }
};

// 현재 맵을 출력하는 함수
void printMap(const vector<vector<char>>& map, const vector<Monster>& monsters) {
    int height = map.size();
    int width = map[0].size();
    
    // 몬스터가 있는 위치를 표시하기 위해 맵 복사
    vector<vector<char>> display = map;
    for (const auto& m : monsters) {
        display[m.y][m.x] = m.shape; // 몬스터 모양으로 표시
    }
    
    // 맵 출력
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cout << display[y][x] << ' ';
        }
        cout << '\n';
    }
}

// 맵에 아이템이 모두 사라졌는지 확인하는 함수
bool allItemsCollected(const vector<vector<char>>& map) {
    for (const auto& row : map) {
        for (char cell : row) {
            if (cell == '*') return false; // 아이템이 남아있으면 false
        }
    }
    return true; // 아이템이 하나도 없으면 true
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 설정

    const int width = 10;        // 맵 너비
    const int height = 8;        // 맵 높이
    const int monsterCount = 3;  // 몬스터 수
    const int maxMoves = 50;     // 최대 이동 횟수

    // 맵 초기화: 모든 칸에 아이템('*') 배치
    vector<vector<char>> map(height, vector<char>(width, '*'));

    // 몬스터 초기화
    vector<Monster> monsters;
    for (int i = 0; i < monsterCount; ++i) {
        int startX = rand() % width;     // 무작위 x 좌표
        int startY = rand() % height;    // 무작위 y 좌표
        char shape = 'A' + i;            // 몬스터 모양 (A, B, C, ...)
        monsters.emplace_back(startX, startY, shape); // 몬스터 생성
    }

    int moveCount = 0; // 이동 횟수 카운터

    // 게임 루프: 최대 이동 횟수까지 반복
    while (moveCount < maxMoves) {
        cout << "Move #" << moveCount + 1 << '\n';

        for (auto& m : monsters) {
            // 8방향 중 무작위 방향 선택
            int dir = rand() % 8;
            int nx = m.x + dx[dir];
            int ny = m.y + dy[dir];

            // 맵 내부로만 이동 허용
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                m.x = nx;
                m.y = ny;
            }
            m.eat(map); // 이동한 후 아이템 먹기 시도
        }

        // 현재 맵 상태 출력
        printMap(map, monsters);
        cout << "-----------------------\n";

        moveCount++; // 이동 횟수 증가

        // 모든 아이템이 사라졌으면 게임 종료
        if (allItemsCollected(map)) {
            cout << "모든 아이템을 수집했습니다!\n";
            break;
        }
    }

    // 몬스터별 결과 출력
    cout << "\n몬스터별 결과:\n";
    for (const auto& m : monsters) {
        m.print(); // 각 몬스터의 상태 출력
    }

    return 0;
}
