#include <iostream>
#include <stdio.h>
using namespace std;
class CFoo 
{ 
  private: 
   string m_strBardzoOsobistyNapis; 
 
  public: 
   // konstruktor 
    CFoo()  { m_strBardzoOsobistyNapis = "Kocham C++!"; } 
 
  // deklaracja przyjaźni z funkcją 
  friend void Wypisz(CFoo*);  // jej deklaracja jest takze prototypem, w tym miejscu mozna ja takze
                             // zdefiniować ale i tak bedzie ona globalna
}; 
 
// zaprzyjaźniona funkcja 
void Wypisz(CFoo* pFoo) 
{ 
  cout << pFoo->m_strBardzoOsobistyNapis; 
}
// deklaracja zapowiadająca klasy CCircle 
class CCircle; 
 
class CGeometryManager 
{ 
  public: 
   bool PrzecinajaSie(CCircle&, CCircle&); 
}; 
 
class CCircle 
{ 
  // (pomijamy resztę) 
 
  friend bool CGeometryManager::PrzecinajaSie(CCircle&, CCircle&); // przyjazn metody klasy 
}; 
 
int main()
{
    CFoo* pFoo = new CFoo;
    Wypisz(pFoo);
    cout << endl;  
    getchar();
    return 0;
}
