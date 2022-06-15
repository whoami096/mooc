#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> PII;
int main()
{
    int n;
    cin >> n;
    multiset<int> a, b;
    while (n--)
    {
        string s;
        int num;
        cin >> s >> num;
        if(s == "add")
        {
            a.insert(num);
            b.insert(num);
            cout << a.count(num) << endl;
        }
        else if(s == "del")
        {
            cout << a.count(num) << endl;
            a.erase(num);

        }
        else if(s == "ask")
        {
            if(b.find(num) == b.end()) cout << 0;
            else cout << 1;
            cout << ' ' << a.count(num) << endl;
        }
    }
    
    return 0;
}