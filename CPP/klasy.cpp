#include <iostream>
#include <conio.h>
using namespace std;
class samochod // uzycie w tej klasie metody czysto wirtualnej czyni z niej klasê abstrakcjyjn¹. Klasy abstrakcyjne s¹ podstawami dla pozosta³ych klas. Panuje zwyczja ¿e ich nazwy zaczynamy od "I"
{
      private: // nie sa dostepne dla klas pochodnych tylko dla tej klasy
              int max_v;
      protected:// tutaj znajduj¹ siê rzeczy które maj¹ takie same prawa jak w private ale sa dziedziczone
               int dlugosc;
               int szerokosc;
      public:
                int rok_pr;
                int przebieg;
                bool jedzie;
                samochod()// konstruktor mo¿e byæ ich wiele, nie s¹ nigdy dziedziczone
                {
                    max_v = 250;
                }
                void ruszaj()   // dla d³u¿szych funkcji nalezy zamiescic tylko prototyp 
                {               // a cia³o umieœciæ poza class¹
                    jedzie = true;
                }
                void stoj()
                {
                    jedzie = false;
                }
                virtual funkcja() = 0; // funkjca virtualna któr¹ nale¿y okreœliæ dopiero w pochodnych gdy¿ teraz nie ma to niejmniejszego sensu jest to tzw. metoda czysto wirtualna
                virtual bool czy_jedzie() // biedny przyk³ad metody virtualnej, metoda taka w klasie pochodnej mo¿e mieæ inn¹ postaæ na tym polega wirtualizacja          
                {
                     return jedzie;
                }
                ~samochod() {/*konczenie(?!)*/} // destruktor nie jest dziedziczony wypada by by³ virtual'ny unikamy tak wycieków pamiêci
};
class TIR : public samochod // - dziedziczenie classy samochod
{
      private:
              int waga;
      public:
              bool czy_jedzie() {cout << "jedzie"; return true} // funkcja przedefiniowana
              void wprowadz_wage() {cin >> waga;}
              int podaj_wage() {return waga;}
};
int main()
{
// klasy
/*
    int k = 0;
    samochod maluch;
    samochod::samochod();
    maluch.rok_pr = 1987;
    maluch.przebieg = 100000;
    cout << "Malucha wyprodukowano w: " << maluch.rok_pr << endl << "Maluch przejachal: " << maluch.przebieg << " km"<< endl;
    while (k <= 1)
    {
          cin >> k;
          if (k == 1) maluch.ruszaj();
          else if (k == 0) maluch.stoj();
          cout << "maluch ";
          if (maluch.jedzie) cout << "jedzie";
          else cout << "stoi";
          cout << endl;
    }
// wskaŸnik na obiekt
/*
    samochod* maluch = new samochod;
    samochod* ferrari = maluch;
    maluch->ruszaj();
    if (maluch->czy_jedzie()) cout << "jedzie" << endl;
    delete maluch; // tylko dla wskaŸników
*/
// klasy dziedziczne
    TIR wywrotka;
    wywrotka.wprowadz_wage();
    cout << wywrotka.podaj_wage();
    wywrotka.czy_jedzie();
    getch();
    return 0;
}
