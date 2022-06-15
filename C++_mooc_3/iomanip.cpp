#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n = 141;
    //1) 改变输出进制，长效
    cout << "1) " << hex << n << " " << dec << n << " " << oct << n << endl;
    double x = 1234567.89, y = 12.34567;
    //1) 保留5位有效数字
    cout << "2) " << setprecision(5) << x << " " << y << " " << endl;
    //3) 保留小数点后面5位
    cout << "3) " << fixed << setprecision(5) << x << ' ' << y << ' ' << endl;
    //4) 科学技术法输出，小数点后面五位小数
    cout << "4) " << scientific << setprecision(5) << x << ' ' << y << ' ' << endl;
    //5) 非负显示正号，宽度12，*填充
    cout << "%) " << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
    //6) 非负不显示正号，宽度12，右边填充*
    cout << "6) " << noshowpos << setw(12) << left << 12.1 << endl;
    //7) 宽度12，左边填充字符
    cout << "7) " <<  setw(12) << right << 12.1 << endl;
    //8) 宽带不足，负号数值分列左右，中间填充字符
    cout << "8) " << setw(12) << internal << -12.1 << endl;
    cout << "9) " << 12.1 << endl;
    return 0;
}