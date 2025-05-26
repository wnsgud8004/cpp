//1.클래스를 상속하여 Rectangle 클래스를 정의하라. Rectangle에는 가로와 세로 길이를 나타내는 width와 height라는 멤버가 추가되어야 한다.
//2.생성자에서 Point의 X, y와 Rectangle의 width, height를 초기화하라. 이때, 멤버 초기화 리스트를 사용하라.
//3. Rectangle 클래스에서 Point클래스에 있는 draw함수를 재정의 하라. 예를 들어, "2,3에 가로 100 세로 200인 사각형을 그려라"를 출력하면 된다.
//4.Point 클래스의 protected 키워드를 private로 바꾸면 어떻게 되는지 설명하라.

#include <iostream>
using namespace std;

// 기본 클래스: Point
class Point {
protected:  // 자식 클래스에서 접근 가능
    int x, y;

public:
    // 생성자 (초기화 리스트 사용)  
    Point(int xx, int yy) : x(xx), y(yy) {}

    // 점 그리기 함수
    void draw() {
        cout << x << "," << y << "에 점을 그려라.\n";
    }
};

// 파생 클래스: Rectangle
class Rectangle : public Point {
private:
    int width, height;

public:
    // 생성자: Point의 x, y를 부모 생성자에서 초기화하고, 나머지 width, height는 본 클래스에서 초기화
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) {}

    // draw() 함수 오버라이딩
    void draw() {
        cout << x << "," << y << "에 가로 " << width
             << " 세로 " << height << "인 사각형을 그려라.\n";
    }
};

int main() {
    Point p(1, 2);
    p.draw();  // "1,2에 점을 그려라."

    Rectangle r(2, 3, 100, 200);
    r.draw();  // "2,3에 가로 100 세로 200인 사각형을 그려라."

    return 0;
}
