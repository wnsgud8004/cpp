#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Monster; // 전방 선언

// =========================
// Matrix 클래스: 맵을 표현
// =========================
class Matrix {
private:
    int width, height;               // 맵 크기
    vector<vector<char>> grid;      // 아이템이 있는 맵: '*'는 아이템, '.'는 빈칸

public:
    Matrix(int h, int w)
        : height(h), width(w), grid(h, vector<char>(w, '*')) {}

    char get(int y, int x) const { return grid[y][x]; }        // 좌표에 있는 값 반환
    void set(int y, int x, char val) { grid[y][x] = val; }     // 좌표에 값 설정

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // 맵에 아이템이 남아 있는지 검사
    bool allItemsCollected() const {
        for (const auto& row : grid)
            for (char cell : row)
                if (cell == '*') return false;
        return true;
    }

    // 몬스터 포함한 현재 맵 출력
    void display(const vector<Monster*>& monsters) const;
};

// =========================
// Monster 클래스 (추상)
// =========================
class Monster {
protected:
    int x, y;          // 현재 위치
    char shape;        // 출력 모양
    int items;         // 먹은 아이템 수
    int nEnergy;       // 현재 에너지
    static int count;  // 전체 몬스터 수

public:
    Monster(int x, int y, char shape)
        : x(x), y(y), shape(shape), items(0), nEnergy(100) {
        count++;
    }

    virtual ~Monster() {
        count--;
    }

    // 모든 몬스터가 각기 다른 방식으로 이동하므로 순수 가상 함수로 정의
    virtual void move(int width, int height) = 0;

    // 아이템 먹기
    void eat(Matrix& map) {
        if (map.get(y, x) == '*') {
            items++;
            nEnergy += 8;             // 아이템 먹으면 에너지 증가
            map.set(y, x, '.');       // 아이템 제거
        } else {
            nEnergy = max(0, nEnergy - 1); // 못 먹으면 에너지 감소 (최소 0)
        }
    }

    void print() const {
        cout << shape << " 몬스터 - 먹은 아이템 수: " << items
             << ", 에너지: " << nEnergy << '\n';
    }

    // 접근자
    int getX() const { return x; }
    int getY() const { return y; }
    char getShape() const { return shape; }
    int getEnergy() const { return nEnergy; }

    static void printCount() {
        cout << "현재 몬스터 수: " << count << '\n';
    }
};

int Monster::count = 0;

// =========================
// 각 몬스터 구현체
// =========================

// 좀비: 8방향 랜덤 이동
class Zombie : public Monster {
public:
    Zombie(int x, int y) : Monster(x, y, 'Z') {}

    void move(int width, int height) override {
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
};

// 뱀파이어: 상하좌우 4방향만 이동
class Vampire : public Monster {
public:
    Vampire(int x, int y) : Monster(x, y, 'V') {}

    void move(int width, int height) override {
        static const int dx[4] = {0, 1, 0, -1};
        static const int dy[4] = {-1, 0, 1, 0};
        int dir = rand() % 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
            x = nx;
            y = ny;
        }
    }
};

// 강시: 좌우 or 상하로 1~3칸 직진
class Jiangshi : public Monster {
protected:
    bool horizontal; // true: 좌우, false: 상하

public:
    Jiangshi(int x, int y) : Monster(x, y, 'J'), horizontal(rand() % 2) {}

    void move(int width, int height) override {
        int dir = rand() % 2 == 0 ? -1 : 1;
        int steps = rand() % 3 + 1;

        int nx = x, ny = y;
        if (horizontal) nx += dir * steps;
        else ny += dir * steps;

        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
            x = nx;
            y = ny;
        }
    }
};

// 슈퍼 강시: 일정 턴마다 방향 전환
class Siangshi : public Jiangshi {
private:
    int tick;

public:
    Siangshi(int x, int y) : Jiangshi(x, y) {
        shape = 'S';  // 모양 변경
        tick = 0;
    }

    void move(int width, int height) override {
        tick++;
        if (tick % 5 == 0) horizontal = !horizontal; // 5턴마다 방향 전환
        Jiangshi::move(width, height);               // 부모 이동 사용
    }
};

// 스몸비: 대각선 방향만 이동
class Smombi : public Monster {
public:
    Smombi(int x, int y) : Monster(x, y, 'M') {}

    void move(int width, int height) override {
        static const int dx[4] = {-1, -1, 1, 1};
        static const int dy[4] = {-1, 1, -1, 1};
        int dir = rand() % 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
            x = nx;
            y = ny;
        }
    }
};

// Cyclone: 8방향을 회전하면서 이동 (사용자 정의 몬스터)
class Cyclone : public Monster {
private:
    int direction; // 현재 방향 인덱스

public:
    Cyclone(int x, int y) : Monster(x, y, 'C'), direction(0) {}

    void move(int width, int height) override {
        static const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        static const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        direction = (direction + 1) % 8; // 회전

        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
            x = nx;
            y = ny;
        }
    }
};

// Ghost: 맵 내 임의 위치로 순간이동
class Ghost : public Monster {
public:
    Ghost(int x, int y) : Monster(x, y, 'G') {}

    void move(int width, int height) override {
        x = rand() % width;
        y = rand() % height;
    }
};

// =========================
// 맵 출력
// =========================
void Matrix::display(const vector<Monster*>& monsters) const {
    vector<vector<char>> disp = grid;

    for (auto* m : monsters)
        disp[m->getY()][m->getX()] = m->getShape();

    for (const auto& row : disp) {
        for (char cell : row)
            cout << cell << ' ';
        cout << '\n';
    }

    Monster::printCount(); // 전체 몬스터 수 출력
}

// =========================
// 에너지 0 몬스터 제거
// =========================
void checkStarvation(vector<Monster*>& monsters) {
    for (auto it = monsters.begin(); it != monsters.end(); ) {
        if ((*it)->getEnergy() == 0) {
            delete *it;
            it = monsters.erase(it);
        } else {
            ++it;
        }
    }
}

// =========================
// 메인 함수
// =========================
int main() {
    srand(time(0)); // 랜덤 시드

    const int width = 10, height = 8, maxMoves = 50;

    // 맵 생성
    Matrix* map = new Matrix(height, width);

    // 다양한 몬스터 생성
    vector<Monster*> monsters;
    monsters.push_back(new Zombie(1, 1));
    monsters.push_back(new Vampire(2, 2));
    monsters.push_back(new Jiangshi(3, 3));
    monsters.push_back(new Siangshi(4, 4));   // 슈퍼 강시
    monsters.push_back(new Ghost(5, 5));
    monsters.push_back(new Smombi(6, 2));     // 스몸비
    monsters.push_back(new Cyclone(7, 3));    // 사용자 정의 몬스터

    int moveCount = 0;

    // 게임 루프
    while (moveCount < maxMoves) {
        cout << "Move #" << moveCount + 1 << '\n';

        for (auto* m : monsters) {
            m->move(width, height);
            m->eat(*map);
        }

        checkStarvation(monsters);  // 에너지 0 제거
        map->display(monsters);     // 맵 출력

        cout << "------------------------\n";

        if (map->allItemsCollected() || monsters.empty()) {
            cout << (monsters.empty() ? "모든 몬스터가 사라졌습니다!\n" : "모든 아이템을 수집했습니다!\n");
            break;
        }

        moveCount++;
    }

    // 최종 결과
    cout << "\n최종 결과:\n";
    for (auto* m : monsters)
        m->print();

    // 메모리 해제
    for (auto* m : monsters)
        delete m;
    delete map;

    return 0;
}
