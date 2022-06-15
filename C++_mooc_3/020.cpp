#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class MyString : public string
{

public:
    string s;
    MyString(const char s1[])
    {
        for(int i=0;s1[i];i++) s += s1[i];
    }
    MyString() {}

    friend ostream & operator << (ostream & os, MyString & s1)
    {
        os << s1.s;
        return os;
    }
    MyString operator + (MyString s1)
    {
        MyString tmp;
        tmp.s = this->s + s1.s;
        return tmp;
    }

    char & operator [](int k)//传引用可以 s[k] = 'a';
    {
        return this->s[k];
    }
    MyString operator += (const char str[])
    {
        for(int i=0;str[i];i++) this->s += str[i];
        return *this;
    }
    friend MyString operator + (const char str[], MyString s1)
    {
        int length = 0;
        while(str[length]) length ++;
        for(int i=length-1;i>=0;i--) s1.s = str[i] + s1.s;
        return s1;
    }
    MyString operator +(const char str[])
    {
        for(int i=0;str[i];i++) this->s += str[i];
        return *this;
    }
    bool operator < (MyString s1)
    {
        return this->s[0] < s1.s[0];
    }

    string operator()(int a, int b)
    {
        string s;
        for(int i=a;i-a<b;i++) s += this->s[i];
        return s;
    }
};

int main()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    sort(SArray, SArray + 4);
    for (int i = 0; i < 4; i++)
        cout << SArray[i] << endl;
    // s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    // s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl; 
    return 0;
}