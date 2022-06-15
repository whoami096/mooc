#include <algorithm>
#include <iostream>
#define N 100010

using namespace std;

int n, k, a[N];
int binary_search(int a[], int l, int r);

int main()
{
    cin >> n >> k;

    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a, a+n);
    cout << binary_search(a, 0, (a[n-1]+1)/k);
    return 0;
}

int binary_search(int a[], int l, int r)
{
    int ans = l + r >> 1;
    while(r-l>=3)
    {
        int las_pos = a[0];
        ans = l + r >> 1;
        int cnt = 1;
        for(int i=1;i<n;i++)
            if(a[i]-las_pos>=ans)
            {
                cnt ++;
                las_pos = a[i];
            }
        if(cnt<k) r = ans;
        else if(cnt>=k) l = ans;
        //else return ans;
    }
    
    while(1)
    {
        int las_pos = a[0];
        int cnt = 1;
        int ans = r --;
        for(int i=1;i<n;i++)
            if(a[i]-las_pos>=ans)
            {
                cnt ++;
                las_pos = a[i];
            }
        if(cnt>=k) return ans;
    }
    return ans;
}