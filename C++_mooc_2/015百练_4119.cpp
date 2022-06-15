//经典dp


#include <iostream>
using namespace std;
int n, k;
const int N = 60;

void f1()
{
    int ans[N][N] = { 0 };
    ans[1][1] = 1;
    for(int i=1;i<=n;i++) ans[i][1] = 1;
    for(int i=1;i<=n;i++)
        for(int j=2;j<=i;j++)
            ans[i][j] = ans[i-1][j-1] + ans[i-j][j]; 

    cout << ans[n][k] << endl;
}
void f2()
{
    int ans[N][N] = { 0 };
    ans[0][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) ans[i][j] = 1 + ans[i][j-1];
            else if(i<j) ans[i][j] = ans[i][i];
            else ans[i][j] = ans[i-j][j-1] + ans[i][j-1];
        }
    cout << ans[n][n] << endl;
}
void f3()
{
    int ans[N][N] = { 0 };
    ans[0][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(j%2!=0)
            {
                if(i==j) ans[i][j] = 1 + ans[i][j-1];
                else if(i<j) ans[i][j] = ans[i][i];
                else ans[i][j] = ans[i-j][j] + ans[i][j-1];
            }
            else ans[i][j] = ans[i][j-1];
        }
    cout << ans[n][n] << endl;

}
int main()
{
    
    while(cin>>n>>k)
    {
        f1();
        f2();
        f3();
    }
    return 0;
}