#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[26];
struct ANS
{
    int num;
    int cnt;
    /* data */
};
ANS b[26];

bool cmp(ANS a1, ANS a2)
{
    if(a1.cnt==a2.cnt) return a1.num > a2.num;
    else return a1.cnt < a2.cnt;
}

int main()
{
    cin >> n;
    //memset(b, -1, sizeof(b));
    for(int i=1;i<=n;i++) scanf("%d", &b[i].num);
    for(int i=n;i>=1;i--)
    {
        b[i].cnt ++;

        //ANS c[n-i];
        //memcpy(c, b+i+1, (n-i)*sizeof(ANS));
        sort(b+i+1, b+n+1, cmp);
        int sum = 0;
        for(int j=n;j>i;j--)
        {
            if(b[j].num<=b[i].num)
            {
                b[i].cnt += b[j].cnt;
                //b[i].num = c[j].num;
                break;
            }
        }
    }
    int ma = 0;
    for(int i=1;i<=n;i++) ma = (b[i].cnt>ma?b[i].cnt:ma);
    cout << ma;
    return 0;
}