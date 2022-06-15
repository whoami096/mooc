#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 110;
bool st[N][N];//用x, y记录状态
class A
{
public:
    A(int _t1, int _t2):x(_t1), y(_t2){}
    int x, y;
    vector<string> way;
};

int a, b, c;
int main()
{
    cin >> a >> b >> c;
    queue<A> q, q1;
    q.push(A(0, 0));

    A ans(0, 0);

    st[0][0] = true;
    while(1)
    {
        if(q.size() == 0)
        {
            q = q1;
            q1 = queue<A> ();
        }
        if(q.size() == 0) break;
        auto tmp = q.front();
        q.pop();
        for(int i=1;i<=6;i++)
        {
            auto tmp1 = tmp;
            switch (i)
            {
            case 1:
                tmp1.x = a;
                tmp1.way.push_back("FILL(1)");
                break;
            case 2:
                tmp1.y = b;
                tmp1.way.push_back("FILL(2)");
                break;
            case 3:
                tmp1.y += tmp1.x;
                tmp1.x = 0;
                if(tmp1.y > b) tmp1.y -= (tmp1.x = tmp1.y - b);
                tmp1.way.push_back("POUR(1,2)");
                break;
            case 4:
                tmp1.x += tmp1.y;
                tmp1.y = 0;
                if(tmp1.x > a) tmp1.x -= (tmp1.y = tmp1.x - a);
                tmp1.way.push_back("POUR(2,1)");
                break;
            case 5:
                tmp1.x = 0;
                tmp1.way.push_back("DROP(1)");
                break;
            case 6:
                tmp1.y = 0;
                tmp1.way.push_back("DROP(2)");
                break;
            default:
                break;
            }
            if(!st[tmp1.x][tmp1.y]) q1.push(tmp1);
            st[tmp1.x][tmp1.y] = true;
            if(tmp1.x == c || tmp1.y == c)
            {
                ans = tmp1;
                break;
            }
        }
        if(ans.x == c || ans.y == c) break;
    }
    if(ans.way.size() == 0) cout << "impossible\n";
    else cout << ans.way.size() << endl;
    for(auto i:ans.way) cout << i << endl;
    
    return 0;
}