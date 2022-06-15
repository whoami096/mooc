#include <iostream>
#include <cstring>
using namespace std;
char ans[30][30];
int res = 0;

void f(int x, int y)

{
    if (ans[x][y] == '.')
    {
        res ++;
        ans[x][y] = '#';
        if(ans[x+1][y] == '.') f(x+1, y);
        if(ans[x-1][y] == '.') f(x-1, y);
        if(ans[x][y-1] == '.') f(x, y-1);
        if(ans[x][y+1] == '.') f(x, y+1);
    }
}

int main()
{
    int w, h;
    while (cin >> w >> h)
    {
        if(w==h&&w==0) break;
        for(int i=0;i<h;i++) cin >> ans[i+1] + 1;
    int x, y;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        if(ans[i][j]=='@') x = i, y = j;

    ans[x][y] = '.';
    f(x, y);
    cout << res << endl;
    res = 0;
    memset(ans, 0, sizeof(ans));
    }
    
    
    
    return 0;
}