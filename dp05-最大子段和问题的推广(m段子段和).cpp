//����Ӷκ�������ƹ㣻���m�Ӷκͣ�
//������n������������Ϊ������ɵ�����a1��a2��a3...,an, �Լ�һ��������m��Ҫ��ȷ�����е�m�����ཻ�ӶΣ�ʹ��m���Ӷε��ܺ����
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
//���вο��𰸣�b(i,j)��ʾ����a��ǰj����i���Ӷκ͵����ֵ���ҵ�i���Ӷκ�a[j]
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


//���ϵĴ𰸣�
int n, m;
ll a[N], dp[2][N];   //ֻ������һ�к͵�ǰ�� 
int main()
{
    while (~scanf_s("%d%d", &n, &m))   //n�����֣�m�Ӷκ� 
    {
        for (int i = 1; i <= n; i++)
            scanf_s("%lld", a + i);
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0, dp[1][i] = 0;    //�ؼ��������ֻ������ֵ

        for (int i = 1, k = 1; i <= m; i++, k ^= 1)    //��Ϊi�Σ�kΪ����֮����л�
        {
            dp[k][i - 1] = -INF;   //i==jʱ���ž���ǰһԪ�ع���
            ll maxpre = -INF;    //maxpre��¼��һ�е����ֵ
            for (int j = i; j <= n - m + i; j++)
            {
                maxpre = max(maxpre, dp[k ^ 1][j - 1]);     //��ʱ������һ�����ֵ
                dp[k][j] = max(dp[k][j - 1], maxpre) + a[j]; //*�����1��2��ѡ��
            }
        }
        ll ans = -INF;
        for (int i = m; i <= n; i++)   //�ҵ���m�е����ֵ����Ϊ��
            ans = max(ans, dp[m & 1][i]);
        printf_s("%lld\n", ans);
    }
}