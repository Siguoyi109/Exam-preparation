//����������
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int comb(int n) {
    int ans = 1;
    if (n > 1)
        for (int i = 1; i <= n / 2; i++)
            ans += comb(i);
    return ans;
}
int main() {
    int n;
    while (scanf_s("%d", &n) != EOF) {
        cout << comb(n) << endl;
    }
    return 0;
}
//�����ǰ����������⣻���Ǹ���ѧ���⣻�Ȳ�д��