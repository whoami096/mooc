#include <iostream>
using namespace std;
class Sample
{
public:
    int v;

public:
    Sample(int i = 0)
    {
        v = i;
    }
    Sample(const Sample &c)
    {
        v = c.v + 2;
    }
};
void PrintAndDouble(Sample o)
{
    cout << o.v;
    cout << endl;
}
int main()
{
    Sample a(5);
    Sample b = a;
    PrintAndDouble(b);
    Sample c = 20;
    PrintAndDouble(c);
    Sample d;
    d = a;
    cout << d.v;
    return 0;
}