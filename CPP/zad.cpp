#include <iostream>
#include <stdio.h>
using namespace std;
float funkcja(float x)
{
    return 5*x-3;
}
int main()
{
    char d;
    while (d != 'q')
    {
          cout << "Funkcja y = 5*x-3" << endl;
          cout << "a - oblicz miejsce zerowe" << endl;
          cout << "b - oblicz wartosc funkcji dla dowolnej wartosci" << endl;
          cout << "q - wyjdz z programu" << endl;
          cin >> d;
          switch (d)
          {
              case 'a':
                   cout << "miejsce zerowe: " << funkcja(0) << endl;
                   break;
              case 'b':
                   int liczba;
                   cout << "Wprowadz liczbe dla ktorej obliczysz wartosc funkcji" << endl;
                   cin >> liczba;
                   cout << "f("<< liczba << ") = " << funkcja(liczba) << endl;
                   break;
          }
    }
    return 0;
}
