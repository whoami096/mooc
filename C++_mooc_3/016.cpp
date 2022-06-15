#include <iostream> 
using namespace std;
class Point { 
    private: 
        int x; 
        int y; 
    public: 
        Point() { };
    friend ostream & operator << (ostream & os, const Point & s)
    {
        os << s.x << "," << s.y;
        return os;
    }
    friend istream & operator >> (istream & is, Point & s)
    {
        is >> s.x >> s.y;
        return is;
    }
// 在此处补充你的代码

}; 
int main() 
{ 
    Point p;
    while(cin >> p) {
        cout << p << endl;
        }
    return 0;
}