#include <cstdio>
void main()
{
	short n = 0;
loop:
	n = n + 1;
	if (n > 0) {
		printf("\r short �ִ� = %d", n);
		goto loop;
	}
	printf("\n�����÷ο� �߻�\a\n");
	printf(" short �ּڰ� = %d\n", n);
}