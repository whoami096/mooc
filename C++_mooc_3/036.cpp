#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
private:
    int x, y, z;
    T * p;
public:
    CArray3D(int _x, int _y, int _z):x(_x), y(_y), z(_z)
    {
        p = new T[x*y*z];
    }
    class CArray2D
    {
    private:
        int x, y, z;
        T *fp;
    public:
        CArray2D(T *_p, int _x, int _y, int _z)
        {
            y = _y, z = _z;
            fp = _p + _x * y * z;
        }
    T *operator[](int _j) {return fp+ _j*z;}
    operator T*(){return fp;}
    };
    CArray2D operator [] (int k) {return CArray2D(p, k, y, z);}
    ~CArray3D(){delete[] p;}

    
};

CArray3D<int> a(3, 4, 5);
CArray3D<double> b(3, 2, 2);
void PrintA()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "layer " << i << ":" << endl;
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 5; ++k)
                cout << a[i][j][k] << ",";
            cout << endl;
        }
    }
}
void PrintB()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "layer " << i << ":" << endl;
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
                cout << b[i][j][k] << ",";
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for (int i = 0; i < 3; ++i)
    {
        a[i];
        for (int j = 0; j < 4; ++j)
        {
            a[j][i];
            for (int k = 0; k < 5; ++k)
                a[i][j][k] = No++;
            a[j][i][i];
        }
    }
    PrintA();
    memset(a[1], -1, 20 * sizeof(int));
    memset(a[1], -1, 20 * sizeof(int));
    PrintA();
    memset(a[1][1], 0, 5 * sizeof(int));
    PrintA();

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                b[i][j][k] = 10.0 / (i + j + k + 1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl; 

    return 0;
}