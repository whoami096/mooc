#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string add(string s1, string s2)
{
    string res = "";
    int length1 = s1.length() - 1, length2 = s2.length() - 1;
    while (length1 != -1 && length2 != -1)
        res = (char)(s1[length1--] + s2[length2--] - 48) + res;
    length1++, length2++;
    while (length1--)
        res = s1[length1] + res;
    while (length2--)
        res = s2[length2] + res;
    int length3 = res.length() - 1;
    while (length3)
    {
        if (res[length3] > '9')
        {
            res[length3 - 1] += (res[length3] - 48) / 10;
            res[length3] = (res[length3] - 48) % 10 + 48;
        }
        length3--;
    }
    if (res[0] > '9')
    {
        res = (char)((res[length3] - 48) / 10 + 48) + res;
        res[1] = (res[1] - 48) % 10 + 48;
    }
    return res;
}
string mins(string s1, string s2)
{
    int length1 = s1.length(), length2 = s2.length();
    if (length1 < length2)
        return s1;
    else if (length2 < length1)
        return s2;
    else
    {
        for (int i = 0; i < length1; i++)
            if (s1[i] < s2[i])
                return s1;
            else if (s1[i] > s2[i])
                return s2;
    }
    //return "";
}

int main()
{
    /*string a = "45", b = "15";
    cout << add(a, b);*/
    int m;
    string dp[52][52];
    while (cin >> m)
    {
        string s;
        cin >> s;
        int length1 = s.length();
        s = ' ' + s;

        for (int i = 0; i <= length1; i++)
            dp[i][0] = s.substr(1, i); // boundery conditions
        for (int i = 1; i <= length1; i++)
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = "-1";
                for (int k = j; k < i; k++)
                {
                    if (!dp[i][j].compare("-1"))
                        dp[i][j] = add(dp[k][j - 1], s.substr(k + 1, i - k));
                    else
                        dp[i][j] = mins(dp[i][j], add(dp[k][j - 1], s.substr(k + 1, i - k)));
                }
            }
        cout << dp[length1][m] << endl;
    }
    return 0;
}