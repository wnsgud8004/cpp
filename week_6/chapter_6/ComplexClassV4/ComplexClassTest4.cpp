#include "Complex.h"

void main()
{
	Complex a, b, c, d, e;

	a.read ( "A =" );
	b.read ( "B =" );
	c.add(a,b);		// add() �Լ��� �ٸ� ����
//	c = a.add(b);		// add() �Լ��� �ٸ� ����
//	d = a + b;			// ������ �����ε�
//	e = a.operator+(b);	// ������ �����ε�

	a.print ( "    A     = ");
	b.print ( "    B     = ");
	c.print ( "C.add(A,B)= ");
//	d.print ( "D=A+B           = ");
//	e.print ( "E=A.operator(B) = ");
}