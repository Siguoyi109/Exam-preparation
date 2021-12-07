//��ν��ַ���s1ת����s2��������ɾ�������롢�滻��
//i��ָs1�ĳ��ȣ�j��ָs2�ĳ���
#include<iostream> 
using namespace std;
#include<string>
#include <cstring>       //�ַ�����׼������ 
#include <algorithm>     //ʹ��min���� 
int convert_word1(const string s1, const string s2)
{
    int m = s1.length();
    int n = s2.length();
    //���붯̬�ڴ�����
    int** dp = new int* [m + 1];
    for (int i = 0; i < m + 1; i++) {
        dp[i] = new int[n + 1];
    }
    //�����ֵ 
    for (int i = 0; i < m + 1; i++) //���s1����Ϊi��s2����Ϊ0����Ҫi��ɾ��
        dp[i][0] = i;
    for (int j = 0; j < n + 1; j++) //���s1����Ϊ0��s2����Ϊj����Ҫi������
        dp[0][j] = j;
    //����Ԫ��֮��Ĺ�ϵ 
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (s1[i - 1] == s2[j - 1])       //���s1�ĵ�i����s2�ĵ�j��һ�� 
                dp[i][j] = dp[i - 1][j - 1];
            else                              //���s1�ĵ�i����s2�ĵ�j����һ��
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
        }        //����dp[i][j-1]����Ҫ����������dp[i-1][j]����Ҫɾ���������dp[i-1][j-1]����Ҫ�滻�������
    }
    return dp[m][n];
}