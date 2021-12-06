//半数集问题
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
//延伸是半数单集问题；这是个数学问题；先不写了