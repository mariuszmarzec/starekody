#include <iostream>
#include <stdio.h>
using namespace std;
// deklaracja szablonu klasy
template <typename TYP = int> class przyklad // jezeli typ nie zostal podany bedzie to ten domyœlny, typy z wartosciami domyœlnymi s¹ wypisywane zawsze na koñcu listy
{
         // deklaracja przyjazni szablonów dla wszystkich typow
         //template <typename T> friend class klasa<T>
         // dla konkretnego typu
         //fiend class klasa<TYP>
         private:
                 typedef TYP ELEMENT; // tworzenie aliasu dla TYP
                TYP zmienna;
         public:
                explicit przyklad(TYP x) : zmienna(x) {}
                przyklad(const przyklad& obiekt);
                TYP pokaz() const {return zmienna;}
};
template <typename TYP> przyklad<TYP>::przyklad(const przyklad& obiekt) // szablon funkcji, która znajduje siê w klasie
{
         zmienna = obiekt.pokaz();         
}
//template <> class przyklad<char> // -klasa specjalizowana
// dziedziczenie np
//class VECTOR : public przyklad<int>
int main()
{
    przyklad<> obiekt(10);
    cout << obiekt.pokaz() << endl;
    przyklad<int> obiekt2(obiekt);
    cout << obiekt2.pokaz() << endl;
    cin.ignore();
    getchar();
    return 0;
}
