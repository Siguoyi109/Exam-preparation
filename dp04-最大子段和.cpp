//��̬�滮������Ӷκ�����
#include<iostream>
using namespace std;

int maxsum(int n, int* a) {
	int sum = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (b > 0)
			b += a[i];
		else
			b = a[i];
		if (b > sum)
			sum = b;
	}
	return sum;
}