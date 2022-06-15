#include <iostream>
using namespace std;
class MyCin
{
private:
    bool judge;
public:
    MyCin():judge(true){}
    MyCin & operator >> (int & n)
    {
        cin >> n;
        if(n==-1) judge = false;
        return *this;
    }
    operator bool(){return judge;}
};
int main()
{
    MyCin m;
    int n1, n2;
    while (m >> n1 >> n2)
        cout << n1 << " " << n2 << endl;
    return 0;
}