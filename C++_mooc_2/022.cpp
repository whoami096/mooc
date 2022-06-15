#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;
bool chess[N][N];
bool st[N][N];
typedef pair<int, int> PII;


template <class T>
class myvector
{
private:
    bool check(int tmp)
    {
        if(tmp < 32) return false;
        while(!(tmp&1)) tmp >>= 1;
        tmp >>= 1;
        if(tmp) return false;
        else return true; 
    }
public:
    T * a = new T[32];
    T & operator[](int k)
    {return *(a+k);}
    int cnt = 0;
    int & size() {return cnt;}
    void push_back(T k)
    {
        if(this->check(cnt))
        {
            T *tmp = new T[(cnt)*2];
            memcpy(tmp, a, sizeof(T)*cnt);
            delete []a;
            a = tmp;
        }
        *(a + cnt ++) = k;
    }
    void pop_back() { cnt--; }

    int back() { return *(a+cnt-1); }

    void clear() { cnt = 0;}
    T *begin(){return a;}
    T *end(){return a+cnt;}



    void operator=(myvector<T> tmp)
    {
        this->size() = tmp.size();
        for (int i = 0; i < tmp.size(); i++)
        {
            *(a+i) = tmp[i];
        }
        
    }
};


myvector<PII> q;
myvector<PII> ans, tmp;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
void dfs(int x, int y)
{
    if(st[x][y]) return;
    st[x][y] = true;
    q.push_back({x, y});
    if(x == 5 && y == 5)
    {
        if(q.size() < ans.size() || ans.size() == 0) ans = q;
        
        //cout << q.size() << endl;
        q.pop_back();
        st[x][y] = false;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if(chess[tx][ty] && tx >= 1 && tx <=5 && ty >= 1 && ty <= 5)
        {

            dfs(tx, ty);     
        }
        
    }
    st[x][y] = false;
    q.pop_back();
    
}

int main()
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            int x;
            cin >> x;
            if(x) chess[i][j] = false;
            else chess[i][j] = true;
        }
    dfs(1, 1);
    for(auto i:ans) cout << '(' << i.first - 1 << ", " << i.second -1 << ')' << endl;
    return 0;
}