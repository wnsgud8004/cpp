#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// 전방 선언: Matrix에서 Monster 포인터 사용을 위해 필요
class Monster;

// =======================
// Matrix 클래스: 맵을 표현
// =======================
class Matrix {
private:
    int width, height;                      // 맵의 가로/세로 크기
    vector<vector<char>> grid;             // 2차원 문자 배열로 아이템 저장 ('*'는 아이템, '.'는 없음)

public:
    Matrix(int h, int w)
        : height(h), width(w), grid(h, vector<char>(w, '*')) {} // 초기 모든 칸에 아이템 설정

    // 맵의 특정 좌표의 값 반환
    char get(int y, int x) const { return grid[y][x]; }

    // 맵의 특정 좌표의 값 설정
    void set(int y, int x, char val) { grid[y][x] = val; }

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // 모든 아이템이 없어졌는지 확인
    bool allItemsCollected() const {
        for (const auto& row : grid)
            for (char cell : row)
                if (cell == '*') return false;
        return true;
    }

    // 현재 맵 상태와 몬스터 위치 출력
    void display(const vector<Monster*>& monsters) const;
};

// =======================
// Monster 클래스: 몬스터 정의
// =======================
class Monster {
private:
    int x, y;            // 현재 위치
    char shape;          // 출력 모양 (A, B, C 등)
    int items;           // 먹은 아이템 수
    int nEnergy;         // 현재 에너지 (0이면 제거 대상)
    static int count;    // 현재 존재하는 몬스터 수 (정적 멤버)

public:
    // 생성자: 위치, 모양, 에너지 초기화
    Monster(int x, int y, char shape)
        : x(x), y(y), shape(shape), items(0), nEnergy(100) {
        count++; // 몬스터 생성 시 전체 수 증가
    }

    // 소멸자: count 감소
    ~Monster() {
        count--;
    }

    // 8방향 중 하나로 이동 (맵 밖으로는 나가지 않음)
    void move(int width, int height) {
        static const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        static const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        int dir = rand() % 8;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
            x = nx;
            y = ny;
        }
    }

    // 현재 위치에서 아이템 먹기
    void eat(Matrix& map) {
        if (map.get(y, x) == '*') {
            items++;
            nEnergy += 8;              // 아이템 먹으면 에너지 증가
            map.set(y, x, '.');        // 아이템 제거
        } else {
            nEnergy = max(0, nEnergy - 1); // 못 먹으면 에너지 1 감소, 최소 0
        }
    }

    // 몬스터 정보 출력
    void print() const {
        cout << shape << " 몬스터 - 먹은 아이템 수: " << items
             << ", 에너지: " << nEnergy << '\n';
    }

    // 접근자 함수
    int getX() const { return x; }
    int getY() const { return y; }
    char getShape() const { return shape; }
    int getEnergy() const { return nEnergy; } // 에너지 반환

    // 현재 전체 몬스터 수 출력 (정적 함수)
    static void printCount() {
        cout << "현재 몬스터 수: " << count << '\n';
    }
};

// 정적 멤버 변수 정의
int Monster::count = 0;

// =======================
// Matrix::display 구현
// =======================
void Matrix::display(const vector<Monster*>& monsters) const {
    vector<vector<char>> displayGrid = grid;

    // 몬스터의 위치를 해당 모양으로 표시
    for (auto* m : monsters)
        displayGrid[m->getY()][m->getX()] = m->getShape();

    // 맵 출력
    for (const auto& row : displayGrid) {
        for (char cell : row)
            cout << cell << ' ';
        cout << '\n';
    }

    // 전체 몬스터 수 출력
    Monster::printCount();
}

// =======================
// 몬스터 에너지 검사 및 제거 함수
// =======================
void checkStarvation(vector<Monster*>& monsters) {
    for (auto it = monsters.begin(); it != monsters.end(); ) {
        if ((*it)->getEnergy() == 0) {
            delete *it;                // 메모리 해제
            it = monsters.erase(it);  // 포인터 제거
        } else {
            ++it;
        }
    }
}

// =======================
// main 함수
// =======================
int main() {
    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 설정

    // 맵 및 게임 설정
    int width = 10;
    int height = 8;
    int monsterCount = 3;
    int maxMoves = 50;

    // 맵 동적 생성
    Matrix* map = new Matrix(height, width);

    // 몬스터 동적 생성 및 배열에 저장
    vector<Monster*> monsters;
    for (int i = 0; i < monsterCount; ++i) {
        int x = rand() % width;
        int y = rand() % height;
        monsters.push_back(new Monster(x, y, 'A' + i));
    }

    int moveCount = 0;

    // 게임 루프
    while (moveCount < maxMoves) {
        cout << "Move #" << moveCount + 1 << '\n';

        // 모든 몬스터에 대해 이동 + 먹기
        for (auto* m : monsters) {
            m->move(width, height);
            m->eat(*map);
        }

        // 에너지 0인 몬스터 제거
        checkStarvation(monsters);

        // 현재 맵 상태 출력
        map->display(monsters);

        cout << "------------------------\n";

        moveCount++;

        // 게임 종료 조건
        if (map->allItemsCollected() || monsters.empty()) {
            cout << (monsters.empty() ? "모든 몬스터가 사라졌습니다!" : "모든 아이템을 수집했습니다!") << '\n';
            break;
        }
    }

    // 결과 출력
    cout << "\n최종 몬스터 상태:\n";
    for (auto* m : monsters)
        m->print();

    // 남은 메모리 해제
    for (auto* m : monsters)
        delete m;
    delete map;

    return 0;
}
