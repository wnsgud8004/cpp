#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	int x = 1, y = 2;
	char s[100];

	ofstream f1("tmp.txt"); 		// ������ ���� ���� ����
	if (f1) {			// ���������� ��������
		f1 << x << " " << y << endl;	// ���Ϸ� int �� ����
		f1 << "Game Over !\n\n";	// ���Ϸ� ���ڿ� ����
	}
	f1.close();			// ���� �ݱ�

	ifstream f2("tmp.txt"); 		// �б⸦ ���� ���� ����
	if (f2) { 			// ���������� ��������
		f2 >> x >> y; 		// ���Ͽ������� x�� y �б�
		f2 >> s; 			// ���Ͽ������� ���ڿ� �б�
		cout << " x=" << x << " y=" << y << endl;
		cout << s << endl;
	}
	f2.close();			// ���� �ݱ�
}