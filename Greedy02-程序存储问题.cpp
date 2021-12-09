//最简单的贪心:设有n个程序存放在L的磁带上；程序i在磁带上的长度是li;
//要求确定这N个程序在磁带上的存储方案；使磁带尽可能多存程序
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int greedy(vector<int>x, int m) {
	int i = 0 , sum = 0, n = x.size();
	sort(x.begin(), x.end());
	while (i < n) {
		sum += x[i];
		if (sum <= m) i++;
		else return i;
	}
	return 0;
}