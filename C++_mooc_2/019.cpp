#include <cstring>
#include <iostream>
using namespace std;
bool chess[30][30];
bool res = false;
int c, r;
string ans, ans1;
bool check()
{
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            if(!chess[i][j]) return false;
    return true;
}

void dfs(int x, int y)
{
    if(res) return;
    ans += (char) y + 'A' - 1;
    ans += (char) x + '0';
    chess[x][y] = true;
    int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1}, dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int flag = true;
    for (int i = 0; i < 8; i++)
    {
        int tmp1 = x + dx[i], tmp2 = y + dy[i];
        if(tmp1 >=1 && tmp1 <= r && tmp2 >= 1 && tmp2 <= c && chess[tmp1][tmp2] == false)
        {
            dfs(tmp1, tmp2);
            flag = false;
        }
    }
    if(flag && check())
    {
        res = true;
        ans1 = ans;
    }
    chess[x][y] = false;
    ans.pop_back();
    ans.pop_back();
    

}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        
        cin >> r >> c;
        cout << "Scenario #" << i + 1 << ":\n";
        for(int j = 1; j <= r; j++)
        {
            for(int k = 1; k <= c; k++)
            {
                memset(chess, 0, sizeof(chess));
                dfs(j, k);
                if(res)
                {
                    cout << ans1 << endl;
                    j = k = 30;
                }

            }
        }
        if(res) res = false;
        else cout << "impossible" << endl;
        if(i!=n-1) puts("");
    }

    
    

    return 0;
}