#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class Monster; // 몬스터 클래스 전방 선언

// ======================= Matrix =========================
// 게임 맵을 담당하는 클래스 (2차원 맵 + 아이템 상태)
class Matrix {
private:
    int width, height;
    vector<vector<char>> grid; // '*' = 아이템, '.' = 없음

public:
    Matrix(int h, int w) : height(h), width(w), grid(h, vector<char>(w, '*')) {}

    char get(int y, int x) const { return grid[y][x]; }
    void set(int y, int x, char val) { grid[y][x] = val; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // 아이템이 모두 수집되었는지 확인
    bool allItemsCollected() const {
        for (const auto& row : grid)
            for (char cell : row)
                if (cell == '*') return false;
        return true;
    }

    // 몬스터 상태 포함하여 맵 출력
    void display(const vector<Monster*>& monsters) const;
};

// ======================= Monster =========================
// 몬스터 추상 클래스 (기본 속성 및 인터페이스 정의)
class Monster {
protected:
    int x, y;
    char shape; // 출력 기호 (Z, V, 등)
    int items;  // 먹은 아이템 수
    int nEnergy; // 에너지
    static int count; // 전체 몬스터 수

public:
    Monster(int x, int y, char shape)
        : x(x), y(y), shape(shape), items(0), nEnergy(100) {
        count++;
    }
    virtual ~Monster() { count--; }

    // 자식 클래스에서 반드시 정의해야 하는 이동 함수
    virtual void move(int width, int height) = 0;

    // 현재 칸에 아이템이 있다면 먹고 에너지 회복
    void eat(Matrix& map) {
        if (map.get(y, x) == '*') {
            items++;
            nEnergy += 8;
            map.set(y, x, '.');
        } else {
            nEnergy = max(0, nEnergy - 1);
        }
    }

    void print() const {
        cout << shape << " 몬스터 - 아이템: " << items << ", 에너지: " << nEnergy << '\n';
    }

    int getX() const { return x; }
    int getY() const { return y; }
    char getShape() const { return shape; }
    int getEnergy() const { return nEnergy; }

    static void printCount() {
        cout << "현재 몬스터 수: " << count << '\n';
    }
};

int Monster::count = 0;

// ======================= Monster Types =========================
// 다양한 종류의 몬스터들 (고유한 이동 방식 구현)
class Zombie : public Monster {
public:
    Zombie(int x, int y) : Monster(x, y, 'Z') {}
    void move(int width, int height) override {
        static const int dx[8] = {-1,-1,-1,0,1,1,1,0};
        static const int dy[8] = {-1,0,1,1,1,0,-1,-1};
        int dir = rand() % 8;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) x = nx, y = ny;
    }
};

class Vampire : public Monster {
public:
    Vampire(int x, int y) : Monster(x, y, 'V') {}
    void move(int width, int height) override {
        static const int dx[4] = {0,1,0,-1};
        static const int dy[4] = {-1,0,1,0};
        int dir = rand() % 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) x = nx, y = ny;
    }
};

class Jiangshi : public Monster {
protected:
    bool horizontal; // true: 좌우 / false: 상하

public:
    Jiangshi(int x, int y) : Monster(x, y, 'J'), horizontal(rand() % 2) {}
    void move(int width, int height) override {
        int dir = rand() % 2 == 0 ? -1 : 1;
        int steps = rand() % 3 + 1;
        int nx = x, ny = y;
        if (horizontal) nx += dir * steps;
        else ny += dir * steps;
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) x = nx, y = ny;
    }
};

class Siangshi : public Jiangshi {
private:
    int tick;

public:
    Siangshi(int x, int y) : Jiangshi(x, y), tick(0) { shape = 'S'; }
    void move(int width, int height) override {
        if (++tick % 5 == 0) horizontal = !horizontal;
        Jiangshi::move(width, height);
    }
};

class Smombi : public Monster {
public:
    Smombi(int x, int y) : Monster(x, y, 'M') {}
    void move(int width, int height) override {
        static const int dx[4] = {-1,-1,1,1};
        static const int dy[4] = {-1,1,-1,1};
        int dir = rand() % 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) x = nx, y = ny;
    }
};

class Cyclone : public Monster {
private:
    int direction;
public:
    Cyclone(int x, int y) : Monster(x, y, 'C'), direction(0) {}
    void move(int width, int height) override {
        static const int dx[8] = {-1,-1,-1,0,1,1,1,0};
        static const int dy[8] = {-1,0,1,1,1,0,-1,-1};
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        direction = (direction + 1) % 8;
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) x = nx, y = ny;
    }
};

class Ghost : public Monster {
public:
    Ghost(int x, int y) : Monster(x, y, 'G') {}
    void move(int width, int height) override {
        x = rand() % width;
        y = rand() % height;
    }
};

// Human 클래스 (기본적으로 움직이지 않음)
class Human : public Monster {
public:
    Human(int x, int y) : Monster(x, y, 'H') {}
    void move(int width, int height) override {}
};

// Tuman 클래스: 사용자가 조작하는 인간
class Tuman : public Human {
public:
    Tuman(int x, int y, char icon) : Human(x, y) { shape = icon; }

    // 키보드 입력(WASD, 화살표)에 따라 이동
    void moveHuman(char input, int width, int height) {
        int nx = x, ny = y;
        switch (input) {
            case 'w': case 'W': ny--; break;
            case 's': case 'S': ny++; break;
            case 'a': case 'A': nx--; break;
            case 'd': case 'D': nx++; break;
            case 72: ny--; break; // ↑
            case 80: ny++; break; // ↓
            case 75: nx--; break; // ←
            case 77: nx++; break; // →
        }
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) x = nx, y = ny;
    }
};
