#include <iostream>
#include <conio.h>
using namespace std;
int NWD(int, int);
int main()
{
    unsigned int a, b;
    cout << "NWW dla dwoch dowolnych liczb naturalnych." << endl;
    cin >> a >> b;
    cout << "NWW(" << a << "," << b << ") = " << (a*b/NWD(a, b)) << endl;
    getch();
    return 0;
}
int NWD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
              a -= b;
        else if (a < b)
              b -= a;
    }
    return a;
}
