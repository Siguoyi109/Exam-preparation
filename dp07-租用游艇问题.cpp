#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    int m[200][200] = { 0 };
    cin >> n;
    for (int i = 1; i <= n - 1; i++){   //��ʼ����������r(i,j)���ȴ�������m��
        for (int j = i + 1; j <= n; j++)
            cin >> m[i][j];
    }
    for (int r = 2; r <= n; r++){  //���Ŵӳ���Ϊ 2 �Ŀ�ʼ�ҽ��Ž⣨����˵�� 1 �� 2 ���ǳ���Ϊ 2�ģ���ֱ���ҵ�����Ϊ n ��
        for (int i = 1; i <= n - r + 1; i++){
            int j = i + r - 1;     // r(i��j)�ĳ���Ϊr
            for (int k = i; k <= j; k++){     //�� i �� j ����ĳһվ k��ʹ��r(i,k)+r(k,j)��С
                int t = m[i][k] + m[k][j];
                if (t < m[i][j])
                    m[i][j] = t;//�ý��Ž��滻ԭ����r(i,j)
            }
        }
    }
    cout << m[1][n] << endl;
    system("pause");
    return 0;
}