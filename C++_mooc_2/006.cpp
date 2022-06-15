#include <iostream>
using namespace std;
int f(int n, int k);
int main()
{
    int n;
    while(cin>>n)
    cout << f(n, n) << endl;
    return 0;
}

int f(int n, int k)
{
    if(k==1) return 1;
    if(n<k) return f(n, n);
    if(n==0) return 1;
    return f(n-k, k) + f(n, k-1);
}//经典放苹果