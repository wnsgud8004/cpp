#include <iostream>
using namespace std;

void main()
{
	const double phi = 3.14;
	//phi = 3.5;		// Error: ��� phi ���� ������ �� ����

	int x = 10, y = 20, z = 30, w = 40;
	int* px = &x;
	int* const py = &y;	// py ��ü�� ���� �Ұ�
	const int* pz = &z;	// pz�� ����Ű�� �ּ��� ���� ���� �Ұ�
	const int* const pw = &w; // pw�� ����Ű�� �ּ��� ���� ��� ���� �Ұ�

	cout << " x=" << x << " y=" << y << " z=" << z << " w=" << w << endl;
	*px = 100;
	*py = 100;
	//*pz = 100;		// Error: pz�� ����Ű�� �ּ��� ���� ������ �� ����
	//*pw = 100;		// Error: pw�� ����Ű�� �ּ��� ���� ������ �� ����
	cout << " x=" << x << " y=" << y << " z=" << z << " w=" << w << endl;

	cout << " px=" << px << " py=" << py << " pz=" << pz << " pw=" << pw << endl;
	px = &y;
	pz = &w;
	//py = &x;		// Error: py�� ��(�ּ�)�� ������ �� ����
	//pw = &z;		// Error: pw�� ��(�ּ�)�� ������ �� ����
	cout << " *px=" << *px << " y=" << y << " *pz=" << *pz << " w=" << w << endl;
}