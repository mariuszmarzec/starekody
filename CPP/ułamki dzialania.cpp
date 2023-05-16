#include <iostream>
#include <stdio.h>
using namespace std;
class ulamek
{
      private:
             int p, q;
      public:
             ulamek(int a = 0, int b = 0)
             {
                  p = a;
                  q = b;
             }
             void wprowadz_dane()
             {
                  cout << "Licznik: ";
                  cin >> p;
                  cout << "Mianownik: ";
                  cin >> q;
             }
             void skroc()
             {
                  int d = p > q ? p : q;
                  while (d)
                  {
                        if (p%d == 0 and q%d == 0)
                        {
                            p /= d;
                            q /= d;
                        }
                        --d;
                  }
             }
             void wyswietl() {cout << p << "/" << q;}
             int licznik() {return p;}
             int mianownik() {return q;}
};
ulamek operator + (ulamek liczba1, ulamek liczba2)
{
         return ulamek(liczba1.licznik()*liczba2.mianownik()+liczba2.licznik()*liczba1.mianownik(),liczba1.mianownik()*liczba2.mianownik());
}
ulamek operator - (ulamek liczba1, ulamek liczba2)
{
         return ulamek(liczba1.licznik()*liczba2.mianownik()-liczba2.licznik()*liczba1.mianownik(),liczba1.mianownik()*liczba2.mianownik());
}
ulamek operator * (ulamek liczba1, ulamek liczba2)
{
       return ulamek(liczba1.licznik()*liczba2.licznik(), liczba1.mianownik()*liczba2.mianownik());
}
ulamek operator / (ulamek liczba1, ulamek liczba2)
{
       return ulamek(liczba1.licznik()*liczba2.mianownik(), liczba1.mianownik()*liczba2.licznik());
}
int main()
{
    char d;
    ulamek liczba1, liczba2;
    cout << "+ - dodawanie" << endl << "- - odejmowanie" << endl << "* - mnozenie" << endl << "/ - dzielenie" << endl;
    do 
    {
       cin >> d;
    }
    while (!(d == '+' or d == '-' or d == '*' or d == '/'));
    cout << "Pierwszy ulamek:" << endl;
    liczba1.wprowadz_dane();
    cout << endl;
    cout << "Drugi ulamek:" << endl;
    liczba2.wprowadz_dane();
    cout << endl;
    liczba1.wyswietl();
    switch (d)
    {
        case '+' :
             cout << " + ";
             liczba2.wyswietl();
             liczba1 = liczba1 + liczba2;
             break;
        case '-' :
             cout << " - ";
             liczba2.wyswietl();
             liczba1 = liczba1 - liczba2;
             break;
        case '*' :
             cout << " * ";
             liczba2.wyswietl();
             liczba1 = liczba1 * liczba2;
             break;
        case '/' :
             cout << " / ";
             liczba2.wyswietl();
             liczba1 = liczba1 / liczba2;
             break;
    }
    cout << " = ";
    liczba1.skroc();
    liczba1.wyswietl();
    cout << endl;
    cin.ignore();
    getchar();
    return 0;
}
