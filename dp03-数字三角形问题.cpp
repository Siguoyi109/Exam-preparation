//����һ����n��������ɵ����������Σ���Ƴ��������εĶ����׵�һ��·����ʹ��·�������������ܺ����
//��̬�滮�⣺���Ե����ϵķ�ʽ�ݹ����
#include <iostream>
#include <algorithm>
#include "string.h"
#define Max 101
using namespace std;
int D[Max][Max];     //D[i][j]��ָ��i�еĵ�j���������ױߵ���������ܺ�
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
