#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX 2000000000
using namespace std;

struct P
{
    int height;
    int left;
    int right;
    int id;
    /* data */
};

bool cmp(P s1, P s2)
{
    return s1.height > s2.height;
}
P a[1010];
int n, x, y, Max;
int left_ans[1010], right_ans[1010];
void left_time(int k)
{
    int m = k + 1;
    while(m<=n&&a[k].height-a[m].height<=Max)
    {
        if(a[k].left<=a[m].right&&a[k].left>=a[m].left)
        {
            left_ans[k] = a[k].height - a[m].height + min(left_ans[m]+a[k].left-a[m].left, right_ans[m]+a[m].right-a[k].left);
            return;
        }
        else m ++;
    }
    if (a[k].height<=Max) left_ans[k] = a[k].height;
    else left_ans[k] = MAX;
    
}

void right_time(int k)
{
    int m = k + 1;
    while(m<=n&&a[k].height-a[m].height<=Max)
    {
        if(a[k].right<=a[m].right&&a[k].right>=a[m].left)
        {
            right_ans[k] = a[k].height - a[m].height + min(right_ans[m]+a[m].right-a[k].right, left_ans[m]+a[k].right-a[m].left);
            return;
        }
        else m ++;
    }
    if (a[k].height<=Max) right_ans[k] = a[k].height;
    else right_ans[k] = MAX;
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        scanf("%d %d %d %d", &n, &x, &y, &Max);
        for(int i=1;i<=n;i++) scanf("%d %d %d", &a[i].left, &a[i].right, &a[i].height);
        sort(a+1, a+n+1, cmp);
        a[0].height = y, a[0].left = a[0].right = x;
        for(int i=1;i<=n;i++) a[i].id = i;
        for(int i=n;i>=0;i--)
        {
            left_time(i);
            right_time(i);
        }
        
        cout << min(left_ans[0], right_ans[0]) << endl;
    }
    return 0;
}