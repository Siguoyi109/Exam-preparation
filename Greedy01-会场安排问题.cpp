//�᳡�������⣺����Ҫ���㹻��Ļ᳡�ﰲ��һ�������ϣ��ʹ�þ������ٵĻ᳡��
//���һ����Ч��̰���㷨���а��š����ڸ�����k�������ŵĻ������ʹ�����ٻ᳡��ʱ���
#include<iostream>
#include<cstdio>
using namespace std;
struct ans {   //����ṹ���ʾ� 
	int begin, end;
	bool flag; //���ñ�־ 
};
int arrange(int k, ans* a){
	int count = k, room_avail = 0, room_num = 0;
	while (count > 0){
		for (int i = 1; i <= k; i++){
			if ((a[i].begin > room_avail) && (a[i].flag == 0)) { //�����ǰ�δ���Ų��Һͻ᳡���л����ͻ 
				room_avail = a[i].end;  //����ǰ�����û᳡�����»᳡�Ŀ���ʱ��
				a[i].flag = 1;
				count--;
			}
		}
		room_avail = 0;  //��room_avail��ʼ��
		room_num++;   //����һ�Σ�ʹ�õĻ᳡����һ 
	}
	return room_num; //���ذ��ŵĻ᳡�� 
}
int main(){
	int k, room_num;
	cin >> k;
	ans *a=new ans[k+1];
	for (int i = 1; i <= k; i++){
		cin >> a[i].begin >> a[i].end;
		a[i].flag = 0;
	}
	room_num = arrange(k, a);
	cout << room_num << endl;
	return 0;
}