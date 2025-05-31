#include <cstdio>

class Complex
{
	double	real;
	double	imag;
public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {  }
	void print(char* msg = "���Ҽ� = ") {
		printf("  %s %4.2f + %4.2fi\n", msg, real, imag);
	}

	// ��� ���� - : -c(����, negation)
	Complex operator-() { return Complex(-real, -imag); }
	// ��� ���� ~ : ~c �ӷ� ���Ҽ� (�ǹ̰� �ָ��ϹǷ� �ߺ����� �ʴ� ���� �� ����)
	Complex operator~() { return Complex(real, -imag); }

	// ��� ���� - : a - b
	Complex operator-(Complex b) {
		return Complex(real - b.real, imag - b.imag);
	}
	// ��� * : ���Ҽ��� ��Į���� ��. c*s�� s*c ������ ���� �ٸ� �����ڿ� ���� ó����
	Complex operator*(double s) { return Complex(s*real, s*imag); }
	friend Complex operator*(double s, Complex c) {	// �Ϲ� �Լ��� !!! 
		return Complex(s*c.real, s*c.imag);
	}

	// �� : c1 == c2, c1 != c2
	bool operator==(Complex a) { return real == a.real && imag == a.imag; }
	bool operator!=(Complex a) { return real != a.real || imag != a.imag; }
	// �ٸ� �� ������ >, <, >=, <=, ���� ������ �ָ���. �ߺ����� �ʴ� ���� �ٶ�����.

	// ���� : c1=c2, c1+=c2, c1-=c2
	Complex& operator=(Complex a) { real = a.real; imag = a.imag; return *this; }
	Complex& operator+=(Complex a) { real += a.real; imag += a.imag; return *this; }
	Complex& operator-=(Complex a) { real -= a.real; imag -= a.imag; return *this; }
	// �ٸ� ���� ������ <<=, >>=, � ������ �ָ���. �ߺ����� �ʴ� ���� �ٶ�����.
};

void main()
{
	Complex c1(1, 2), c2(3, 4), c3, c4, c5, c6, c7, c8;

	c1.print("c1(1, 2)      : ");
	c2.print("c2(3, 4)      : ");
	c3 = -c1;
	c3.print("c3 = -c1      : ");
	c4 = ~c1;
	c4.print("c4 = ~c1      : ");
	c5 = c1 - c2;
	c5.print("c5 = c1 - c2  : ");
	c5 = c1 * 2.0;
	c5.print("c5 = c1 * 2.0 : ");
	c6 = 3.0 * c1;
	c6.print("c6 = 3.0 * c1 : ");
	c7 = c8 = c1;
	c7.print("c7 = c8 = c1  : ");
	c7 += c1;
	c7.print("c7 += c1      : ");
	c8 -= c1;
	c8.print("c8 -= c1      : ");
}
