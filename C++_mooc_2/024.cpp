#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int N = 30, K = 200;
int f[N], d[N], t[N];
int fish[N][K];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

int main()
{
    bool tmp0 = false;
    while (true)
    {
        int n, h;
        cin >> n;
        if(!n) break;;
        cin >> h;
        for(int i=1;i<=n;i++) cin >> f[i];
        for(int i=1;i<=n;i++) cin >> d[i];
        for(int i=1;i<n;i++) cin >> t[i];
        int fish_time = 0;
        for(int i=1;i<=n;i++)
        {
            fish[i][0] = f[i] + d[i];
            for(int j=1;j<=h*60/5;j++) fish[i][j] = max(fish[i][j-1] - d[i], 0);
        }
        int ans1 = 0;
        vector<int> ans2(N, 0);
        for(int i=1;i<=n;i++)
        {
            fish_time = h * 60;
            for(int j=2;j<=i;j++) fish_time -= t[j-1] * 5;
            fish_time = max(fish_time, 0);
            vector<pair<int, int>> ans;
            for(int j=1;j<=i;j++)
                for(int k=1;k<=fish_time/5;k++)
                    ans.push_back({fish[j][k], j});
            sort(ans.begin(), ans.end(), cmp);
            int res = 0;
            for(int i=1;i<=fish_time/5;i++) res += ans[i-1].first;
            if(res > ans1)
            {
                ans2 = vector<int> (N, 0);
                for(int i=1;i<=fish_time/5;i++)
                    ans2[ans[i-1].second] ++;
            }
                
            ans1 = max(ans1, res);
        }
        if(tmp0) puts("");
        else tmp0 = true;
        if(ans1 == 0) ans2[1] = h * 60 / 5;
        for(int i=1;i<=n;i++)
        {
            cout << ans2[i] * 5;
            if(i!=n) cout << ", ";
        }
        puts("");
        cout << "Number of fish expected: ";
        cout << ans1 << endl;
        }
    
    
    return 0;
}