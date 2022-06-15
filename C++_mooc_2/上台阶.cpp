#include <iostream>
using namespace std;
int f(int i, int k);
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int i, k;
        cin >> i >> k;
        cout << f(i, k) << endl;
    }
    

    return 0;
}

int f(int i, int k)
{
    if(i<k) return f(i, i);
    if(k==1) return 1;
    if(i==0) return 1;
    
    return f(i-k, k)+f(i, k-1);
}