#include 	<cstdio>

int& getCount() {
	static int count = 0;
	count++;
	// ... �Լ� ������ ó���� �ڵ�
	return count;
}
void main()
{
	for (int i = 0; i<5; i++)
		printf("count = %d\n", getCount());
	getCount() = 10;		// getCount()���� ���� ���� count�� 10�� ����
	for (int i = 0; i<5; i++)
		printf("count = %d\n", getCount());
}