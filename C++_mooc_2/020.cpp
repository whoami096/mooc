#include <cstring>
#include <iostream>
using namespace std;
int n, k, cnt, cnt1;
char chess[10][10];
bool stx[10], sty[10];

void dfs(int x, int y)
{
    stx[x] = true, sty[y] = true;
    cnt1 ++;
    if(cnt1 == k)
    {
        cnt ++;
        return;
    }
    for(int i=x;i<=n;i++)
    {
        int j;
        if(i!=x) j = 1;
        else j = y;
        for(;j<=n;j++)
        {
            if(chess[i][j] == '#' && !stx[i] && !sty[j])
            {
                dfs(i, j);
                stx[i] = false, sty[j] = false;
                cnt1 --;
            }
        }
    }
    
    stx[x] = false, sty[y] = false;
}

int main()
{
    
    while (cin>>n>>k)
    {
        for(int i=1;i<=n;i++) cin >> chess[i] + 1;

        if(n == -1) break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cnt1 = 0;
                memset(stx, 0, sizeof(stx));
                memset(sty, 0, sizeof(sty));
                if(chess[i][j] == '#') dfs(i, j);
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }
    
    return 0;
}