//设有n 个顾客同时等待一项服务。顾客i需要的服务时间为t i n i, 1 £ £ 。共有s 处可以
//提供此项服务。应如何安排n 个顾客的服务次序才能使平均等待时间达到最小 ? 平均等待时
//间是n个顾客等待服务时间的总和除以n。
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
double greedy(vector<int>x, int s) {
	vector<int>st(s + 1, 0);
	vector<int>su(s + 1, 0);
	int n = x.size();
	sort(x.begin(), x.end());
	int i = 0, j = 0;
	while (i < n) {
		st[j] += x[i];    //在第j处处理的任务运行时间之和
		su[j] += st[j];     //在第j处处理的任务等待时间之和
		i++; j++;
		if (j == s)  j = 0;
	}
	double t = 0;
	for (i = 0; i < s; i++)
		t += su[i];
	t /= n;
	return t;
}