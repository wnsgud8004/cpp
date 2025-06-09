#include "Rational.h"

void main()
{
	Rational r;
	cout << "r �Է�(a/b): ";
	try {
		cin >> r;
	}
	catch (char c) {
		cout << "���� �߻�: �м����� �и� 0�Դϴ�.\n";
		cout << "�� ������ �� �����ϴ�.\n";
		exit(0);
	}
	catch (NegBotException e) {
		r = Rational(-e.top, -e.bottom);
		cout << "���� �߻�: �и� ����� ��ȯ�մϴ�.\n";
	}
	cout << "r = " << r << endl;
	cout << "r = " << r.real() << endl;
}