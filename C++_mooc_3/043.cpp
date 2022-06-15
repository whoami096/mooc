#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> PII;

int main()
{
    multiset<PII> a;
    a.insert({1000000000, 1});
    int n;
    cin >> n;
    while (n--)
    {
        int id, strength;
        cin >> id >> strength;

        auto it = a.lower_bound({strength, 0});
        //int strength1 = strength * 2 - (*it).first;
        auto it1 = it;
        if(it1 != a.begin())
        {
            it1 --;
            int strength1 = (*it1).first;
            it1 = a.lower_bound({strength1, 0});
        }
        cout << id << " ";
        if(strength - (*it1).first == (*it).first - strength) cout << min((*it).second, (*it1).second) << endl;
        else if((*it).first - strength < strength - (*it1).first) cout << (*it).second << endl;
        else cout << (*it1).second << endl;

        //a.insert({strength, id});


        a.insert({strength, id});
    }
    
    return 0;
}