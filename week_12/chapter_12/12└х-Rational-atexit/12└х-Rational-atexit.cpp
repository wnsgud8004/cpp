#include "Rational.h"

void onExit() { cout << "���α׷��� ����˴ϴ�!" << endl; }
void main() 
{
	atexit(onExit);
	Rational r;
	cout << "r �Է�(a/b): ";
	cin >> r;
	cout << "r = " << r << " = " << r.real() << endl;
}
