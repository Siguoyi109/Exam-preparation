/*��һ������Ϊm��m <= 240����������������ȡ��k��k < n��������ʹʣ���������ԭ���Ĵ��򲻱䣬
���������������ɾ��֮����С�Ƕ��١�
����ֻ��Ҫ�ҵ���һ���������е�ĩβ��ȡ�����Ϳ�����ɹ�����ˡ��ֲ������Ž⡱*/
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