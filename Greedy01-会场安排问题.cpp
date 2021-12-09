//会场安排问题：假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。
//设计一个有效的贪心算法进行安排。对于给定的k个待安排的活动，计算使用最少会场的时间表
#include<iostream>
#include<cstdio>
using namespace std;
struct ans {   //定义结构体表示活动 
	int begin, end;
	bool flag; //设置标志 
};
int arrange(int k, ans* a){
	int count = k, room_avail = 0, room_num = 0;
	while (count > 0){
		for (int i = 1; i <= k; i++){
			if ((a[i].begin > room_avail) && (a[i].flag == 0)) { //如果当前活动未安排并且和会场已有活动不冲突 
				room_avail = a[i].end;  //将当前活动加入该会场并更新会场的空闲时间
				a[i].flag = 1;
				count--;
			}
		}
		room_avail = 0;  //将room_avail初始化
		room_num++;   //遍历一次，使用的会场数加一 
	}
	return room_num; //返回安排的会场数 
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