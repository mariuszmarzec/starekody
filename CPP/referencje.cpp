#include <iostream>
#include <conio.h>
using namespace std;
int foo(const int&, const int&);
int main()
{
    int liczba;
    int& referencja = liczba; // deklaracja referencji
    referencja = 1;
    cout << liczba << endl;
    // u¿ycie w funkcjach (foo) - optymalizacja bez wiêkszych zmian w ciele funkcji
    int a = 5, b = 2;
    cout << foo(a,b);
    getch();
    return 0;
}
int foo(const int& a, const int& b) // nie zmieniamy ich wartoœci wiêc powinny byæ const
{
    return (a*b);
}
