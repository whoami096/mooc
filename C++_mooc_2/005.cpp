#include <iostream>
int f();
int g();
using namespace std;
int main()
{
    int ans = 0, cnt = 0;
    char op1 = '|';
    while(1)
    {
        char op = cin.peek();
        
        if(op=='|'||op=='&') op1 = op;
        char x = getchar();



        if(x=='V'||x=='F'||x=='('||x=='!')
        {
            int one;
            if(x=='V') one = 1;
            else if(x=='F') one = 0;
            else if(x=='(') one = f();
            else one = !g();//读到！单独处理
            switch (op1)
            {
            //case '!': ans = (one==0)?1:0; break;
            case '|': ans |= one; break;
            case '&': ans &= one; break;     
            default: break;
            }
        }
        
        
        if(x=='\n')
        {
            printf("Expression %d: %c\n", ++cnt, ans?'V':'F');
            op1 = '|';
            ans = 0;
        }
        else if(x==EOF)
        {
            printf("Expression %d: %c\n", ++cnt, ans?'V':'F');
            return 0;
        }
        
    }
    //cout << ans;
    
}

int f()
{
    int ans = 0;
    char op1 = '|';
    while(1)
    {
        char op = cin.peek();
        
        if(op=='|'||op=='&') op1 = op;
        char x = getchar();
        //if(x=='(') ans = f();
        if(x==')') return ans;
        if(x=='V'||x=='F'||x=='('||x=='!')
        {
            int one;
            if(x=='V') one = 1;
            else if(x=='F') one = 0;
            else if(x=='(') one = f();
            else one = !g();
            switch (op1)
            {
            //case '!': ans = (one==0)?1:0; break;
            case '|': ans |= one; break;
            case '&': ans &= one; break;
            default: break;
            }
        }
    }
    
}

int g()
{
    char c;
    while(1)
    {
        c = getchar();
        if(c==' ') continue;//跳过空格
        else if(c=='(')//如果是（表明是一项，调用f()
        {
            int ans;
            ans = f();
            return ans;
        }
        else return c=='F'?0:1;//否则就只有一个字母，直接返回
    }
}