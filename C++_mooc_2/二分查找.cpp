#include <iostream>
void quick_sort(int a[], int l, int r);
int binary_search(int a[], int size, int ans);
int tmp[10000];
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    quick_sort(a, 0, n-1);

    int x = binary_search(a, n, 5);
    cout << x;
    return 0;
}

void quick_sort(int a[], int l, int r)
{
    if(l>=r) return;
    int i = l - 1, j = r + 1, x = a[l+r>>1];
    while(i<j)
    {
        do i++; while(a[i]<x);
        do j--; while(a[j]>x);
        if(i<j) swap(a[i], a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j+1, r);
}

int binary_search(int a[], int size, int ans)
{
    int l = 0, r = size - 1, pos = -1;
    while(l<=r)
    {
        int p = l + (r - l) / 2;
        if(a[p]>ans) r = p - 1;
        else l = p + 1;
    }
    return pos;
}