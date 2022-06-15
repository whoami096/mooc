#include <iostream>
using namespace std;
int GetBit(int n, int k);
void f(int n);
int main()
{
    int n, ret = 0;
    cin >> n;
    for(int i=14;i>=0;i--)
    {
        if(GetBit(n, i))
        {
            if(ret) printf("+");
            ret = 1;
            if(i==1)
            {
                printf("2");
                continue;
            }
            printf("2(");
            f(i);
            printf(")");
            
        }
    }
    return 0;
}

int GetBit(int n, int k)
{
    return (n >> k) & 1;
}
void f(int n)
{
    if(n==0) cout << 0;
    else if(n==2) cout << 2;
    else if(n==3) printf("2+2(0)");
    else if(n==4) printf("2(2)");
    else if(n==5) printf("2(2)+2(0)");
    else if(n==6) printf("2(2)+2");
    else if(n==7) printf("2(2)+2+2(0)");
    else if(n==8) printf("2(2+2(0))");
    else if(n==9) printf("2(2+2(0))+2(0)");
    else if(n==10) printf("2(2+2(0))+2");
    else if(n==11) printf("2(2+2(0))+2+2(0)");
    else if(n==12) printf("2(2+2(0))+2(2)");
    else if(n==13) printf("2(2+2(0))+2(2)+2(0)");
    else if(n==14) printf("2(2+2(0))+2(2)+2");
    else if(n==15) printf("2(2+2(0))+2(2)+2+2(0)");
}