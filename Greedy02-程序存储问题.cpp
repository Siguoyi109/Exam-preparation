//��򵥵�̰��:����n����������L�ĴŴ��ϣ�����i�ڴŴ��ϵĳ�����li;
//Ҫ��ȷ����N�������ڴŴ��ϵĴ洢������ʹ�Ŵ������ܶ�����
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