#include <iostream>
#include <stdio.h>
#include <string> 
using namespace std;
class CException // klasa do obs≥ugi wyjπtkÛw wywo≥anie - throw CException(__FILE__, __LINE__, "Cos sie stalo");  
{ 
  private: 
    // dane wyjπtku 
   std::string m_strNazwaPliku; 
   unsigned m_uLinijka; 
   std::string m_strKomunikat; 
 
  public: 
   // konstruktor 
   CException(const std::string& strNazwaPliku, 
  unsigned uLinijka, 
  const std::string& strKomunikat) 
 : m_strNazwaPliku(strNazwaPliku), 
 m_uLinijka(uLinijka), 
 m_strKomunikat(strKomunikat) { } 
 
 //-------------------------------------------------------------  
 
    // metody dostÍpowe 
   std::string NazwaPliku() const { return m_strNazwaPliku; } 
   unsigned Linijka() const   { return m_uLinijka; } 
   std::string Komunikat() const   { return m_strKomunikat; } 
}; 
/*
- funkcja zrzucajπca dowolne typy wyjπtkÛw
funkcja();
- funkcja zrzucajπca okreslone typy typy wyjπtkÛw
funkjca() throw(void*);
- funkcja nie zrzucajπca wyjπtkÛw
funkjca() throw();
*/
int main()
{
    // try - sprÛbuj, wykonanie kodu
    // throw - rzuÊ, wew. try, informuje o wyjπtku --> throw obiekt;
    // catch - z≥ap
    // komunikaty o obladach powinny byc kierowane do strumiena cerr
    /*
    try
    {
    // ryzykowny kod
    }
    catch (...)
    {
    // kod obs≥ugi wyjπtkÛw
    }
    */
    try
    {
           int zmienna;
           cin >> zmienna;
           if (zmienna > 0) throw CException("wyjatki.cpp",57,"wystapila dodatnia liczba");
           throw "pozdro";
    }
    catch (CException error)
    {
           cout << error.NazwaPliku() << " " << error.Linijka() << " " << error.Komunikat() << endl;
    }
    catch (...) // uniwersalny catch
    {
         cout << "FAIL" << endl; 
    }
    /*
    #include <memory>
    zawiera txw. sprytny wskaünik
    klasa (szablon) std::auto_ptr
    uøycie...
    std::auto_ptr<typ> wskaünik(new typ[(parametry_konstruktora_typu)]);
    */
    cin.ignore();
    getchar();
    return 0;
}
