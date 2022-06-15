#include <iostream>
#define N 100009
using namespace std;
int a[N], tmp[N], n, k;
void f(int l, int r, int cnt);
void merge_sort(int a[], int l, int r);
int main()
{
    int k;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    cin >> k;
    //f(0, n-1, k);
    
    merge_sort(a, 0, n-1);
    for(int i=n-1;i>=n-k;i--) printf("%d\n", a[i]);
    return 0;
}

void merge_sort(int a[], int l, int r)
{
    if(l>=r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);
    int i = l, j = mid + 1, k = 0;
    while(i<=mid&&j<=r)
        if(a[i]<a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(int i=l, j=0;i<=r;i++, j++) a[i] = tmp[j];
}

void f(int l, int r, int cnt)
{
    int i = l - 1, j = r + 1, key = a[l+r>>1];
    while(i<j)
    {
        do i++; while(a[i]<key);
        do j--; while(a[j]>key);
        if(i<j) swap(a[i], a[j]);
    }
    if(n-j==cnt) return;
    else if(n-j<cnt) f(l, j, cnt);
    else f(j+1, r, cnt);
}
