/*找出给定递增序列的众数，并求出众数在序列中出现的次数（重数）
对于一个数组，首先我假设中间元素是众数，并且用区间内扫描法来定位所有与中间数相等的数，区间标记为[p,r]，
个数记为midcnt,这样就通过p,r将区间分成了三段，接下来要做的应该是向[left,p-1]和[r+1,right]分别拓展，看这
两个区间内是否会出现众数*/
#include<iostream> 
using namespace std;
int a[] = { 1,1,2,2,2,3,3,3,3,3,4,4,5,6,7,7,7 };
int len = sizeof(a) / sizeof(a[0]);
int num;
int cnt = 0;
void pos(int left, int right, int mid, int& p, int& r) {
    int i;
    for (i = left; i <= right; i++) {
        if (a[i] == a[mid])
            break;
    }
    p = i;//mid的左边界
    for (i = p + 1; i <= right; i++) {
        if (a[i] != a[mid]) 
            break;
    }
    r = i - 1;//mid的右边界
}
void getMaxCnt(int left, int right) {
    int mid = (left + right) / 2;
    int p;
    int r;
    pos(left, right, mid, p, r);
    int midcnt = r - p + 1;
    if (midcnt > cnt) {
        num = a[mid];
        cnt = midcnt;
    }
    if (p - left > cnt) 
        getMaxCnt(left, p - 1);
    if (right - r - 1 > cnt) 
        getMaxCnt(r + 1, right);
}
int main() {
    getMaxCnt(0, len - 1);
    cout << num << endl;
    cout << cnt << endl;
    return 0;
}