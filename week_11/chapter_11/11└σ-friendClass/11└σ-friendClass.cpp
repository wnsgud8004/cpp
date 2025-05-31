#pragma once
#include <cstdio>

class Point {
	int x, y;			// private ���
	friend class Shape;
	friend class Line;
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { }
	void print(char *s = "��") { printf("%s(%d,%d)", s, x, y); }
};

class Shape {
protected:
	Point	p;		// ��ġ
public:
	Shape(int x = 0, int y = 0) : p(x, y) { }
	void draw() { printf("[ ���� ] ��ġ=(%d,%d)\n", p.x, p.y); }
};

class Line : public Shape {
	Point	q;
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : Shape(x1, y1), q(x2, y2) { }
	void draw() {
		printf("[ ���� ] P1=(%d,%d) P2=(%d,%d)\n", p.x, p.y, q.x, q.y);
	}
};

void main() {
	Line l(3, 4, 5, 6);
	l.draw();
}