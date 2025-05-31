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
	// ��� 1: ��� �Լ�
	void add(Complex a, Complex b) {
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}
	// ��� 2: �Ϲ� �Լ�
	friend Complex add(Complex a, Complex b) {
		return Complex(a.real + b.real, a.imag + b.imag);
	}
	// ��� 3: ��� �Լ�
	Complex add(Complex b) {
		return Complex(real + b.real, imag + b.imag);
	}
	// ��� 4: ������ �ߺ� �Լ� (��� �Լ��� ����)
	Complex operator+(Complex b) {
		return Complex(real + b.real, imag + b.imag);
	}
};
void main()
{
	Complex c1(1, 2), c2(3, 4), s1, s2, s3, s4;
	s1.add(c1, c2);
	s2 = add(c1, c2);
	s3 = c1.add(c2);
	s4 = c1 + c2;
	s1.print("s1.add(c1,c2) : ");
	s2.print("s2=add(c1,c2) : ");
	s3.print("s3=c1.add(c2) : ");
	s4.print("s4= c1 + c2   : ");
}