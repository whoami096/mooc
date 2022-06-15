#include <cstring>
#include <iostream>
//#include <cstdio>
using namespace std;
void f(int a[][3], int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
int main()
{
    int a[3][3];
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        scanf("%d", &a[i][j]);
    for(int a1=0;a1<4;a1++)
    for(int a2=0;a2<4;a2++)
    for(int a3=0;a3<4;a3++)
    for(int a4=0;a4<4;a4++)    
    for(int a5=0;a5<4;a5++)
    for(int a6=0;a6<4;a6++)
    for(int a7=0;a7<4;a7++)
    for(int a8=0;a8<4;a8++)
    for(int a9=0;a9<4;a9++)
    {
        int b[3][3];
        memcpy(b, a, sizeof(a));
        f(b, a1, a2, a3, a4, a5, a6, a7, a8, a9);
        int ret = 1;
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(b[i][j]%4!=0) ret = 0;
        if(ret)
        {
            while(a1--) printf("1 ");
            while(a2--) printf("2 ");
            while(a3--) printf("3 ");
            while(a4--) printf("4 ");
            while(a5--) printf("5 ");
            while(a6--) printf("6 ");
            while(a7--) printf("7 ");
            while(a8--) printf("8 ");
            while(a9--) printf("9 ");
            return 0;
        }

    }
    return 0;
}

void f(int a[][3], int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    while(a1--)
    {
        a[0][0] ++;
        a[0][1] ++;
        a[1][0] ++;
        a[1][1] ++;
    }
    while(a2--)
    {
        a[0][0] ++;
        a[0][1] ++;
        a[0][2] ++;
    }
    while(a3--)
    {
        a[0][1] ++;
        a[0][2] ++;
        a[1][1] ++;
        a[1][2] ++;
    }
    while(a4--)
    {
        a[0][0] ++;
        a[1][0] ++;
        a[2][0] ++;
    }
    while(a5--)
    {
        a[0][1] ++;
        a[1][0] ++;
        a[1][1] ++;
        a[1][2] ++;
        a[2][1] ++;
    }
    while(a6--)
    {
        a[0][2] ++;
        a[1][2] ++;
        a[2][2] ++;
    }
    while(a7--)
    {
        a[1][0] ++;
        a[1][1] ++;
        a[2][0] ++;
        a[2][1] ++;
    }
    while(a8--)
    {
        a[2][0] ++;
        a[2][1] ++;
        a[2][2] ++;
    }
    while(a9--)
    {
        a[1][1] ++;
        a[1][2] ++;
        a[2][1] ++;
        a[2][2] ++;
    }
}