#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    char str1[1000], str2[1000];
    while(cin>>str1>>str2)
    {
        int ans[1010][1010] = { 0 };
        int length1 = strlen(str1), length2 = strlen(str2);
        for(int i=1;i<=length1;i++)
            for(int j=1;j<=length2;j++)
            {
                if(str1[i-1]==str2[j-1])
                    ans[i][j] = ans[i-1][j-1] + 1;
                else
                    ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
            }
        cout << ans[length1][length2] << endl;
    }
    return 0;
}