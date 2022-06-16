#include <iostream>
using namespace std;

template <class T1, class T2>
class mypair
{
public:
    T1 key;
    T2 value;
    mypair(T1 tmp1, T2 tmp2):key(tmp1), value(tmp2){}
    mypair(){}
    bool operator < (const mypair<T1, T2> &p) const;
};
template <class T1, class T2>
bool mypair<T1, T2>::operator<(const mypair<T1, T2> & p) const
{
    return key < p.key;
}
int main()
{
    mypair<int, string> a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i].key >> a[i].value;
    }
    for (int i = 0; i < 5; i++)
    {
        if(a[i] < a[i + 1]) cout << a[i].key << ' ' << a[i].value << endl;
    }
    
    
}