#include <iostream>
#include <stdlib.h>
using namespace std;
long long ans;
int ok(char str[], int a, int b) //����b��Ԫ���Ƿ��ܷ��ڵ�a��λ��
{
    int i;
    if (b > a)                      //����ǰ����һ��Ԫ��a[i]��a[b]��ȣ�                 
        for (i = a; i < b; i++)     //��a[b]��ֵ�Ѿ��ڵ�a��λ�ó��ֹ����ٷ�������ط������ظ��ˡ�
            if (str[i] == str[b]) 
                return 0;
    return 1;
}
void perm(char str[], int k, int m){
    char temp;
    int i;
    if (k == m){
        ans++;
        for (i = 0; i <= m; i++)
            printf("%c", str[i]);
        printf("\n");
        return;
    }
    else for (i = k; i <= m; i++)
        if (ok(str, k, i))   {         //����i��Ԫ���Ƿ��ܷ��ڵ�k��λ��
            temp = str[k]; str[k] = str[i]; str[i] = temp;   //swap(str[k],str[i]);
            perm(str, k + 1, m);
            temp = str[k]; str[k] = str[i]; str[i] = temp;   //swap(str[k],str[i]);
        }
}
int main(){
    char str[505];
    int n, i;
    scanf_s("%d", &n);
    getchar();
    ans = 0;
    for (i = 0; i < n; i++)
        scanf_s("%c", &str[i]);
    perm(str, 0, n - 1);
    printf_s("%lld\n", ans);
    return 0;
}