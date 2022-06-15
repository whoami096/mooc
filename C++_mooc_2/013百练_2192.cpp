//zipper
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[210], str2[210], str3[420];
    bool ans[210][210];

    int t;
    cin >> t;
    int n = t;
    while(t--)
    {
        memset(ans, 0, sizeof(ans));

        scanf("%s %s %s", str1+1, str2+1, str3+1);
        str1[0] = str2[0] = str3[0] = 'a';
        int length1 = strlen(str1)-1, length2 = strlen(str2)-1;
        int length3 = strlen(str3)-1;
        for(int i=1;i<=length1;i++)
            if(str1[i]==str3[i]) ans[0][i] = true;
            else ans[0][i] = false;
        for(int i=1;i<=length2;i++)
            if(str2[i]==str3[i]) ans[i][0] = true;
            else ans[i][0] = false;
        for(int i=1;i<=length2;i++)
            for(int j=1;j<=length1;j++)
            {
                if((ans[i-1][j]&&str3[i+j]==str2[i]) || (ans[i][j-1]&&str3[i+j]==str1[j]))
                    ans[i][j] = true;
                else ans[i][j] = false;
            }
        if(ans[length2][length1]) printf("Data set %d: yes\n", n-t);
        else printf("Data set %d: no\n", n-t);
    }
    return 0;
}