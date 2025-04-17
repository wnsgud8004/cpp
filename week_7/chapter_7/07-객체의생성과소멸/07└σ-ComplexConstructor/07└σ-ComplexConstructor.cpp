
/*
class Complex {
	double real, imag; 		// ��� ����. �Ǽ��ο� �����
public:
	Complex() { real = imag = 0.0; } 	// �⺻ ������
	Complex(double r, double i) { 	// �Ű� ������ �ִ� ������
		real = r;		// r�� ��� ���� real�� ����
		imag = i;		// i�� ��� ���� imag�� ����
	}
	//...				// ���� ���� ��� �Լ� �߰�
};

class Complex {
	double real, imag;
public:
	Complex(double r = 0, double i = 0) { 	// ����Ʈ ������ ��� ������
		real = r;		// r�� ��� ���� real�� ����
		imag = i;		// i�� ��� ���� imag�� ����
	}
	//...
};
*/

class Complex {
	double real, imag;
public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) { }
	//...
};

void main() { }