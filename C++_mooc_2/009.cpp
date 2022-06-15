#include <iostream>
bool judge(int ans, int a[], int n, int m);
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], l = 0, r = 0, ans;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        r += a[i];
        l = (l>a[i]?l:a[i]);
    }
    
    while(l<=r)
    {
        ans = l + r >> 1;
        if(judge(ans, a, n, m)) l = ans + 1;
        else r = ans - 1;
    }
    cout << ans;
    return 0;
}

bool judge(int ans, int a[], int n, int m)
{
    int sum = 0, cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]>ans)
        {
            sum = a[i];
            cnt ++;
        }
        else sum += a[i];
    }
    if(cnt>=m) return true;
    else return false;
}