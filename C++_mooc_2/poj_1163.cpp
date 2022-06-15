#include <iostream>
#include <cstring>
using namespace std;
int n, a[110][110], b[110][110];

int Max(int a, int b)
{
    return a > b ? a : b;
}

int max_num(int l, int r)
{
    if(b[l][r]!=-1) return b[l][r];
    if(l==n) b[l][r] = a[l][r];

    if(l==n) return a[l][r];
    b[l][r] = Max(max_num(l+1, r), max_num(l+1, r+1)) + a[l][r];
    return b[l][r];
}

int main()
{
    cin >> n;
    memset(b, -1, sizeof(b));
    //int a[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++) scanf("%d", &a[i][j]);
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++) a[i][j] += Max(a[i+1][j], a[i+1][j+1]);
    cout << a[1][1];
    //cout << max_num(1, 1);

    return 0;
}