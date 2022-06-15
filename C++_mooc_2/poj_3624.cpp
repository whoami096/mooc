#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n+1][3];
    for(int i=1;i<=n;i++)
        //for(int j=1;j<=2;j++)
            scanf("%d %d", &a[i][1], &a[i][2]);
    int F[m+1], tmp[m+1];
    memset(F, 0, sizeof(F));
    for(int i=1;i<=m;i++) F[i] = (a[1][1]>i?0:a[1][2]);

    for(int i=2;i<=n;i++){
        memcpy(tmp, F, sizeof(F));
        for(int j=1;j<=m;j++)
        {
            
            F[j] = max(tmp[j], tmp[((j-a[i][1])>=0?(j-a[i][1]):0)]+(j-a[i][1]>=0?a[i][2]:0));
        }}
    cout << F[m];
    return 0;
}