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
	void	read( char* msg = " ���Ҽ� �Է� =" );
	void	print( char* msg = "���Ҽ� = " );
	void	add( Complex a, Complex b );
};
