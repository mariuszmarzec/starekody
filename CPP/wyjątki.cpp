#include <iostream>
#include <stdio.h>
#include <string> 
using namespace std;
class CException // klasa do obs�ugi wyj�tk�w wywo�anie - throw CException(__FILE__, __LINE__, "Cos sie stalo");  
{ 
  private: 
    // dane wyj�tku 
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
 
    // metody dost�powe 
   std::string NazwaPliku() const { return m_strNazwaPliku; } 
   unsigned Linijka() const   { return m_uLinijka; } 
   std::string Komunikat() const   { return m_strKomunikat; } 
}; 
/*
- funkcja zrzucaj�ca dowolne typy wyj�tk�w
funkcja();
- funkcja zrzucaj�ca okreslone typy typy wyj�tk�w
funkjca() throw(void*);
- funkcja nie zrzucaj�ca wyj�tk�w
funkjca() throw();
*/
int main()
{
    // try - spr�buj, wykonanie kodu
    // throw - rzu�, wew. try, informuje o wyj�tku --> throw obiekt;
    // catch - z�ap
    // komunikaty o obladach powinny byc kierowane do strumiena cerr
    /*
    try
    {
    // ryzykowny kod
    }
    catch (...)
    {
    // kod obs�ugi wyj�tk�w
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
    zawiera txw. sprytny wska�nik
    klasa (szablon) std::auto_ptr
    u�ycie...
    std::auto_ptr<typ> wska�nik(new typ[(parametry_konstruktora_typu)]);
    */
    cin.ignore();
    getchar();
    return 0;
}
