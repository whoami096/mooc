#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
int GetBit(int a, int i);
void SetBit(int &a, int i, int n);
void FlipBit(int &a, int i);
int main()
{
    int a = 0, b = 0;
    char a1[32], a2[32];
    cin >> a1 >> a2;
    int len = strlen(a1);
    for(int i=0;i<len;i++){
        SetBit(a, i, a1[i]-48);
        SetBit(b, i, a2[i]-48);
    }
    int cnt = 0, mi = 0x7fffffff;
    int num = pow(2, len);
    /*if(len<20){
    for(int i=0;i<num;i++){
            int tmp = b;
        for(int j=0;j<len;j++){
            if(GetBit(i, j)){
                FlipBit(tmp, j);
                if(j>0) FlipBit(tmp, j-1);
                if(j<len-1) FlipBit(tmp, j+1);
                cnt ++;
            }
        }
        if(a==tmp) mi = (mi>cnt)?cnt:mi;
        cnt = 0;
    }
    if(mi&&mi!=0x7fffffff) cout << mi;
    else cout << "impossible";
    return 0;
    }
    else*/
    
        int num1 = pow(2, 19);//先反转前19位
        for(int i=0;i<num1;i++){
            int tmp = b;
            for(int j=0;j<19;j++){
                if(GetBit(i, j)){
                   FlipBit(tmp, j);
                if(j>0) FlipBit(tmp, j-1);
                if(j<len-1) FlipBit(tmp, j+1);
                cnt ++; 
                }
            }
            int ret = 1, cnt1 = cnt;
            for(int k=0;k<18;k++)
                if(GetBit(a, k)!=GetBit(tmp, k)) ret = 0;//如果前18位相同，可以继续反转
            if(ret){
                int num2 = pow(2, len-19);
                for(int k=0;k<num2;k++){
                    for(int j=0;j<len-19;j++){
                        if(GetBit(k, j))
                        {
                            FlipBit(tmp, j+19);
                            FlipBit(tmp, j+18);
                        if(j<len-20) FlipBit(tmp, j+20);
                        cnt ++;
                        }
                    }
                    if(a==tmp) mi = (mi>cnt)?cnt:mi;//循环结束要判断
                        cnt = cnt1; //不能让cnt归零
                }
                
            }
            if(a==tmp) mi = (mi>cnt)?cnt:mi;
                cnt = 0;
        }
        if(mi!=0x7fffffff) cout << mi;
        else cout << "impossible";
        return 0;
    
}
void SetBit(int &a, int i, int n)
{
    if(n) a |= (1 << i);
    else a &= ~(1 << i);

}
int GetBit(int a, int i)
{
    return (a >> i) & 1;

}
void FlipBit(int &a, int i)
{
    a ^= (1 << i);
}
