#include <iostream>
using namespace std;

class Vector {
	int dim;		// ������ ����
	double* arr;	// ������ �� ���� ������
public:
	Vector(int d = 0) : dim(d) { arr = new double[dim]; }
	~Vector() { delete[] arr; }

	void setRand(int max = 100) {
		for (int i = 0; i<dim; i++)
			arr[i] = rand() % (max * 10) / 10.0;
	}
	void print(char *str = "Vector") {
		cout << str << "[" << dim << "] = < ";
		for (int i = 0; i < dim; i++)
			cout << arr[i] << " ";
		cout << ">\n";
	}
};
void main()
{
	Vector	u(3), v(5);
	u.setRand();
	v = u;
	u.print(" U ");
	v.print(" V ");
}