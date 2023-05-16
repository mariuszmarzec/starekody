#include<iostream>
#include<conio.h>
#include<math.h>
#include<iomanip>
using namespace std;
long double oblicz_PI(int n, int * ilosc) // n - ilosc przebiegow, ilosc - dokladnosc
{
    int i;
    long double e, main = 0, licz = 2, wynik = 2, temp;
    for (i = 0; i < n; i++)
    {
        temp = wynik;
        main = sqrt(2+main);
        wynik *= 2/main;
    }
    e = wynik - temp;
    i = 0;
    while (e < 1)
    {
          i++;
          e *= 10;
    }
    *ilosc = i-1;
    return wynik;
}
long double generuj_e(int n)
{
    int i;
    long double e = 1;
    for (i = 0; i < n; i++)
    {
        e *= 0.1;
    }
    return e;  
}
long double oblicz_PI2(int dokladnosc, int * ilosc)
{
    int i = 0;
    long double temp = 1, e = generuj_e(dokladnosc), main = 0, licz = 2, wynik = 2;
    while (wynik - temp > e) 
    {
        temp = wynik;
        main = sqrt(2+main);
        wynik *= 2/main;
        i++;
    }
    *ilosc = i;
    return wynik;
}

int main()
{
    int n, l;
    cout << "PI = " << setprecision(20) << fixed << M_PI << endl;
    cin >> n;
    cout << "     " << setprecision(20) << fixed << oblicz_PI2(n,&l) << " liczba iteracji = " << l << endl;
    cout << "     " << setprecision(20) << fixed << oblicz_PI(n,&l) << " dokladnosc = " << l << endl;
    getch();
    return 0;
}

