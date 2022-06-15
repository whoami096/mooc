#include <iostream>
using namespace std;
const long long inf = -1;

long long dp[25][25][25];

long long ways(long long w, long long h, long long m)
{
    if(w*h<m+1) return inf;
    else if(m==0) return w * h;
    else if(dp[w][h][m]) return dp[w][h][m];
    long long mx = 2e9;
    for (long long i = 1; i <= w-1; i++)
    {
        for (long long j = 0; j <= m-1; j++)
        {
            long long k1, k2;
            k1 = ways(i, h, j);
            k2 = ways(w-i, h, m-1-j);
            mx = min(mx, max(k1, k2));
        }
        
    }
    for (long long i = 1; i <= h-1; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            long long k1, k2;
            k1 = ways(w, i, j);
            k2 = ways(w, h-i, m-j-1);
            mx = min(mx, max(k1, k2));
        }
        
    }
    dp[w][h][m] = mx;
    return mx;
    
    
}


int main()
{
    long long w, h, m;
    while (cin>>w>>h>>m)
    {
        if(w==0) break;
        else cout << ways(w, h, m-1) << endl;
    }
    
    return 0;
}