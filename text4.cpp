//回溯算法：今有7对数字：两个1，两个2，两个3，…两个7，把它们排成一行。
//要求，两个1间有1个其它数字，两个2间有2个其它数字，以此类推，两个7之间有7个其它数字。如下就是一个符合要求的排列
//17126425374635
//求以74开头的排列法
#include<iostream>
using namespace std;
int num[15] = { 0,7,4,0,0,0,0,4,0,7,0,0,0,0,0 };
int dfs(int n) {
	if (n == 4)  dfs(n + 1);
	if (n == 7) {
		for (int i = 1; i <= 14; i++)
			cout << num[i];
	}
	for (int i = 1; i <= 14; i++) {
		if (i == 1 || i == 2 || i == 7 || i == 9)  continue;
		int flag = i + n + 1;
		if (flag > 14) continue;
		if (num[i] == 0 && num[flag] == 0) {
			num[i] = n; num[flag] = n;
			dfs(n + 1);
			num[i] = 0; num[flag] = 0;
		}
	}
	return 0;
}

int main4(){
	dfs(1);
	system("pause");
	return 0;
}