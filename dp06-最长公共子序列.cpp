//��������������⣻mΪ����x��Ԫ�ظ�����nΪ����y��Ԫ�ظ���������������еĳ��ȴ���c[m][n]�У�
//b[i][j]��¼��c[i][j]��ֵ�����ĸ�������Ľ�õ��ģ�
#include<iostream>
using namespace std;
void LCSlength(int m, int n, char* x, char* y, int** c, int** b) {
	int i, j;
	for (i = 1; i <= m; i++)
		c[i][0] = 0;
	for (i = 1; i <= n; i++)
		c[0][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] == x[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
}
void LCS(int i, int j, char *x, int ** b) {
	if (i == 0 || j == 0) return;
	if (b[i][j] == 1) {
		LCS(i - 1, j - 1, x, b);
		cout << x[i];
	}
	else if (b[i][j] == 2) {
		LCS(i - 1, j, x, b);
	}
	else
		LCS(i, j - 1, x, b);
}