/*一辆汽车加满油后可以行驶n km。中间有若干个加油站。设计一个算法；
指出最少加油次数。*/
#include<iostream>
#include<vector>
using namespace std;
int greedy(vector<int>x, int n) {
	int sum = 0, k = x.size();
	for (int j = 0; j < k; j++) {
		if (x[j] > n) {    //代表某两个加油站之间的距离大于最大行驶里程n；
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