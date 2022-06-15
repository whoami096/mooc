#include <algorithm>
#include <iostream>
using namespace std;
long long ans = 0;
const int N = 100009;
int tmp[N], a[N];
void merge_sort(int a[], int l, int r)
{
    if(l>=r) return;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);
    int k = 0, i = l, j = mid + 1;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]) tmp[k++] = a[i++];
        else
        {
            tmp[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(int i=l, j=0;i<=r;i++, j++) a[i] = tmp[j]; 
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n-1);
    cout << ans;

    return 0;
}