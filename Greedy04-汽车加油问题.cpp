/*һ�����������ͺ������ʻn km���м������ɸ�����վ�����һ���㷨��
ָ�����ټ��ʹ�����*/
#include<iostream>
#include<vector>
using namespace std;
int greedy(vector<int>x, int n) {
	int sum = 0, k = x.size();
	for (int j = 0; j < k; j++) {
		if (x[j] > n) {    //����ĳ��������վ֮��ľ�����������ʻ���n��
			cout << "No Solution!" << endl;
			return -1;
		}
		for (int i = 0, s = 0; i < k; i++) {
			s += x[i];
			if (s > n) { sum++; s = x[i]; }
		}
	}
	return sum;
}