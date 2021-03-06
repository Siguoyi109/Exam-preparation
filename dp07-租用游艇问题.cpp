#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    int m[200][200] = { 0 };
    cin >> n;
    for (int i = 1; i <= n - 1; i++){   //初始化，将所有r(i,j)都先存在数组m中
        for (int j = i + 1; j <= n; j++)
            cin >> m[i][j];
    }
    for (int r = 2; r <= n; r++){  //接着从长度为 2 的开始找较优解（比如说从 1 到 2 就是长度为 2的），直到找到长度为 n 的
        for (int i = 1; i <= n - r + 1; i++){
            int j = i + r - 1;     // r(i，j)的长度为r
            for (int k = i; k <= j; k++){     //在 i 到 j 中找某一站 k，使得r(i,k)+r(k,j)最小
                int t = m[i][k] + m[k][j];
                if (t < m[i][j])
                    m[i][j] = t;//用较优解替换原来的r(i,j)
            }
        }
    }
    cout << m[1][n] << endl;
    system("pause");
    return 0;
}