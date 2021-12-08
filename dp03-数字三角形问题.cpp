//给定一个由n行数字组成的数字三角形；设计出从三角形的顶至底的一条路径；使该路径经过的数字总和最大
//动态规划题：以自底向上的方式递归计算
#include <iostream>
#include <algorithm>
#include "string.h"
#define Max 101
using namespace std;
int D[Max][Max];     //D[i][j]是指第i行的第j个数，到底边的最大数字总和
int num;
int MaxSum(int num) {
    int i, j;
    for (i = num - 1; i >= 1; i--)
        for (j = 1; j <= i; j++)
            D[i][j] = max(D[i + 1][j], D[i + 1][j + 1]) + D[i][j];
    return D[1][1];
}
int main(int argc, char const* argv[]){
    int i, j;
    cin >> num;
    for (i = 1; i <= num; i++)
        for (j = 1; j <= i; j++)
            cin >> D[i][j];
    cout << MaxSum(num) << endl;
    return 0;
}
