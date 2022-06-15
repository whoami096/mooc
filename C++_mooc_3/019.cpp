#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char *s)
{
    int i = 0;
    for (; s[i]; ++i)
        ;
    return i;
}
void strcpy(char *d, const char *s)
{
    int i = 0;
    for (i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;
}
int strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] && s2[i]; ++i)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char *d, const char *s)
{
    int len = strlen(d);
    strcpy(d + len, s);
}
class MyString
{
public:
    char str[20];
    //for(int i=0;i<20;i++) str[i] = '\0';
    MyString(const char s1[])
    {
        strcpy(str, s1);
    }
    MyString(const MyString &s1) //必须传引用，加个const使得通过数组可以复制
    {
        strcpy(str, s1.str);
    }
    MyString()
    {
        str[0] = '\0';
    }
    friend ostream & operator << (ostream &os, MyString &s1)
    {
        os << s1.str;
        return os;
    }
    MyString operator =(MyString s1)
    {
        strcpy(this->str, s1.str);
        return *this;
    }
    MyString operator +(MyString s1)
    {
        MyString s2;
        strcat(s2.str, this->str);
        strcat(s2.str, s1.str);
        return s2;
    }
    char & operator [](int k)
    {
        return this->str[k];
    }
    MyString operator =(const char s1[])
    {
        
        strcpy(this->str, s1);
        return *this;
    }
    MyString operator +=(const char str[])
    {
        strcat(this->str, str);
        return *this;
    }
    MyString operator +(const char str[])
    {
        MyString s2;
        strcat(s2.str, this->str);
        strcat(s2.str, str);
        
        return s2;
    }
    friend MyString operator +(const char str[], MyString s1)
    {
        MyString s2;
        strcpy(s2.str, str);

        return s2 + s1;
    }
    bool operator <(MyString s1)
    {
        if(this->str[0]<s1.str[0]) return true;
        else return false;
    }
    bool operator >(MyString s1)
    {
        if(this->str[0]>s1.str[0]) return true;
        else return false;
    }
    bool operator ==(MyString s1)
    {
        if(this->str[0]==s1.str[0]) return true;
        else return false;
    }
    // 在此处补充你的代码
    char *  operator ()(int a, int b)
    {
        char *str = new char[20];
        strcpy(str, this->str);
        if(a==0) str[b] = '\0';
        else
        {
            strcpy(str, str+a);
            str[b] = '\0';
        }
        return str;
    }
};

int CompareString(const void *e1, const void *e2)
{
    MyString *s1 = (MyString *)e1;
    MyString *s2 = (MyString *)e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else if (*s1 > *s2)
        return 1;
    return 0;
}
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
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; i++)
        cout << SArray[i] << endl;
    // s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    // s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}