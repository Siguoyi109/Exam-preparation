//最长有序子序列
#include<iostream>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b);

int main3() {
	int n;
	cin >> n;
	int a[100010], dp[100010];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int m = 0;
	for (int i = 0; i < n; i++)
		m = max(m, dp[i]);
	cout << m << endl;
	return 0;
}