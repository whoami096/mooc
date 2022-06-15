#include <iostream>
using namespace std;
const int N = 3500, M = 13000;
int n, m;
int a[N], w[N];

int ans[3][M];
int main()
{
    
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%d %d", &a[i], &w[i]);
    for(int i=1;i<=m;i++) if(a[1]<=i) ans[1][i] = w[1];
    for(int i=2;i<=n;i++)
    for(int j=1;j<=m;j++)
    {

        int tmp1, tmp2;
        int row = 1;
        if(i&1)
        {


            tmp1  = ans[2][j];
            if(j-a[i]<0) tmp2 = 0;
            else tmp2 = ans[2][j-a[i]] + w[i];

        }
        else
        {
            row = 2;
            
            tmp1 = ans[1][j];
            if(j-a[i]<0) tmp2 = 0;
            else tmp2 = ans[1][j-a[i]] + w[i];

        }

        
        ans[row][j] = max(tmp1, tmp2);
    }
    cout << ans[(n&1)?1:2][m];
    return 0;
}