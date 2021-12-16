#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n, l, i, j;
    int a[100], b[100];
    while (scanf_s("%d %d", &n, &l) != EOF){
        int sum = 0;
        for (i = 0; i < n; i++)
            scanf_s("%d", &a[i]);
        for (i = 0; i < n; i++)
            b[i] = a[i];
        sort(a, a + n);
        int q;
        for (i = 0; i < n; i++){
            sum += a[i];
            q++;
            if (sum > l){
                sum = sum - a[i] - a[i - 1];
                q = i - 2;
                break;
            }
        }
        int t;
        for (i = q; i < n; i++){
            if (a[i] > l - sum){
                t = a[i - 1];
                q = q + 1;
                sum = sum + a[i - 1];
                break;
            }
        }
        printf("%d %d\n", q + 1, sum);
        for (i = 0; i < q; i++)
            printf("%d ", b[i]);
        printf("%d\n", t);
    }
    return 0;
}
/*
input:                          output:
9 50                            5 49
2 3 13 8 80 20 21 22 23         2 3 13 8 23
*/