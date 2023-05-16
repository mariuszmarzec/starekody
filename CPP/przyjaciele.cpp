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
 
  // deklaracja przyjaŸni z funkcj¹ 
  friend void Wypisz(CFoo*);  // jej deklaracja jest takze prototypem, w tym miejscu mozna ja takze
                             // zdefiniowaæ ale i tak bedzie ona globalna
}; 
 
// zaprzyjaŸniona funkcja 
void Wypisz(CFoo* pFoo) 
{ 
  cout << pFoo->m_strBardzoOsobistyNapis; 
}
// deklaracja zapowiadaj¹ca klasy CCircle 
class CCircle; 
 
class CGeometryManager 
{ 
  public: 
   bool PrzecinajaSie(CCircle&, CCircle&); 
}; 
 
class CCircle 
{ 
  // (pomijamy resztê) 
 
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
