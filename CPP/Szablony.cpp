#include <iostream>
#include <stdio.h>
using namespace std;
// slowko export str 526
// class == typename
// poza typami mo�na definiowa� sta�e, wska�niki, szablon np.
//template<unsigned N> class klasa
//template<int* P> class klasa - aby tego dokona� zmienna musi by� extern (globalna)
//template<typename T, typename KLASA = obiekt<T> > class klasa* problemowe zast�pujemy to tak -|
// SZABLONY KLAS KONKRETYZOWANE INNYMI PARAMETRAMI STANOWI� INNY TYP                            |
template <typename T, template <typename> class TAB = TArray> class TNumericArray // <<<--------|
{ 
   private: 
     TAB<T> m_aTablica; 
}
int main()
{
    cin.ignore();
    getchar();
    return 0;
}
