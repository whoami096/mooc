#include <iostream>
using namespace std;
ostream &tab(ostream &output)
{
    return output << '\t';
}

//ostream &operator <<(ostream&(*p)(ostream &));
int main()
{
    cout << "aa" << tab << "bb";
    return 0;
}