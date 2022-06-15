#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e3+10;
int a[N], b[N];
int main()
{
    while (true)
    {
        int n, ans = 0;
        cin >> n;
        if(!n) break;
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        for(int i=0;i<n;i++) scanf("%d", &b[i]);
        int l = 0, r = n - 1;
        int r1 = r, l1 = l;
        sort(a, a+n, greater<int>());
        sort(b, b+n, greater<int>());
        for (int i = 0; i < n; i++)
        {
            if(a[l] > b[l1])
            {
                ans += 200;
                l ++, l1 ++;
            }
            else if(a[r] > b[r1])
            {
                ans += 200;
                r --, r1 --;
            }
            else if(a[r] < b[l1])
            {
                ans -= 200;
                r --, l1 ++;
            }
            else if(a[r] == b[l1])
            {
                r --; l1 ++;
            }
        }
        cout << ans << endl;
        
    }
    
    return 0;
}