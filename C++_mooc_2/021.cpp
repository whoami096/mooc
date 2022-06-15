#include <iostream>
using namespace std;
const int N = 210;
char chess[N][N];
bool st[N][N];
int ans = 1e9;
int n, m, t;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int mit[N][N][N/10];
void dfs(int x, int y, int time, int cnt)
{
    
    if(mit[x][y][cnt] == 0) mit[x][y][cnt] = time;
    else if(time >= mit[x][y][cnt]) return;
    else mit[x][y][cnt] = time;
    st[x][y] = true;
    if(time > ans || cnt < 0) return;
        
    if(chess[x][y] == '+'&&cnt>=0)
    {
        ans = min(ans, time);
        //cout << ans;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >=1 && tx <= m && ty >= 1 && ty <= n && st[tx][ty] == false)
            {
                if(chess[tx][ty] == '#') dfs(tx, ty, time+1, cnt-1);
                else dfs(tx, ty, time+1, cnt);
                st[tx][ty] = false;
            }
        }
        
    }
    
}


int main()
{
    
    cin >> m >> n >> t;
    for(int i=1;i<=m;i++) cin >> chess[i] + 1;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(chess[i][j] == '@')
            {
                dfs(i, j, 0, t);

            }
        }
    }
    
    if(ans<1e8) cout << ans;
    else cout << -1;
    return 0;
}