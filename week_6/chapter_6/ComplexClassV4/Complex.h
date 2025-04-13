#pragma once
#include <cstdio>

// ���Ҽ� Ŭ���� ����
class Complex
{
	double	real;
	double	imag;
public:
	// ���Ҽ� ������ �����ϴ� �Լ� : inline
	void set( double r, double i ) {
		real = r;
		imag = i;
	}
	void read( char* msg = " ���Ҽ� �Է� ="  ) {
		printf("  %s ", msg);
		scanf("%lf%lf", &real, &imag);
	}
	void print( char* msg = "���Ҽ� = "  ) {
		printf("  %s %4.2f + %4.2fi\n", msg, real, imag);
	}

	// ���ϱ� / ���� ���� ����Լ� �߰�
	void add( Complex a, Complex b ) {
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}
	/*
	// ���ϱ� / ���� ���� ����Լ� �߰�
	Complex add( Complex b ) {
		Complex c;
		c.real = real + b.real;
		c.imag = imag + b.imag;
		return c;
	}
	
	Complex operator+( Complex b ) { return add(b); }
	*/
};
