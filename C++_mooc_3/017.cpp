#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
    int row, column;
    int **p;
public:
    Array2(int row_ = 0, int column_ = 0): row(row_), column(column_)
    {
        if(row==0&&column==0)
        {
            p = NULL;
            return;
        }
        p = new int *[row];
        for(int i=0;i<row;i++) p[i] = new int[column];
    }
    int *& operator [] (int row_)
    {
        return p[row_];
    }
    int & operator ()(int row_, int column_)
    {
        return p[row_][column_];
    }
    Array2 & operator = (Array2 arr)
    {
        /*if(p)
        {
            for(int i=0;i<row;i++) delete [] p[i];
            delete[] p;
        }*/
        row = arr.row;
        column = arr.column;
        p = new int*[row];
        for(int i=0;i<row;i++) p[i] = new int[column];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++) *(p[i]+j) = *(arr[i]+j);
        }
        return *this;
    }
    
    ~Array2()
    {
        if(p)
        {
            for(int i=1;i<row;i++) delete [] p[i];
            delete []p;
        }
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}