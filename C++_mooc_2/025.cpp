#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-5;
bool cmp(pair<double, double> a, pair<double, double> b)
{
    if(fabs(a.second-b.second) > eps) return a.second < b.second;
    else return a.first < b.first;
}
int main()
{
    int cnt = 1;
    while (true)
    {

        vector<pair<double, double>> ans;
        int n, d, res = 1;
        cin >> n >> d;
        if(n == 0 && d == 0) break;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            double l1, l2;
            if(d * d - y * y < 0 || d < 0)
            {
                res = -1;
                ans.clear();
            }
            l1 = x - sqrt(d*d-y*y);
            l2 = x * 2 - l1;
            ans.push_back({l1, l2});
        }
        sort(ans.begin(), ans.end(), cmp);
        
        double r = ans[0].second;
        for(auto i:ans)
        {
            if(i.first > r)
            {
                res ++;
                r = i.second;
            }
        }
        cout << "Case " << cnt << ": ";
        cout << res << endl;
        cnt ++;
    }
    

    return 0;
}