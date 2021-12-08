//最大子段和问题的推广；最大m子段和；
//给定由n个整数（可能为负）组成的序列a1、a2、a3...,an, 以及一个正整数m，要求确定序列的m个不相交子段，使这m个子段的总和最大！
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
//书中参考答案：b(i,j)表示数组a的前j项中i个子段和的最大值，且第i个子段含a[j]
int maxsum(int m, int n, int* a) {
    if (n < m || m < 1)  return 0;
    int** b = new int* [m + 1];
    for (int i = 0; i <= m; i++)
        b[i] = new int[n + 1];
    for (int i = 0; i <= m; i++)
        b[i][0] = 0;
    for (int j = 1; j < n; j++)
        b[0][j] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= n - m + i; j++) {
            if (j > i) {
                b[i][j] = b[i][j - 1] + a[j];
                for (int k = i - 1; k < j; k++)
                    if (b[i][j] < b[i - 1][k] + a[j])
                        b[i][j] = b[i - 1][k] + a[j];
            }
            else
                b[i][j] = b[i - 1][j - 1] + a[j];
        }
    }
    int sum = 0;
    for (int j = m; j <= n; j++)
        if (sum < b[m][j])
            sum = b[m][j];
    return sum;
}


//网上的答案：
int n, m;
ll a[N], dp[2][N];   //只保存上一行和当前行 
int main()
{
    while (~scanf_s("%d%d", &n, &m))   //n个数字，m子段和 
    {
        for (int i = 1; i <= n; i++)
            scanf_s("%lld", a + i);
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0, dp[1][i] = 0;    //关键！此题答案只允许正值

        for (int i = 1, k = 1; i <= m; i++, k ^= 1)    //分为i段，k为两行之间的切换
        {
            dp[k][i - 1] = -INF;   //i==j时，杜绝与前一元素共伍
            ll maxpre = -INF;    //maxpre记录上一行的最大值
            for (int j = i; j <= n - m + i; j++)
            {
                maxpre = max(maxpre, dp[k ^ 1][j - 1]);     //随时更新上一行最大值
                dp[k][j] = max(dp[k][j - 1], maxpre) + a[j]; //*对情况1、2的选择
            }
        }
        ll ans = -INF;
        for (int i = m; i <= n; i++)   //找到第m行的最大值，即为答案
            ans = max(ans, dp[m & 1][i]);
        printf_s("%lld\n", ans);
    }
}