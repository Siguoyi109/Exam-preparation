//贪心算法：乘船问题，每艘船只能做两人；求最小用船数
#include<iostream>
using namespace std;
#include<algorithm>
int n, c, ans = 0;
int a[10000];
int main1()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int i = 1, j = n;
	while (i < j) {
		if (a[i] + a[j] <= c) {
			ans += 1;
			i++; j--;
		}
		else 
			j--;
	}
	cout << ans + n - 2 * ans << endl;
	system("pause");
	return 0;
}