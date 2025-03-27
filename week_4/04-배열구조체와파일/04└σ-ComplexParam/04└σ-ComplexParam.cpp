#include <cstdio>
struct Complex {
	double	real;
	double	imag;
};
void printComplex(Complex c, char* msg = "���Ҽ�") {
	printf("  %s %4.2f + %4.2fi\n", msg, c.real, c.imag);
}
Complex readComplex(char* msg="���Ҽ�") {
	Complex c;
	printf("  %s ", msg);
	scanf("%lf%lf", &c.real, &c.imag);
	return c;
}
Complex addComplex(Complex a, Complex b) {
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}
void resetComplex(Complex a) { a.real = a.imag = 0.0; }	// ???

void main()
{
	Complex a, b, c;
	a = readComplex("a(�Է�) = ");
	b = readComplex("b(�Է�) = ");
	c = addComplex(a, b);
	printComplex(a, "    a   =");
	printComplex(b, "    b   =");
	printComplex(c, "   a+b  =");
	resetComplex(c);
	printComplex(c, "reset(c)=");	// ???
}