#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int factor_value();
int term_value();
int expression_value();
int main()
{
    cout << expression_value();
    return 0;
}

int factor_value()
{
    char op = cin.peek();
    int result;
    if(op=='(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else cin >> result;
    return result; 
}

int term_value()
{
    int result = factor_value();
    char op = cin.peek();
    bool more = true;
    while(more)
    {
        if(op=='*'||op=='/')
        {
            cin.get();
            op=='*'?result*=factor_value():result/=term_value();
            op = cin.peek();
        }
        else more = false;
    }
    return result;
}

int expression_value()
{
    int result = term_value();
    char op = cin.peek();
    bool more = true;
    while(more)
    {
        if(op=='+'||op=='-')
        {
            cin.get();
            op=='+'?result+=term_value():result-=term_value();
            op = cin.peek();
        }
        else more = false;
    }
    return result;
}
 