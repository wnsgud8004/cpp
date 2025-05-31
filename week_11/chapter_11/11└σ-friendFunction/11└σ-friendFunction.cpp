#pragma once
#include <cstdio>

class Point {
	int x, y;		// private ���
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { }
	void print(char *s = "��") { printf("%s(%d,%d)", s, x, y); }

	friend double avgPointX(Point* list, int n);	// ��� x�� ����ϴ� �Ϲ� �Լ�
	friend Point addPoint(Point& p, Point& q) {	// �� Point�� ���ϴ� �Ϲ� �Լ�
		Point	r;
		r.x = p.x + q.x;
		r.y = p.y + q.y;
		return r;
	}
	friend Point subPoint(Point& p, Point& q) {	// �� Point�� ���� �Ϲ� �Լ�
		return Point(p.x - q.x, p.y - q.y);
	}
};
// double Point::avgPointX(...)�� �ƴ�
double avgPointX(Point* list, int n) {	// friend �Լ��� �Ϲ��Լ���
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += list[i].x;
	return sum / n;
}

void main()
{
	Point arr[5] = { Point(0, 1), Point(2, 3), Point(4, 5) };
	arr[3] = addPoint(arr[0], arr[1]);
	arr[4] = subPoint(arr[2], arr[1]);
	for (int i = 0; i < 5; i++)
		arr[i].print();
	printf("\nAverage X = %lf\n", avgPointX(arr, 5));
}