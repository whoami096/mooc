#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct POS
{
    int x;
    int y;
    int height;
    
};

bool cmp(POS s1, POS s2)
{
    return s1.height < s2.height;
}



int main()
{
    int m, n;
    cin >> m >> n;
    int a[m+2][n+2], ans[m+2][n+2];
    memset(a, 0, sizeof(a));
    memset(ans, 0, sizeof(ans));
    POS b[m*n];
    int cnt = 0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d", &a[i][j]);
            ans[i][j] = 1;
            b[cnt].x = i;
            b[cnt].y = j;
            b[cnt].height = a[i][j];
            cnt ++;
        }
    sort(b, b+m*n, cmp);
    int Max = 0;
    for(int i=0;i<m*n;i++)
    {
        if(a[b[i].x][b[i].y]<a[b[i].x+1][b[i].y]) ans[b[i].x+1][b[i].y] = max(ans[b[i].x+1][b[i].y], ans[b[i].x][b[i].y]+1);
        if(a[b[i].x][b[i].y]<a[b[i].x-1][b[i].y]) ans[b[i].x-1][b[i].y] = max(ans[b[i].x-1][b[i].y], ans[b[i].x][b[i].y]+1);
        if(a[b[i].x][b[i].y]<a[b[i].x][b[i].y+1]) ans[b[i].x][b[i].y+1] = max(ans[b[i].x][b[i].y+1], ans[b[i].x][b[i].y]+1);
        if(a[b[i].x][b[i].y]<a[b[i].x][b[i].y-1]) ans[b[i].x][b[i].y-1] = max(ans[b[i].x][b[i].y-1], ans[b[i].x][b[i].y]+1);
        Max = (Max>ans[b[i].x][b[i].y])?Max:ans[b[i].x][b[i].y];
    }
    cout << Max;


    return 0;
}
