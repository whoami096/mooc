#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*int main()
{
    char str[28];
    scanf("%s", str);
    sort(str, str+strlen(str));
    do
    {
        printf("%s\n", str);
    } while (next_permutation(str, str+strlen(str)));
    
    return 0;
} //stl版本
*/
char a[30], b[30], c[30];
int len;

void print()
{
    for(int i=1;i<=len;i++) printf("%c", b[i]);
    printf("\n");
}

void dfs(int k)
{
    if(k==len)
    {
        print();
        return;
    }
    for(int i=1;i<=len;i++)
    {
        if(!c[i-1])
        {
            b[k+1] = a[i-1];
            c[i-1] = 1;
            dfs(k+1);
            c[i-1] = 0;
        }
    }
}

int main()
{

    cin >> a;
    len = strlen(a);
    dfs(0);
    return 0;
}