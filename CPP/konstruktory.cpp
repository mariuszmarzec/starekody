#include <iostream>
#include <stdio.h>
using namespace std;
class cfoo
{
      private:
              int wartosc, wartosc2;
      public:
              /*Je�eli potrzebujesz konstruktora jednoparametrowego, kt�ry b�dzie dzia�a� 
              wy��cznie jako zwyk�y (a nie te� jako konwertuj�cy), umie�� w jego deklaracji s�owo 
              kluczowe explicit. */
              // konstruktor konwertuj�cy
              //cfoo(float liczba) : wartosc(2); // nie poprawny przyk�ad, uczy jak 
              // zmienic obiekt podany na obiekt klasy
              // Jeden argument lub wiecej ale drugi i kolejny musza miec domyslne wartosci
              //cfoo(cfoo& klasa) konstruktor kopiujacy
              cfoo(int x) : wartosc2(3) { wartosc = x; }
              void wypisz() {cout << wartosc << endl << wartosc2 << endl;}
              // operator konwersji - operator typ(); dziedziczne, mog� by� virtualne
              // np operator float() {}
};
int main()
{
    // wywo�anie konstruktora w sposob niejawny
    //cfoo foo;
    // jawne
    //cfoo foo(2); // lub cfoo* foo = new cfoo;
    cfoo foo = 2;
    foo.wypisz();
    // kopiowanie obiekt�w
    cfoo foo2 = foo;
    // kopiowanie za pomoc� konstruktora kopiuj�cego
    cfoo foo3(foo2); // lub cfoo foo3 = cfoo(foo2);
    // maj�c definicje konwersji mozemy realizowac konwersje niejawna
    // np. sqrt(foo2);
    foo3.wypisz();
    cin.ignore();
    getchar();
    return 0;
}
