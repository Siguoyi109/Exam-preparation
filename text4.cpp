//�����㷨������7�����֣�����1������2������3��������7���������ų�һ�С�
//Ҫ������1����1���������֣�����2����2���������֣��Դ����ƣ�����7֮����7���������֡����¾���һ������Ҫ�������
//17126425374635
//����74��ͷ�����з�
#include<iostream>
using namespace std;
int num[15] = { 0,7,4,0,0,0,0,4,0,7,0,0,0,0,0 };
int dfs(int n) {
	if (n == 4)  dfs(n + 1);
	if (n == 7) {
		for (int i = 1; i <= 14; i++)
			cout << num[i];
	}
	for (int i = 1; i <= 14; i++) {
		if (i == 1 || i == 2 || i == 7 || i == 9)  continue;
		int flag = i + n + 1;
		if (flag > 14) continue;
		if (num[i] == 0 && num[flag] == 0) {
			num[i] = n; num[flag] = n;
			dfs(n + 1);
			num[i] = 0; num[flag] = 0;
		}
	}
	return 0;
}

int main4(){
	dfs(1);
	system("pause");
	return 0;
}