//如何将字符串s1转化成s2，可以用删除、插入、替换；
//i是指s1的长度；j是指s2的长度
#include<iostream> 
using namespace std;
#include<string>
#include <cstring>       //字符串标准函数库 
#include <algorithm>     //使用min函数 
int convert_word1(const string s1, const string s2)
{
    int m = s1.length();
    int n = s2.length();
    //申请动态内存数组
    int** dp = new int* [m + 1];
    for (int i = 0; i < m + 1; i++) {
        dp[i] = new int[n + 1];
    }
    //赋予初值 
    for (int i = 0; i < m + 1; i++) //如果s1长度为i，s2长度为0，需要i步删除
        dp[i][0] = i;
    for (int j = 0; j < n + 1; j++) //如果s1长度为0，s2长度为j，需要i步插入
        dp[0][j] = j;
    //数组元素之间的关系 
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (s1[i - 1] == s2[j - 1])       //如果s1的第i个和s2的第j个一样 
                dp[i][j] = dp[i - 1][j - 1];
            else                              //如果s1的第i个和s2的第j个不一样
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
        }        //上面dp[i][j-1]是需要插入的情况；dp[i-1][j]是需要删除的情况；dp[i-1][j-1]是需要替换的情况；
    }
    return dp[m][n];
}