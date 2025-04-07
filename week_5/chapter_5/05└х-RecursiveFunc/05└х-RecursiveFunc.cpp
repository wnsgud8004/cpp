int factorial(int n)
{
	if (n == 1) return 1;					// ���� ���� �˻� �ڵ�
	else return (n * factorial(n - 1));		// ��� ȣ�� �ڵ�
}

int factorial_iter(int n)
{
	int result = 1;
	for (int k = n; k>0; k--)
		result = result * k;
	return result;
}

int fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fibonacci(n - 1) + fibonacci(n - 2));
}

int fibonacci_iter(int n)
{
	if (n < 2) return n;
	else {
		int tmp, current = 1, last = 0;
		for (int i = 2; i <= n; i++) {
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

#include <cstdio>
void main()
{
	printf("5! = %d\n", factorial(5));
	printf("5! = %d\n", factorial_iter(5));
	printf("fibo(5) = %d\n", fibonacci(5));
	printf("fibo(5) = %d\n", fibonacci_iter(5));
}