#define PI 3.141592653589793
#include <algorithm>
#include <iostream>
#include <cmath>
long double binary_search(int a[], int l, int r);
using namespace std;
int N, F;
int main()
{

    cin >> N >> F;
    int a[N];
    for(int i=0;i<N;i++) scanf("%d", &a[i]);

    sort(a, a+N);

    printf("%.3Lf", binary_search(a, 0, a[N-1]));
    return 0;
}

long double binary_search(int a[], int l, int r)
{
    long double le = 0.0, ri = PI*r*r;
    while(ri-le>0.1)
    {
        long double ans = (le + ri) / 2;
        int cnt = 0;
        for(int i=0;i<N;i++)
        cnt += (int) a[i]*a[i]*PI/ans;
        if(cnt>=F+1) le = ans;
        else if(cnt<F+1) ri = ans;
        //else return ans;
    }
    while(1)
    {
        long double ans = ri;
        ri -= 0.00001;
        int cnt = 0;
        for(int i=0;i<N;i++)
            cnt += (int) a[i]*a[i]*PI/ans;
        if(cnt>=F+1) return ans;
    }
}