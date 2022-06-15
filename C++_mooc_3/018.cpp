#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt
{
    public:
    string s;
    CHugeInt(int a)
    {
        if(a==0) s += '0';
        while(a) s += a%10+'0', a /= 10;
        

    }//构造函数
    CHugeInt(char *str)
    {
        int length = strlen(str);
        while(length--) s += str[length];
    }//构造函数
    CHugeInt  operator + (CHugeInt a)//+运算符重载
    {
        string tmp1;
        tmp1 = this->s;
        string tmp2 = a.s;
        char str[203];
        memset(str, 0, sizeof(str));
        int t = 0;
        for(int i=0;i<tmp1.size()||i<tmp2.size();i++)
        {
            if(i<tmp1.size()) t += tmp1[i]-'0';
            if(i<tmp2.size()) t += tmp2[i]-'0';
            
            str[i] = (t%10)+'0';
            t /= 10;

        }
        if(t) str[strlen(str)] = t + '0';

        CHugeInt b(str);
        return b;
    }//流输出运算符重载
    friend ostream & operator << (ostream & os, const CHugeInt & s)
    {
        os << s.s;
        return os;
    }
    CHugeInt operator + (int b)//+运算符对int重载
    {
        string tmp1;
        tmp1 = this->s;
        string tmp2;
        while(b) tmp2 += b%10+'0', b/=10;
        char str[203];
        memset(str, 0, sizeof(str));
        int t = 0;
        for(int i=0;i<tmp1.size()||i<tmp2.size();i++)
        {
            if(i<tmp1.size()) t += tmp1[i]-'0';
            if(i<tmp2.size()) t += tmp2[i]-'0';
            
            str[i] = (t%10)+'0';
            t /= 10;

        }
        if(t) str[strlen(str)] = t + '0';

        CHugeInt ans(str);
        return ans;
    }
    friend CHugeInt operator + (int b, CHugeInt b1)
    {
        return b1 + b;//使对象+int=int+对象
    }
    CHugeInt operator += (int ans)
    {
        return *this = *this + ans;//+=重载
    }
    CHugeInt & operator ++()//&引用是为了++对象=对象成立
    {
        (*this).s[(*this).s.size()-1] += 1;
        return *this;//++重载
        
    }
    CHugeInt operator++(int k) //为什么给一个没用的参数
    {
        CHugeInt tmp(*this);
        (*this).s[(*this).s.size()-1] += 1;//返回临时变量
        return tmp;
    }
};
int main()
{
    char s[210];
    int n;

    while (cin >> s >> n)
    {
        CHugeInt a(s);
        CHugeInt b(n);
        



        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        
        cout << ++b << endl;
        cout << b++ << endl;
        cout << b << endl; 
    } 
    return 0;
}