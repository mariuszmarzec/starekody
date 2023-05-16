#include <iostream>
#include <cstdio>
using namespace std;
int zamien (int&, int&);
int uporzadkuj(int&, int&, int&);
bool czy_trojkat(int, int, int);
void jaki(int, int, int);
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    uporzadkuj(a, b, c);
    while (!czy_trojkat(a,b,c) or a <= 0 or b <= 0 or c <= 0)
    {
       cout << "nie poprawne dane, nie mozna zbudowac trojkata. Wprowadz nowe dane" << endl;
       cin >> a >> b >> c;
       uporzadkuj(a, b, c);
    }
    cout << "trojkat o bokach:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "jest :" << endl;
    jaki(a,b,c);
    cout << endl;
    cin.ignore();
    getchar();
    return 0;
}
int zamien (int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int uporzadkuj(int& a, int& b, int& c)
{
    if (a > b) zamien(a,b);    
    if (a > c) zamien(a,c);
    if (b > c) zamien(b,c);

}
bool czy_trojkat(int a, int b, int c)
{
     if (a + b > c) return true;
     return false;
}
void jaki(int a, int b, int c)
{
        if (a*a + b*b == c*c) cout << " - prostokatny" << endl;
        if (a == b or b == c) cout << " - rownoramienny" << endl;
        if (a == b and b == c and a == c) cout << " - rownoboczny" << endl;
        if (a*a + b*b < c*c) cout << " - rozwartokatny" << endl; 
        if (a*a + b*b > c*c) cout << " - o katach ostrych" << endl;
}
