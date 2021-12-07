//最经典的01背包问题；仔细体会
//n种物品，i的重量是wi，价值为vi，背包的容量为c；m(i,j)是指背包容量为j，可选择物品为i，i+1,...,n时背包的最优值
#include<iostream>
using namespace std;
template<class Type>    

//这个算法是从下往上写二维数组的；这样在回溯的时候会比较方便；
void  knapsack(Type *v, int *w, int c, int n, Type** m) {
	int jmax = min(w[n] - 1, c);    //这里是做了个分段；在jmax之后的就不变了；
	for (int j = 0; j <= jmax; j++)  //初始化
		m[n][j] = 0;
	for (int j = w[n]; j <= c; j++)
		m[n][j] = v[n];
	for (int i = n - 1; i > 1; i--) {
		jmax = (w[i] - 1, c);
		for (int j = 0; j <= jmax; j++)
			m[i][j] = m[i + 1][j];
		for (int j = w[i]; j <= c; j++)
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
	}
	m[1][c] = m[2][c];
	if (c >= w[1])
		m[1][c] = max(m[1][c], m[2][c - w[i]] + v[1]);
}

template<class Type>
void traceback(Type **m, int *w, int c, int n, int* x) {
	for (int i = 1; i < n; i++) {
		if (m[i][c] == m[i + 1][c])
			x[i] = 0;
		else {
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;   //判断最后一个；
}