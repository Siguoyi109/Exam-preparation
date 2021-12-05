//用快排思想求一个序列的第k小的数；
#include<iostream>
using namespace std;
int a1[1000010];
void swap(int i, int j) {
	int t = a1[i];
	a1[i] = a1[j];
	a1[j] = t;
}
int patrition(int x, int y) {
	int i = x,j = y;
	int p = a1[x];
	while (i < j) {
		while (i < j && a1[j] >= p) j--;
		while (i < j && a1[i] <= p) i++;
		swap(i, j);
	}
	swap(i, x);
	return i;
}
void solve(int x, int y,int k) {
	int p = patrition(x, y);
	if (p + 1 == k) {
		cout << a1[p] << endl;
	}
	else if (p + 1 > k) solve(x, p - 1, k);
	else solve(p + 1, y, k);
}
int main2()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a1[i];
	solve(0, n - 1, k);
	system("pause");
	return 0;
}