#include <list>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


template <class T>
class myvector
{
private:
    T *a;

    bool check(int tmp)
    {
        if(tmp < 32) return false;
        while(!(tmp&1)) tmp >>= 1;
        tmp >>= 1;
        if(tmp) return false;
        else return true; 
    }
public:
    myvector(int k){ a = new T[k];}
    myvector(){a = new T[32];}


    
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
    void erase(T *tmp1, T *tmp2)
    {
        myvector<T> tmp;
        int j = 0;
        for (int i = 0; i < tmp1-a; i++, j++) tmp[j] = *(a+i);
        for (int i = 0; tmp2+i!=this->end(); i++, j++) tmp[j] = *(tmp2 + i);

        cnt -= tmp2 - tmp1;
        
        delete [] a;
        a = tmp.a;
    }


    void operator=(myvector<T> tmp)
    {
        this->size() = tmp.size();
        for (int i = 0; i < tmp.size(); i++)
        {
            *(a+i) = tmp[i];
        }
        
    }
};


int main()
{
    myvector<list<int> > a(10010);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if(s == "new")
        {
            int id;
            cin >> id;
        }
        else if(s == "add")
        {
            int id, num;
            cin >> id >> num;
            a[id].push_back(num);
        }
        else if(s == "merge")
        {
            int id1, id2;
            cin >> id1 >> id2;
            if(id1 != id2)
            {
                a[id1].merge(a[id2]);
                a[id2].clear();
            }
        }
        else if(s == "unique")
        {
            int id;
            cin >> id;
            a[id].sort();
            a[id].unique();
        }
        else if(s == "out")
        {
            int id;
            cin >> id;
            a[id].sort();
            for(auto i:a[id]) cout << i << ' ';
            cout << endl;
        }
    }
    
    return 0;
}