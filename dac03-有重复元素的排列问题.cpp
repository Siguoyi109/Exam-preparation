#include <iostream>
#include <stdlib.h>
using namespace std;
long long ans;
int ok(char str[], int a, int b) //检测第b个元素是否能放在第a个位置
{
    int i;
    if (b > a)                      //若是前面有一个元素a[i]与a[b]相等，                 
        for (i = a; i < b; i++)     //那a[b]的值已经在第a个位置出现过，再放在这个地方就是重复了。
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
        if (ok(str, k, i))   {         //检测第i个元素是否能放在第k个位置
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