#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
/*
int GetBit(int i, int j)
{
    return (i >> j) & 1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int ans = 0, total = pow(2, n);
    for(int i=0;i<total;i++)
    {
        int sum = 0;
        for(int j=0;j<n;j++)
            if(GetBit(i, j)) sum += a[j];
        if(sum==40) ans ++;
    }
    cout << ans;
    return 0;
}
int a[22], n;


int f(int w, int k)
{
    if(w==0) return 1;
    if(k<=0) return 0;
    
    return f(w, k-1) + f(w-a[k], k-1);
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    cout << f(40, n);
    return 0;
}*/
int a[22], n, ans[42][42];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    memset(ans, 0, sizeof(a));
    for(int i=0;i<=42;i++)
    {
        ans[0][i] = 1;
        ans[i][0] = 1;
    }
    for(int i=1;i<=40;i++) if(a[1]==i) ans[1][i] = 1;

    for(int i=2;i<=n;i++)
        for(int j=1;j<=40;j++)
        {
            ans[i][j] = ans[i-1][j] + ans[i-1][(j-a[i])>0?(j-a[i]):0];
            if(j-a[i]<0) ans[i][j] --;
        }
    cout << ans[n][40];
    return 0;
}