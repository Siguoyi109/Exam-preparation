/*有一个长度为m（m <= 240）的正整数，从中取出k（k < n）个数，使剩余的数保持原来的次序不变，
求这个正整数经过删数之后最小是多少。
我们只需要找到第一个升序数列的末尾并取出它就可以算成功完成了“局部的最优解”*/
#include<iostream>
using namespace std;
string a; int k;
void delek() {
	int m = a.size();
	if (k >= m) { a.erase(); return; }
	while (k > 0) {
		for (int i = 0; (i < a.size() - 1) && (a[i] <= a[i + 1]); i++)
			a.erase(i, 1); k--;
	}
	while (a.size() > 1 && a[0] == '0')   a.erase(0, 1);
}