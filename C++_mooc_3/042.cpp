#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> PII;

int main()
{
    set<PII> a;
    a.insert({1000000000, 1});
    int n;
    cin >> n;
    while (n--)
    {
        int id, strength;
        cin >> id >> strength;
        
        auto it = a.lower_bound({strength, id});
        cout << id << ' ';
        //cout << (*it).second << endl;
        int ans = (*it).first;
        if(it == a.begin())
        {
            cout << (*it).second << endl;
            a.insert({strength, id});
            continue;
        }
        int ans1 = (*--it).first;
        if(ans - strength == strength - ans1) cout << (*it).second;
        else if(ans-strength > strength - ans1) cout << (*it).second;
        else cout << (*++it).second;
        putchar(10);
        a.insert({strength, id});

    }
    
    return 0;
}