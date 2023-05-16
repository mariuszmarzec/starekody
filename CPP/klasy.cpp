#include <iostream>
#include <conio.h>
using namespace std;
class samochod // uzycie w tej klasie metody czysto wirtualnej czyni z niej klas� abstrakcjyjn�. Klasy abstrakcyjne s� podstawami dla pozosta�ych klas. Panuje zwyczja �e ich nazwy zaczynamy od "I"
{
      private: // nie sa dostepne dla klas pochodnych tylko dla tej klasy
              int max_v;
      protected:// tutaj znajduj� si� rzeczy kt�re maj� takie same prawa jak w private ale sa dziedziczone
               int dlugosc;
               int szerokosc;
      public:
                int rok_pr;
                int przebieg;
                bool jedzie;
                samochod()// konstruktor mo�e by� ich wiele, nie s� nigdy dziedziczone
                {
                    max_v = 250;
                }
                void ruszaj()   // dla d�u�szych funkcji nalezy zamiescic tylko prototyp 
                {               // a cia�o umie�ci� poza class�
                    jedzie = true;
                }
                void stoj()
                {
                    jedzie = false;
                }
                virtual funkcja() = 0; // funkjca virtualna kt�r� nale�y okre�li� dopiero w pochodnych gdy� teraz nie ma to niejmniejszego sensu jest to tzw. metoda czysto wirtualna
                virtual bool czy_jedzie() // biedny przyk�ad metody virtualnej, metoda taka w klasie pochodnej mo�e mie� inn� posta� na tym polega wirtualizacja          
                {
                     return jedzie;
                }
                ~samochod() {/*konczenie(?!)*/} // destruktor nie jest dziedziczony wypada by by� virtual'ny unikamy tak wyciek�w pami�ci
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
// wska�nik na obiekt
/*
    samochod* maluch = new samochod;
    samochod* ferrari = maluch;
    maluch->ruszaj();
    if (maluch->czy_jedzie()) cout << "jedzie" << endl;
    delete maluch; // tylko dla wska�nik�w
*/
// klasy dziedziczne
    TIR wywrotka;
    wywrotka.wprowadz_wage();
    cout << wywrotka.podaj_wage();
    wywrotka.czy_jedzie();
    getch();
    return 0;
}
