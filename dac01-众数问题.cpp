/*�ҳ������������е�����������������������г��ֵĴ�����������
����һ�����飬�����Ҽ����м�Ԫ����������������������ɨ�跨����λ�������м�����ȵ�����������Ϊ[p,r]��
������Ϊmidcnt,������ͨ��p,r������ֳ������Σ�������Ҫ����Ӧ������[left,p-1]��[r+1,right]�ֱ���չ������
�����������Ƿ���������*/
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
    p = i;//mid����߽�
    for (i = p + 1; i <= right; i++) {
        if (a[i] != a[mid]) 
            break;
    }
    r = i - 1;//mid���ұ߽�
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