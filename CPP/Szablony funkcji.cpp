#include <iostream>
#include <stdio.h>
using namespace std;
template<typename TYP> TYP potega(TYP liczba)
{
    return liczba*liczba;
}
template<typename ZWRACANY, typename TYP1, typename TYP2> ZWRACANY max(TYP1 liczba1, TYP2 liczba2)
{
   return (liczba1 > liczba2 ? liczba1 : liczba2);
}
int main()
{
    /*
    Szablon - kolejne typy wprowowadzamy po przecinku
    template <typename TYP>  TYP max(TYP Parametr1, TYP Parametr2) 
    { 
        return (Parametr1 > Parametr2 ? Parametr1 : Parametr2); 
    }
    napisanie szablonu bez u¿ycia argumentów typename przypisuj¹ j¹ jako specjalizacje 
    do szablonu funkcji / klasy o takiej samej nazwie
    
    template <typename TYP> 
    TYP* max<TYP*>(TYP* pWskaznik1, TYP* pWskaznik2) 
    { 
      return (*pWskaznik1 > *pWskaznik2 ? pWskaznik1 : pWskaznik2); 
    } 
    */
    cout << potega(10) << endl;
    cout << potega(2.5) << endl;
    cout << potega<float>(10) << endl;
    cout << max<float>(10, 12.0f) << endl;
    cin.ignore();
    getchar();
    return 0;
}
