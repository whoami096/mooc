#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class cshape
{
public:
    virtual double area() = 0;
    virtual void printinfo() = 0;
};

class juxing:public cshape
{
public:
    int w, h;
    virtual double area();
    virtual void printinfo();
};

class yuan:public cshape
{
public:
    int r;
    virtual double area();
    virtual void printinfo();
};

class sanjiaoxing:public cshape
{
public:
    int a, b, c;
    virtual double area();
    virtual void printinfo();
};

double juxing::area() { return w*h; }
void juxing::printinfo() { cout << "juxing:" << area() << endl; }

double yuan::area() { return 3.14*r*r; }
void yuan::printinfo() { cout << "yuan:" << area() << endl; }

double sanjiaoxing::area()
{
    double p = (a + b + c) / 2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
void sanjiaoxing::printinfo() { cout << "sanjiaoxing:" << area() << endl; }

cshape *p[100];


bool cmp(cshape *a, cshape *b)
{
    return a->area() < b->area();
}

int main()
{
    sanjiaoxing *pb;
    yuan *pa;
    juxing *pc;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case 'a':
            pa = new yuan();
            cin >> pa->r;
            p[i] = pa;
            break;
        case 'b':
            pb = new sanjiaoxing();
            cin >> pb->a >> pb->b >> pb->c;
            p[i] = pb;
            break;
        case 'c':
            pc = new juxing();
            cin >> pc->h >> pc->w;
            p[i] = pc;
            break;
        
        default:
            break;
        }

    }
    sort(p, p+n, cmp);
    for (int i = 0; i < n; i++)
    {
        p[i] -> printinfo();
    }
    return 0;
    

}